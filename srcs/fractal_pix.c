/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   fractal_pix.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mtaquet <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/01/09 11:04:44 by mtaquet      #+#   ##    ##    #+#       */
/*   Updated: 2019/01/15 13:09:43 by mtaquet     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fractol.h"

static double	ft_z_r(t_map *map, double z_r, double z_i)
{
	if (map->frac.power == 3)
		return (z_r * z_r * z_r - 3 * z_i * z_i * z_r);
	if (map->frac.power == 4)
	{
		return (z_r * z_r * z_r * z_r - 6 * z_i * z_i * z_r * z_r + z_i *
			z_i * z_i * z_i);
	}
	if (map->frac.power == 5)
	{
		return (z_r * z_r * z_r * z_r * z_r - 10 * z_i * z_i * z_r * z_r * z_r
			+ 5 * z_i * z_i * z_i * z_i * z_r);
	}
	if (map->frac.power == 6)
	{
		return (z_r * z_r * z_r * z_r * z_r * z_r - z_i * z_i * z_i * z_i *
			z_i * z_i - 15 * z_i * z_i * z_r * z_r * z_r * z_r + 15 * z_i *
			z_i * z_i * z_i * z_r * z_r);
	}
	return (0);
}

static double	ft_z_i(t_map *map, double z_r, double z_i)
{
	if (map->frac.power == 3)
		return (3 * z_i * z_r * z_r - z_i * z_i * z_i);
	if (map->frac.power == 4)
		return (4 * (z_i * z_r * z_r * z_r - z_i * z_i * z_i * z_r));
	if (map->frac.power == 5)
	{
		return (z_i * z_i * z_i * z_i * z_i + 5 * z_i * z_r * z_r * z_r *
			z_r - 10 * z_i * z_i * z_i * z_r * z_r);
	}
	if (map->frac.power == 6)
	{
		return (6 * (z_i * z_r * z_r * z_r * z_r * z_r + z_r * z_i * z_i * z_i
			* z_i * z_i) - 20 * z_i * z_i * z_i * z_r * z_r * z_r);
	}
	return (0);
}

void			ft_otherbrot_pix(t_map *map, int x, int y)
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
		z_r = ft_z_r(map, z_r, z_i) + map->frac.c_r;
		z_i = ft_z_i(map, tmp, z_i) + map->frac.c_i;
	}
	if (i == map->frac.i_max)
		map->data[x + y * map->window.x] = 0;
	else
		ft_color_pix(map, x, y, i);
}

void			ft_mandelbrot_pix(t_map *map, int x, int y)
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
		z_i = 2 * tmp * z_i + map->frac.c_i;
	}
	if (i == map->frac.i_max)
		map->data[x + y * map->window.x] = 0;
	else
		ft_color_pix(map, x, y, i);
}
