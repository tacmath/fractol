/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   event.c                                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mtaquet <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/11/29 04:34:44 by mtaquet      #+#   ##    ##    #+#       */
/*   Updated: 2018/12/10 00:42:13 by mtaquet     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fractol.h"

int             ft_destroy(t_map *map)
{
	ft_free_map(map);
	exit(1);
	return (1);
}

int		deal_key(int key, t_map *map)
{
	if (key == KEY_ESCAPE)
		ft_destroy(map);
	return (1);
}

int		deal_mv(int x, int y, t_map *map)
{
	if (map->mouse_status == FALSE)
		return (0);
	if (x > map->window.x)
		x = map->window.x;
	if (y > map->window.y)
		y = map->window.y;
	if (x < 0)
		x = 0;
	if (y < 0)
		y = 0;
	map->mouse.x = x;
	map->mouse.y = y;
	map->frac.c_r = -1 + map->mouse.x / (double)(map->window.x / 2);
	map->frac.c_i = -1 + map->mouse.y / (double)(map->window.y / 2);
	ft_julia(map);
	return (1);
}

int		deal_mouse(int button, int x, int y, t_map *map)
{
	double dx;
	double dy;

	if (x > map->window.x)
		x = map->window.x;
	if (y > map->window.y)
		y = map->window.y;
	if (x < 0)
		x = 0;
	if (y < 0)
		y = 0;
	dx = x * (map->frac.x2 - map->frac.x1) / ((double)map->window.x * map->zoom) + map->frac.x1;
	dy = y * (map->frac.y2 - map->frac.y1) / ((double)map->window.y * map->zoom) + map->frac.y1;						
	if (button == ROULETTE_UP)
	{
		map->zoom += 0.001;
		map->frac.x1 = dx - ((map->frac.x2 - map->frac.x1) / 10) * 4;
		map->frac.x2 = dx + ((map->frac.x2 - map->frac.x1) / 10) * 4;
		map->frac.y1 = dy - ((map->frac.y2 - map->frac.y1) / 10) * 4;
		map->frac.y2 = dy + ((map->frac.y2 - map->frac.y1) / 10) * 4;
		ft_draw(map);
	}
	if (button == ROULETTE_DOWN)
	{
		map->zoom -= 0.001;
		map->frac.x1 -= (map->frac.x2 - map->frac.x1) / 10;
		map->frac.x2 += (map->frac.x2 - map->frac.x1) / 10;
		map->frac.y1 -= (map->frac.y2 - map->frac.y1) / 10;
		map->frac.y2 += (map->frac.y2 - map->frac.y1) / 10;
		ft_draw(map);
	}
	return (1);
}

int             deal_key_press(int key, t_map *map)
{
	if (map->mouse_status == FALSE && key == KEY_S && map->fractal == JULIA)
		map->mouse_status = TRUE;
	else if (key == KEY_S && map->fractal == JULIA)
		map->mouse_status = FALSE;
	if (key == KEY_PLUS)
		map->frac.i_max++;
	if (key == KEY_MINUS && map->frac.i_max > 1)
		map->frac.i_max--;
	if (key == KEY_R)
		ft_map_init(map);
	ft_draw(map);
	return (1);
}
