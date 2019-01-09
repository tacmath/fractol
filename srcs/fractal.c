/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   fractal.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mtaquet <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/11/26 11:53:23 by mtaquet      #+#   ##    ##    #+#       */
/*   Updated: 2019/01/09 11:16:02 by mtaquet     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fractol.h"

static void	*ft_mandelbrot(void *maps)
{
	t_map *map;
	int x;
	int y;

	map = maps;
	y = map->thread * map->thread_length - 1;
	while (++y < (map->thread + 1) * map->thread_length)
	{
		x = -1;
		while (++x < map->window.x)
		{
			map->frac.c_r = x * (map->frac.x2 - map->frac.x1) /
				((double)map->window.x) + map->frac.x1;
			map->frac.c_i = y * (map->frac.y2 - map->frac.y1) /
				((double)map->window.y) + map->frac.y1;
			map->frac.z_r = 0;
			map->frac.z_i = 0;
			if (map->frac.power == 2)
				ft_mandelbrot_pix(map, x, y);
			else
				ft_otherbrot_pix(map, x, y);
		}
	}
	return (0);
}

static void	ft_julia(t_map *map)
{
	int x;
	int y;

	y = -1;
	while (++y < map->window.y)
	{
		x = -1;
		while (++x < map->window.x)
		{
			map->frac.z_r = x * (map->frac.x2 - map->frac.x1) /
				((double)map->window.x) + map->frac.x1;
			map->frac.z_i = y * (map->frac.y2 - map->frac.y1) /
				((double)map->window.y) + map->frac.y1;
			if (map->frac.power == 2 || map->fractal == FLAT)
				ft_mandelbrot_pix(map, x, y);
			else
				ft_otherbrot_pix(map, x, y);
		}
	}
}

void		ft_draw(t_map *map)
{
	if (map->fractal == JULIA)
		ft_julia(map);
	if (map->fractal == FLAT)
		ft_julia(map);
	if (map->fractal == MANDELBROT)
		ft_threading(map, ft_mandelbrot);
	mlx_put_image_to_window(map->mlx_ptr, map->win_ptr, map->img_ptr, 400, 0);
}
