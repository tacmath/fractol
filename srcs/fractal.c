/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   fractal.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mtaquet <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/11/26 11:53:23 by mtaquet      #+#   ##    ##    #+#       */
/*   Updated: 2018/12/10 02:12:45 by mtaquet     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fractol.h"

void	ft_mangelbrot_pix(t_map *map, int x, int y)
{
	double 	tmp;
	double	z_r;
	double	z_i;
	int	i;

	i = -1;
	z_r = 0;
	z_i = 0;
	while ((z_r * z_r + z_i * z_i) < 4 && ++i < map->mdb.i_max)
	{
		tmp = z_r;
		z_r = z_r * z_r - z_i * z_i + map->mdb.c_r;
		z_i = 2 * z_i * tmp + map->mdb.c_i;
	}
	if (i == map->mdb.i_max)
		mlx_pixel_put(map->mlx_ptr, map->win_ptr, x, y, 0);
	else
		mlx_pixel_put(map->mlx_ptr, map->win_ptr, x, y, ft_rgb((255 * i) / map->mdb.i_max, (255 * i) / map->mdb.i_max, 255));
}

void    ft_julia_pix(t_map *map, int x, int y)
{
	double  tmp;
	double  z_r;
	double  z_i;
	int     i;

	i = -1;
	z_r = map->julia.z_r;
	z_i = map->julia.z_i;
	while ((z_r * z_r + z_i * z_i) < 4 && ++i < map->julia.i_max)
	{
		tmp = z_r;
		z_r = z_r * z_r - z_i * z_i + map->julia.c_r;
		z_i = 2 * z_i * tmp + map->julia.c_i;
	}
	if (i == map->julia.i_max)
		mlx_pixel_put(map->mlx_ptr, map->win_ptr, x, y, 0);
	else
		mlx_pixel_put(map->mlx_ptr, map->win_ptr, x, y, ft_rgb((255 * i) / map->julia.i_max, (255 * i) / map->julia.i_max, 255));
}

void	ft_mandelbrot(t_map *map)
{
	int x;
	int y;

	y = -1;
	while (++y < map->window.y)
	{
		x = -1;
		while (++x < map->window.x)
		{
			map->mdb.c_r = x * (map->mdb.x2 - map->mdb.x1) / (double)map->window.x + map->mdb.x1;
			map->mdb.c_i = y * (map->mdb.y2 - map->mdb.y1) / (double)map->window.y + map->mdb.y1;
			map->mdb.z_r = 0;
			map->mdb.z_i = 0;
			ft_mangelbrot_pix(map, x, y);
		}
	}
}

void    ft_julia(t_map *map)
{
	int x;
	int y;

	y = -1;
	while (++y < map->window.y)
	{
		x = -1;
		while (++x < map->window.x)
		{
			map->julia.z_r = x * (map->julia.x2 - map->julia.x1) / (double)map->window.x + map->julia.x1;
			map->julia.z_i = y * (map->julia.y2 - map->julia.y1) / (double)map->window.y + map->julia.y1;
			map->julia.c_r = -0.76;
			map->julia.c_i = 0.12;
			ft_julia_pix(map, x, y);
		}
	}
}
