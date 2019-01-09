/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   util.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mtaquet <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/01/04 13:24:44 by mtaquet      #+#   ##    ##    #+#       */
/*   Updated: 2019/01/07 16:27:57 by mtaquet     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fractol.h"
#include <pthread.h>

void	ft_free_map(t_map *map)
{
	free(map->mlx_ptr);
	free(map->win_ptr);
	free(map->data);
	free(map->img_ptr);
	free(map);
}

void	ft_threading(t_map *map, void *fractal(void *map))
{
	t_map		maps[NB_THREAD];
	pthread_t	threads[NB_THREAD];
	int n;

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
