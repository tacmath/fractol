/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   main.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mtaquet <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/11/26 11:53:23 by mtaquet      #+#   ##    ##    #+#       */
/*   Updated: 2018/12/10 02:12:45 by mtaquet     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fractol.h"

int 	usage_msg(void)
{
	ft_putendl("Usage : ./fractol [fractals]");
	ft_putendl(" fractals :");
	ft_putendl(" --> Mandelbrot");
	ft_putendl(" --> Julia");
	return (0);
}

int	main(int ac, char **av)
{
	t_map	*map;

	if (ac != 2)
		return (usage_msg());
	if (ft_strcmp("Mandelbrot", av[1]) && ft_strcmp("Julia", av[1]))
		return (usage_msg());
	if (!(map = malloc(sizeof(t_map))))
		return (0);
	ft_map_init(map);
	if (!ft_strcmp("Mandelbrot", av[1]))
		map->mdb.status = TRUE;
	if (!ft_strcmp("Julia", av[1]))
		map->julia.status = TRUE;
	map->mlx_ptr = mlx_init();
	map->win_ptr = mlx_new_window(map->mlx_ptr,
			map->window.x, map->window.y, "fractol");
	if (map->mdb.status == TRUE)
		ft_mandelbrot(map);
	if (map->julia.status == TRUE)
		ft_julia(map);
	mlx_hook(map->win_ptr, DESTROY_NOTIFY, 0, ft_destroy, map);
	mlx_hook(map->win_ptr, KEY_PRESS, 0, deal_key_press, map);
	mlx_key_hook(map->win_ptr, deal_key, map);
	mlx_loop(map->mlx_ptr);
	return (1);
}
