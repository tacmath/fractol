/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   event_press.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mtaquet <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/01/04 14:06:22 by mtaquet      #+#   ##    ##    #+#       */
/*   Updated: 2019/01/04 15:02:32 by mtaquet     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fractol.h"

static void	ft_move(int key, t_map *map)
{
	double size;

	size = map->frac.x2 - map->frac.x1;
	if (key == KEY_RIGHT)
	{
		map->frac.x1 += size / 100;
		map->frac.x2 += size / 100;
	}
	if (key == KEY_LEFT)
	{
		map->frac.x1 -= size / 100;
		map->frac.x2 -= size / 100;
	}
	size = map->frac.y2 - map->frac.y1;
	if (key == KEY_UP)
	{
		map->frac.y1 -= size / 100;
		map->frac.y2 -= size / 100;
	}
	if (key == KEY_DOWN)
	{
		map->frac.y1 += size / 100;
		map->frac.y2 += size / 100;
	}
}

static void	ft_iterration_changes(int key, t_map *map)
{
	if (key == KEY_PLUS)
	{
		if (map->frac.i_max > 20)
			map->frac.i_max += map->frac.i_max / 20;
		else 
			map->frac.i_max++;
	}
	if (key == KEY_MINUS && map->frac.i_max > 1)
	{
		if (map->frac.i_max > 20)
			map->frac.i_max -= map->frac.i_max / 20;
		else 
			map->frac.i_max--;
	}
}

int			deal_key_press(int key, t_map *map)
{
	ft_move(key, map);
	ft_iterration_changes(key, map);
	if (key == KEY_MINUS && map->frac.i_max > 1)
	{
		if (map->frac.i_max > 20)
			map->frac.i_max -= map->frac.i_max / 20;
		else 
			map->frac.i_max--;
	}
	if (map->palette == 4 && map->color_status == TRUE)
	{
		if (key == KEY_ONE)
			ft_color_change(&(map->colors[4][0]));
		else if (key == KEY_TWO)
			ft_color_change(&(map->colors[4][1]));
		else if (key == KEY_THREE)
			ft_color_change(&(map->colors[4][2]));
		else if (key == KEY_FOUR)
			ft_color_change(&(map->colors[4][3]));
	}
	if (key == KEY_PLUS || key == KEY_MINUS || (key >= KEY_LEFT && key <=
		KEY_UP) || (map->palette == 4 && map->color_status == TRUE && (key
		== KEY_ONE || key == KEY_TWO || key == KEY_THREE || key == KEY_FOUR)))
		ft_draw(map);
	return (1);
}
