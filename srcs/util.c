/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   util.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mtaquet <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/01/04 13:24:44 by mtaquet      #+#   ##    ##    #+#       */
/*   Updated: 2019/01/10 14:46:41 by mtaquet     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fractol.h"
#include <pthread.h>

void	ft_free_map(t_map *map)
{
	mlx_destroy_image(map->mlx_ptr, map->img_ptr);
	mlx_destroy_window(map->mlx_ptr, map->win_ptr);
	free(map->mlx_ptr);
	free(map);
}

void	ft_threading(t_map *map, void *fractal(void *map))
{
	t_map		maps[NB_THREAD];
	pthread_t	threads[NB_THREAD];
	int			n;

	n = -1;
	while (++n < NB_THREAD)
	{
		map->thread = n;
		maps[n] = *map;
		pthread_create(&threads[n], 0, fractal, &maps[n]);
	}
	while (--n)
		pthread_join(threads[n], 0);
}
