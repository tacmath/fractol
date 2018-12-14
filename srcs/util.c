# include "fractol.h"

void	ft_julia_init(t_map *map)
{
	map->frac.x1 = -1.6;
	map->frac.x2 = 1.6;
	map->frac.y1 = -1.2;
	map->frac.y2 = 1.2;
	map->frac.c_r = -0.76;
	map->frac.c_i = 0.12;
	map->frac.i_max = 50;
}

void	ft_mandelbrot_init(t_map *map)
{
	map->frac.x1 = -2.1;
	map->frac.x2 = 0.6;
	map->frac.y1 = -1.2;
	map->frac.y2 = 1.2;
	map->frac.i_max = 15;
}

void	ft_map_init(t_map *map)
{
	map->window.x = 1000;
	map->window.y = 700;
	if (map->fractal == JULIA)
		ft_julia_init(map);
	if (map->fractal == MANDELBROT)
		ft_mandelbrot_init(map);
	map->mouse_status = FALSE;
	map->zoom = 1;
}

void	ft_free_map(t_map *map)
{
	free(map->mlx_ptr);
	free(map->win_ptr);
	free(map);
}

int	ft_rgb(unsigned char r, unsigned char g, unsigned char b)
{
	return ((r << 16) | (g << 8) | b);	
}
