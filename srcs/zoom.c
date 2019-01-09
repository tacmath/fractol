/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   zoom.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mtaquet <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/01/04 14:04:42 by mtaquet      #+#   ##    ##    #+#       */
/*   Updated: 2019/01/09 11:30:00 by mtaquet     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fractol.h"

static void	ft_zoom(int x, int y, t_map *map)
{
	double dx;
	double dy;
	double size_x;
	double size_y;

	size_x = (map->frac.x2 - map->frac.x1);
	size_y = (map->frac.y2 - map->frac.y1);
	dx = x * size_x / ((double)map->window.x);
	dy = y * size_y / ((double)map->window.y);
	if (map->inf_status == TRUE)
	{
		map->frac.i_max += map->frac.i_max / 10;
		ft_iterrations(map);
	}
	map->frac.x1 += (dx) / 10;
	map->frac.x2 -= (size_x - dx) / 10;
	map->frac.y1 += (dy) / 10;
	map->frac.y2 -= (size_y - dy) / 10;
	ft_draw(map);
}

static void	ft_dezoom(t_map *map)
{
	double size_x;
	double size_y;

	size_x = (map->frac.x2 - map->frac.x1);
	size_y = (map->frac.y2 - map->frac.y1);
	if (map->inf_status == TRUE)
	{
		map->frac.i_max -= map->frac.i_max / 20;
		ft_iterrations(map);
	}
	map->frac.x1 -= size_x / 20;
	map->frac.x2 += size_x / 20;
	map->frac.y1 -= size_y / 20;
	map->frac.y2 += size_y / 20;
	ft_draw(map);
}

static void	ft_center(int x, int y, t_map *map)
{
	double dx;
	double dy;
	double size_x;
	double size_y;

	size_x = (map->frac.x2 - map->frac.x1);
	size_y = (map->frac.y2 - map->frac.y1);
	dx = x * size_x / ((double)map->window.x) + map->frac.x1;
	dy = y * size_y / ((double)map->window.y) + map->frac.y1;
	map->frac.x1 = dx - (size_x / 2);
	map->frac.x2 = dx + (size_x / 2);
	map->frac.y1 = dy - (size_y / 2);
	map->frac.y2 = dy + (size_y / 2);
	ft_draw(map);
}

int			deal_mouse(int button, int x, int y, t_map *map)
{
	x -= 400;
	if (x > map->window.x)
		x = map->window.x;
	if (y > map->window.y)
		y = map->window.y;
	if (x < 0)
		x = 0;
	if (y < 0)
		y = 0;
	if (button == RIGHT_CLICK && y > 0)
		ft_center(x, y, map);
	if (button == ROULETTE_UP)
		ft_zoom(x, y, map);
	if (button == ROULETTE_DOWN)
		ft_dezoom(map);
	return (1);
}
