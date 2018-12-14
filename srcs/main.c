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
	ft_putendl(" --> Flat");
	return (0);
}

int	main(int ac, char **av)
{
	t_map	*map;

	if (ac != 2)
		return (usage_msg());
	if (ft_strcmp("Mandelbrot", av[1]) && ft_strcmp("Julia", av[1]) && ft_strcmp("Flat", av[1]))
		return (usage_msg());
	if (!(map = malloc(sizeof(t_map))))
		return (0);
	if (!ft_strcmp("Mandelbrot", av[1]))
		map->fractal = MANDELBROT;
	else if (!ft_strcmp("Julia", av[1]))
		map->fractal = JULIA;
	else if (!ft_strcmp("Flat", av[1]))
		map->fractal = FLAT;
	ft_map_init(map);
	map->mlx_ptr = mlx_init();
	map->win_ptr = mlx_new_window(map->mlx_ptr,
			map->window.x, map->window.y, "fractol");
	ft_draw(map);
	mlx_hook(map->win_ptr, DESTROY_NOTIFY, 0, ft_destroy, map);
	mlx_hook(map->win_ptr, MOTION_NOTIFY, 0, deal_mv, map);
	mlx_hook(map->win_ptr, KEY_PRESS, 0, deal_key_press, map);
	mlx_key_hook(map->win_ptr, deal_key, map);
	mlx_mouse_hook(map->win_ptr, deal_mouse, map);
	mlx_loop(map->mlx_ptr);
	return (1);
}
