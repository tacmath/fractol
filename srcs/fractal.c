/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   fractal.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mtaquet <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/11/26 11:53:23 by mtaquet      #+#   ##    ##    #+#       */
/*   Updated: 2019/01/11 14:01:31 by mtaquet     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fractol.h"
#include <pthread.h>

static void	*ft_mandelbrot(void *maps)
{
	t_map	*map;
	int		x;
	int		y;

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
	pthread_exit(0);
}

static void	*ft_julia(void *maps)
{
	t_map	*map;
	int		x;
	int		y;

	map = maps;
	y = map->thread * map->thread_length - 1;
	while (++y < (map->thread + 1) * map->thread_length)
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
	pthread_exit(0);
}

static void	*ft_burning_ship(void *maps)
{
	t_map	*map;
	int		x;
	int		y;

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
			ft_mandelbship_pix(map, x, y);
		}
	}
	pthread_exit(0);
}

void		ft_draw(t_map *map)
{
	if (map->fractal == JULIA || map->fractal == FLAT)
		ft_threading(map, ft_julia);
	if (map->fractal == MANDELBROT)
		ft_threading(map, ft_mandelbrot);
	if (map->fractal == BURNING_SHIP)
		ft_threading(map, ft_burning_ship);
	mlx_put_image_to_window(map->mlx_ptr, map->win_ptr, map->img_ptr, 400, 0);
}
