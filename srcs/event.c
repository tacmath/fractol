/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   event.c                                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mtaquet <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/11/29 04:34:44 by mtaquet      #+#   ##    ##    #+#       */
/*   Updated: 2019/01/10 13:11:12 by mtaquet     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fractol.h"

int			ft_destroy(t_map *map)
{
	ft_free_map(map);
	exit(1);
	return (1);
}

static void	ft_deal_other_key(int key, t_map *map)
{
	if (map->mouse_status == FALSE && key == KEY_S && map->fractal == JULIA)
		map->mouse_status = TRUE;
	else if (key == KEY_S && map->fractal == JULIA)
		map->mouse_status = FALSE;
	if (key == KEY_P)
	{
		map->palette++;
		if (map->palette > 4)
			map->palette = 0;
		ft_color_controls(map);
	}
	if (key == KEY_T && map->fractal != FLAT)
	{
		map->frac.power++;
		if (map->frac.power == 7)
			map->frac.power = 2;
		ft_head(map);
	}
	if (key == KEY_R)
	{
		ft_fractal_init(map);
		ft_iterrations(map);
	}
}

int			deal_key(int key, t_map *map)
{
	if (key == KEY_ESCAPE)
		ft_destroy(map);
	if (key == KEY_I && map->inf_status == FALSE)
		map->inf_status = TRUE;
	else if (key == KEY_I)
		map->inf_status = FALSE;
	if (key == KEY_I)
		ft_infini(map);
	if (key == KEY_C)
	{
		if (map->color_status == FALSE)
			map->color_status = TRUE;
		else
			map->color_status = FALSE;
		ft_color_controls(map);
	}
	ft_deal_other_key(key, map);
	if (key == KEY_C || key == KEY_P || key == KEY_R || key == KEY_T)
		ft_draw(map);
	return (1);
}

int			deal_mv(int x, int y, t_map *map)
{
	if (map->mouse_status == FALSE || map->fractal != JULIA)
		return (0);
	x -= 400;
	if (x > map->window.x)
		x = map->window.x;
	if (y > map->window.y)
		y = map->window.y;
	if (x < 0)
		x = 0;
	if (y < 0)
		y = 0;
	map->frac.c_r = -1 + x / (double)(map->window.x / 2);
	map->frac.c_i = -1 + y / (double)(map->window.y / 2);
	ft_draw(map);
	return (1);
}
