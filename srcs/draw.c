/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   draw.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mtaquet <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/01/04 12:57:06 by mtaquet      #+#   ##    ##    #+#       */
/*   Updated: 2019/01/10 15:10:14 by mtaquet     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fractol.h"

static void	ft_palette_put(t_map *map)
{
	char c[2];

	mlx_string_put(map->mlx_ptr, map->win_ptr, 30, 240,
		map->colors[map->palette][2], "< P >  palette :");
	c[0] = map->palette + 1 + '0';
	c[1] = 0;
	mlx_string_put(map->mlx_ptr, map->win_ptr, 205, 240,
		map->colors[map->palette][2], c);
	if (map->palette == 4)
	{
		mlx_string_put(map->mlx_ptr, map->win_ptr, 50, 270,
			map->colors[4][0], "< 1 > change first  color");
		mlx_string_put(map->mlx_ptr, map->win_ptr, 50, 300,
			map->colors[4][1], "< 2 > change second color");
		mlx_string_put(map->mlx_ptr, map->win_ptr, 50, 330,
			map->colors[4][2], "< 3 > change third  color");
		mlx_string_put(map->mlx_ptr, map->win_ptr, 50, 360,
			map->colors[4][3], "< 4 > change last   color");
	}
}

void		ft_color_controls(t_map *map)
{
	int n;
	int m;

	m = 209;
	while (++m < 385)
	{
		n = 4;
		while (++n < 300)
			mlx_pixel_put(map->mlx_ptr, map->win_ptr, n, m, 0);
	}
	if (map->color_status == TRUE)
	{
		mlx_string_put(map->mlx_ptr, map->win_ptr, 5, 210,
			map->colors[map->palette][1], "< C >  colors  :    on");
		ft_palette_put(map);
	}
	else
		mlx_string_put(map->mlx_ptr, map->win_ptr, 5, 210,
			0xFFFFFF, "< C >  colors  :   off");
}

static void	ft_controls_msg(t_map *map)
{
	mlx_string_put(map->mlx_ptr, map->win_ptr, 30, 500,
		0xFFFFFF, "utilisez les fleches directionelles");
	mlx_string_put(map->mlx_ptr, map->win_ptr, 30, 530,
		0xFFFFFF, "pour vous deplacer dans la fractale");
	mlx_string_put(map->mlx_ptr, map->win_ptr, 40, 600,
		0xFFFFFF, "utilisez la molette de la souris");
	mlx_string_put(map->mlx_ptr, map->win_ptr, 11, 630,
		0xFFFFFF, "pour zoomer sur un point de la fractale");
	mlx_string_put(map->mlx_ptr, map->win_ptr, 25, 700,
		0xFFFFFF, "faites un clique gauche sur un pixel");
	mlx_string_put(map->mlx_ptr, map->win_ptr, 110, 730,
		0xFFFFFF, "pour le centrer");
	if (map->fractal == JULIA)
	{
		mlx_string_put(map->mlx_ptr, map->win_ptr, 25, 800,
			0xFFFFFF, "appuyer sur s puis bouger la souris");
		mlx_string_put(map->mlx_ptr, map->win_ptr, 30, 830,
			0xFFFFFF, "pour changer l'ensemble de julia");
	}
}

void		ft_controls(t_map *map)
{
	char *tmp;

	tmp = 0;
	ft_color_controls(map);
	ft_infini(map);
	if (map->fractal != FLAT && map->fractal != BURNING_SHIP)
		ft_head(map);
	mlx_string_put(map->mlx_ptr, map->win_ptr, 5, 180,
			0xFFFFFF, "< I >  infini  :");
	mlx_string_put(map->mlx_ptr, map->win_ptr, 5, 10,
		0xFFFFFF, "< ESCAPE >  Quit");
	mlx_string_put(map->mlx_ptr, map->win_ptr, 30, 40, 0xFFFFFF, "< R > reset");
	mlx_string_put(map->mlx_ptr, map->win_ptr, 30, 70,
		0xFFFFFF, "< + > more iterations");
	mlx_string_put(map->mlx_ptr, map->win_ptr, 30, 100,
		0xFFFFFF, "< - > less iterations");
	mlx_string_put(map->mlx_ptr, map->win_ptr, 140, 130,
		0xFFFFFF, "iterations :");
	ft_iterrations(map);
	ft_controls_msg(map);
}
