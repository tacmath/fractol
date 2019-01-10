/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   main.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mtaquet <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/11/26 11:53:23 by mtaquet      #+#   ##    ##    #+#       */
/*   Updated: 2019/01/10 15:02:23 by mtaquet     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fractol.h"

static int	usage_msg(void)
{
	ft_putendl("Usage : ./fractol [fractal]");
	ft_putendl(" fractals :");
	ft_putendl(" --> Mandelbrot");
	ft_putendl(" --> Julia");
	ft_putendl(" --> Flat");
	ft_putendl(" --> BurningShip");
	return (0);
}

static void	ft_get_fractal(t_map *map, char **av)
{
	if (!ft_strcmp("Mandelbrot", av[1]))
		map->fractal = MANDELBROT;
	else if (!ft_strcmp("Julia", av[1]))
		map->fractal = JULIA;
	else if (!ft_strcmp("Flat", av[1]))
		map->fractal = FLAT;
	else if (!ft_strcmp("BurningShip", av[1]))
		map->fractal = BURNING_SHIP;
}

static int	ft_mlx_init(t_map *map)
{
	ft_map_init(map);
	if (!(map->mlx_ptr = mlx_init()))
	{
		free(map);
		return (0);
	}
	if (!(map->win_ptr = mlx_new_window(map->mlx_ptr,
			map->window.x + 400, map->window.y, "fractol")))
	{
		free(map->mlx_ptr);
		free(map);
		return (0);
	}
	if (!ft_image_init(map))
		return (0);
	return (1);
}

int			main(int ac, char **av)
{
	t_map	*map;

	if (ac != 2)
		return (usage_msg());
	if (ft_strcmp("Mandelbrot", av[1]) && ft_strcmp("Julia", av[1])
			&& ft_strcmp("Flat", av[1]) && ft_strcmp("BurningShip", av[1]))
		return (usage_msg());
	if (!(map = malloc(sizeof(t_map))))
		return (0);
	ft_get_fractal(map, av);
	if (!ft_mlx_init(map))
		return (0);
	ft_draw(map);
	ft_controls(map);
	mlx_hook(map->win_ptr, DESTROY_NOTIFY, 0, ft_destroy, map);
	mlx_hook(map->win_ptr, MOTION_NOTIFY, 0, deal_mv, map);
	mlx_hook(map->win_ptr, KEY_PRESS, 0, deal_key_press, map);
	mlx_key_hook(map->win_ptr, deal_key, map);
	mlx_mouse_hook(map->win_ptr, deal_mouse, map);
	mlx_loop(map->mlx_ptr);
	return (1);
}
