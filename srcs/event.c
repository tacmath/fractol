/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   event.c                                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mtaquet <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/11/29 04:34:44 by mtaquet      #+#   ##    ##    #+#       */
/*   Updated: 2018/12/10 00:42:13 by mtaquet     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fractol.h"


int             ft_destroy(t_map *map)
{
	ft_free_map(map);
	exit(1);
	return (1);
}

int		deal_key(int key, t_map *map)
{
	if (key == KEY_ESCAPE)
		ft_destroy(map);
	return (1);
}

int             deal_key_press(int key, t_map *map)
{
	if (map->julia.status == TRUE)
	{
		if (key == KEY_PLUS)
			map->julia.i_max++;
		if (key == KEY_MINUS && map->julia.i_max > 1)
			map->julia.i_max--;
		ft_julia(map);
	}
	if (map->mdb.status == TRUE)
	{
		if (key == KEY_PLUS)
			map->mdb.i_max++;
		if (key == KEY_MINUS && map->mdb.i_max > 1)
			map->mdb.i_max--;
		ft_mandelbrot(map);
	}
	return (1);
}
