/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   color.c                                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mtaquet <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/01/04 13:17:18 by mtaquet      #+#   ##    ##    #+#       */
/*   Updated: 2019/01/15 13:04:53 by mtaquet     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fractol.h"

void		ft_color_init(t_map *map)
{
	map->colors[0][0] = 0xFFFF99;
	map->colors[0][1] = 0xFFFF00;
	map->colors[0][2] = 0xFF9900;
	map->colors[0][3] = 0xFFFFC9;
	map->colors[1][0] = 0xFF0000;
	map->colors[1][1] = 0xFFFF00;
	map->colors[1][2] = 0x0000FF;
	map->colors[1][3] = 0xFFFFFF;
	map->colors[2][0] = 0x000040;
	map->colors[2][1] = 0x2020FF;
	map->colors[2][2] = 0x1010FF;
	map->colors[2][3] = 0xFFFFFF;
	map->colors[3][0] = 0x000070;
	map->colors[3][1] = 0xFF0000;
	map->colors[3][2] = 0xFFFF00;
	map->colors[3][3] = 0xFF0000;
	map->colors[4][0] = 0x00FFFF;
	map->colors[4][1] = 0xFFFF00;
	map->colors[4][2] = 0xFF0000;
	map->colors[4][3] = 0x0000FF;
}

static int	ft_get_color(t_map *map, intmax_t i, int div, int color)
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

void		ft_color_pix(t_map *map, int x, int y, intmax_t i)
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
		map->data[x + y * map->window.x] = color;
	else
		map->data[x + y * map->window.x] = 0xFFFFFF;
}

void		ft_color_change(int *color)
{
	unsigned char r;
	unsigned char g;
	unsigned char b;

	r = ft_hextor(*color);
	g = ft_hextog(*color);
	b = ft_hextob(*color);
	if (b < 255 && g == 0)
		b += 15;
	else if (g < 255 && r == 0)
		g += 15;
	else if (g == 255 && b > 0)
		b -= 15;
	else if (r < 255 && b == 0)
		r += 15;
	else if (r == 255 && g > 0)
		g -= 15;
	else if (r > 0)
		r -= 15;
	(*color) = ft_rgb(r, g, b);
}
