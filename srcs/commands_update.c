/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   commands_uptade.c                                .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mtaquet <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/01/04 12:57:06 by mtaquet      #+#   ##    ##    #+#       */
/*   Updated: 2019/01/10 12:59:11 by mtaquet     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fractol.h"

void	ft_head(t_map *map)
{
	char	c[2];
	int		n;
	int		m;

	m = 154;
	while (++m < 175)
	{
		n = 4;
		while (++n < 230)
			mlx_pixel_put(map->mlx_ptr, map->win_ptr, n, m, 0);
	}
	mlx_string_put(map->mlx_ptr, map->win_ptr, 5, 155,
		0xFFFFFF, "< T >  power :");
	c[0] = map->frac.power + '0';
	c[1] = 0;
	mlx_string_put(map->mlx_ptr, map->win_ptr, 205, 155, 0xFFFFFF, c);
}

void	ft_iterrations(t_map *map)
{
	char	*tmp;
	int		n;
	int		m;

	m = 129;
	while (++m < 155)
	{
		n = 269;
		while (++n < 400)
			mlx_pixel_put(map->mlx_ptr, map->win_ptr, n, m, 0);
	}
	tmp = ft_itoa(map->frac.i_max);
	mlx_string_put(map->mlx_ptr, map->win_ptr, 270, 130, 0xFFFFFF, tmp);
	free(tmp);
}

void	ft_infini(t_map *map)
{
	int n;
	int m;

	m = 179;
	while (++m < 200)
	{
		n = 205;
		while (++n < 240)
			mlx_pixel_put(map->mlx_ptr, map->win_ptr, n, m, 0);
	}
	if (map->inf_status == TRUE)
	{
		mlx_string_put(map->mlx_ptr, map->win_ptr, 205, 180,
			0xFFFFFF, "on");
	}
	else
	{
		mlx_string_put(map->mlx_ptr, map->win_ptr, 205, 180,
			0xFFFFFF, "off");
	}
}
