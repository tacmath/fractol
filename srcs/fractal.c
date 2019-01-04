/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   fractal.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mtaquet <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/11/26 11:53:23 by mtaquet      #+#   ##    ##    #+#       */
/*   Updated: 2019/01/04 13:27:17 by mtaquet     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fractol.h"

static void	ft_mandelbrot_pix(t_map *map, int x, int y)
{
	double		tmp;
	double		z_r;
	double		z_i;
	intmax_t	i;

	i = -1;
	z_r = map->frac.z_r;
	z_i = map->frac.z_i;
	while ((z_r * z_r + z_i * z_i) < 4 && ++i < map->frac.i_max)
	{
		tmp = z_r;
		z_r = z_r * z_r - z_i * z_i + map->frac.c_r;
		z_i = 2 * z_i * tmp + map->frac.c_i;
	}
	if (i == map->frac.i_max)
		mlx_pixel_put(map->mlx_ptr, map->win_ptr, x + 400, y, 0);
	else
		ft_color_pix(map, x + 400, y, i);
}

static void	ft_mandelbrot(t_map *map)
{
	int x;
	int y;

	y = -1;
	while (++y < map->window.y)
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
			ft_mandelbrot_pix(map, x, y);
		}
	}
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
			ft_mandelbrot_pix(map, x, y);
		}
	}
}

void		ft_draw(t_map *map)
{
	ft_controls(map);
	if (map->fractal == JULIA)
		ft_julia(map);
	if (map->fractal == FLAT)
		ft_julia(map);
	if (map->fractal == MANDELBROT)
		ft_mandelbrot(map);
}
