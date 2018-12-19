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

static int		ft_get_color(t_map *map, int i, int div, int color)
{
	unsigned char r;
	unsigned char g;
	unsigned char b;
	
	r = ft_hextor(map->colors[map->palette][color - 1]) + ((
		ft_hextor(map->colors[map->palette][color]) -
		ft_hextor(map->colors[map->palette][color - 1])) * i) / div;
	g = ft_hextog(map->colors[map->palette][color - 1]) + ((
		ft_hextog(map->colors[map->palette][color]) -
		ft_hextog(map->colors[map->palette][color - 1])) * i) / div;
	b = ft_hextob(map->colors[map->palette][color - 1]) + ((
		ft_hextob(map->colors[map->palette][color]) -
		ft_hextob(map->colors[map->palette][color - 1])) * i) / div;
	return (ft_rgb(r, g, b));
}

static void ft_color_pix(t_map *map, int x, int y, int i)
{
	int color;

	if (i < 0)
		i = 0;
	if (i < 10)
		color = ft_get_color(map, i, 10, 1);
	else if (i < 50)
		color = ft_get_color(map, i - 10, 40, 2);
	else
		color = ft_get_color(map, i - 50, map->frac.i_max - 50, 3);
	if (map->color_status == TRUE)
		mlx_pixel_put(map->mlx_ptr, map->win_ptr, x, y, color);
	else
		mlx_pixel_put(map->mlx_ptr, map->win_ptr, x, y, 0xFFFFFF);
/*	if (i % 4 == 0)
		color = map->colors[map->palette][3];
	else if (i % 3 == 0)
		color = map->colors[map->palette][2];
	else if (i % 2 == 0)
		color = map->colors[map->palette][1];
	else
		color = map->colors[map->palette][0];
	mlx_pixel_put(map->mlx_ptr, map->win_ptr, x, y, color);*/
}

void	ft_mandelbrot_pix(t_map *map, int x, int y)
{
	double 	tmp;
	double	z_r;
	double	z_i;
	int	i;

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
		mlx_pixel_put(map->mlx_ptr, map->win_ptr, x, y, 0);
	else
		ft_color_pix(map, x, y, i);
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
			map->frac.c_r = x * (map->frac.x2 - map->frac.x1) / ((double)map->window.x) + map->frac.x1;
			map->frac.c_i = y * (map->frac.y2 - map->frac.y1) / ((double)map->window.y) + map->frac.y1;
			map->frac.z_r = 0;
			map->frac.z_i = 0;
			ft_mandelbrot_pix(map, x, y);
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
			map->frac.z_r = x * (map->frac.x2 - map->frac.x1) / ((double)map->window.x) + map->frac.x1;
			map->frac.z_i = y * (map->frac.y2 - map->frac.y1) / ((double)map->window.y) + map->frac.y1;
			ft_mandelbrot_pix(map, x, y);
		}
	}
}

void	ft_draw(t_map *map)
{
	if (map->fractal == JULIA)
		ft_julia(map);
	if (map->fractal == FLAT)
		ft_julia(map);
	if (map->fractal == MANDELBROT)
		ft_mandelbrot(map);
}
