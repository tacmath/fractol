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
	map->julia.c_r = -1 + map->mouse.x / (double)(map->window.x / 2);
	map->julia.c_i = -1 + map->mouse.y / (double)(map->window.y / 2);
	ft_julia(map);
	return (1);
}

int		deal_mouse(int button, int x, int y, t_map *map)
{
	if (x > map->window.x)
		x = map->window.x;
	if (y > map->window.y)
		y = map->window.y;
	if (x < 0)
		x = 0;
	if (y < 0)
		y = 0;
	if (map->julia.status == TRUE)
	{
		if (button == ROULETTE_UP)
		{
			map->zoom += 0.001;
			map->julia.x1 -= map->julia.x1 / 10;
			map->julia.x2 -= map->julia.x2 / 10;
			map->julia.y1 -= map->julia.y1 / 10;
			map->julia.y2 -= map->julia.y2 / 10;
			ft_julia(map);
		}
		if (button == ROULETTE_DOWN)
		{
			map->zoom -= 0.001;
			map->julia.x1 += map->julia.x1 / 10;
			map->julia.x2 += map->julia.x2 / 10;
			map->julia.y1 += map->julia.y1 / 10;
			map->julia.y2 += map->julia.y2 / 10;
			ft_julia(map);
		}
	}
	return (1);
}

int             deal_key_press(int key, t_map *map)
{
	if (map->julia.status == TRUE)
	{
		if (map->mouse_status == FALSE && key == KEY_S)
			map->mouse_status = TRUE;
		else if (key == KEY_S)
			map->mouse_status = FALSE;
		if (key == KEY_PLUS)
			map->julia.i_max++;
		if (key == KEY_MINUS && map->julia.i_max > 1)
			map->julia.i_max--;
		ft_julia(map);
	}
	if (map->mdb.status == TRUE)
	{
		if (key == KEY_PLUS)
			map->mdb.i_max++;
		if (key == KEY_MINUS && map->mdb.i_max > 1)
			map->mdb.i_max--;
		ft_mandelbrot(map);
	}
	return (1);
}
