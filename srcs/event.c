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
	map->frac.c_r = -1 + x / (double)(map->window.x / 2);
	map->frac.c_i = -1 + y / (double)(map->window.y / 2);
	ft_julia(map);
	return (1);
}

int		deal_mouse(int button, int x, int y, t_map *map)
{
	double dx;
	double dy;
	double size_x;
	double size_y;

	if (x > map->window.x)
		x = map->window.x;
	if (y > map->window.y)
		y = map->window.y;
	if (x < 0)
		x = 0;
	if (y < 0)
		y = 0;
	size_x = (map->frac.x2 - map->frac.x1);
	size_y = (map->frac.y2 - map->frac.y1);
	dx = x * size_x / ((double)map->window.x);
	dy = y * size_y / ((double)map->window.y);						
	if (button == ROULETTE_UP)
	{
		map->frac.i_max += map->frac.i_max / 20;
		map->frac.x1 += (dx) / 10;
		map->frac.x2 -= (size_x - dx) / 10;
		map->frac.y1 += (dy) / 10;
		map->frac.y2 -= (size_y - dy) / 10;
		ft_draw(map);
	}
	if (button == ROULETTE_DOWN)
	{
		map->frac.i_max -= map->frac.i_max / 20;
		map->frac.x1 -= size_x / 20;
		map->frac.x2 += size_x / 20;
		map->frac.y1 -= size_y / 20;
		map->frac.y2 += size_y / 20;
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
