/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   fractal_pix.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mtaquet <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/01/09 11:04:44 by mtaquet      #+#   ##    ##    #+#       */
/*   Updated: 2019/01/15 13:15:42 by mtaquet     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fractol.h"

void			ft_mandelbship_pix(t_map *map, int x, int y)
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
		z_i = 2 * ft_dabs(tmp * z_i) + map->frac.c_i;
	}
	if (i == map->frac.i_max)
		map->data[x + y * map->window.x] = 0;
	else
		ft_color_pix(map, x, y, i);
}
