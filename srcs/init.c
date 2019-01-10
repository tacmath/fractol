/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   init.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mtaquet <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/01/09 10:49:17 by mtaquet      #+#   ##    ##    #+#       */
/*   Updated: 2019/01/10 14:59:22 by mtaquet     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fractol.h"

static void	ft_julia_init(t_map *map)
{
	map->frac.x1 = -1.6;
	map->frac.x2 = 1.6;
	map->frac.y1 = -1.2;
	map->frac.y2 = 1.2;
	if (map->fractal == JULIA)
		map->frac.c_r = -0.76;
	else
		map->frac.c_r = -1.5;
	if (map->fractal == JULIA)
		map->frac.c_i = 0.12;
	else
		map->frac.c_i = 0;
	map->frac.i_max = 150;
}

static void	ft_mandelbrot_init(t_map *map)
{
	map->frac.x1 = -2.1;
	map->frac.x2 = 0.7;
	map->frac.y1 = -1.2;
	map->frac.y2 = 1.2;
	map->frac.i_max = 100;
}

int			ft_image_init(t_map *map)
{
	int bits_per_pix;
	int size_line;
	int endian;

	if (!(map->img_ptr = mlx_new_image(map->mlx_ptr,
		map->window.x, map->window.y)))
	{
		mlx_destroy_window(map->mlx_ptr, map->win_ptr);
		free(map->mlx_ptr);
		free(map);
		return (0);
	}
	map->data = mlx_get_data_addr(map->img_ptr,
		&bits_per_pix, &size_line, &endian);
	map->img_size_line = size_line;
	map->img_bits_per_pix = bits_per_pix;
	return (1);
}

void		ft_fractal_init(t_map *map)
{
	if (map->fractal == MANDELBROT || map->fractal == BURNING_SHIP)
		ft_mandelbrot_init(map);
	else
		ft_julia_init(map);
}

void		ft_map_init(t_map *map)
{
	map->window.x = WIDTH;
	map->window.y = LENGTH;
	map->thread_length = LENGTH / NB_THREAD;
	ft_color_init(map);
	ft_fractal_init(map);
	map->frac.power = 2;
	map->mouse_status = FALSE;
	map->inf_status = FALSE;
	map->color_status = TRUE;
	map->palette = 0;
}
