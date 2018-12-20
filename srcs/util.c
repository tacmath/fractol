# include "fractol.h"

void	ft_julia_init(t_map *map)
{
	map->frac.x1 = -1.6;
	map->frac.x2 = 1.6;
	map->frac.y1 = -1.2;
	map->frac.y2 = 1.2;
	if (map->fractal == JULIA)
		map->frac.c_r = -0.76;
	else
		map->frac.c_r = -1.5;
	if (map->fractal == JULIA)
		map->frac.c_i = 0.12;
	else
		map->frac.c_i = 0;
	map->frac.i_max = 300;
}

void	ft_mandelbrot_init(t_map *map)
{
	map->frac.x1 = -2.1;
	map->frac.x2 = 0.7;
	map->frac.y1 = -1.2;
	map->frac.y2 = 1.2;
	map->frac.i_max = 300;
}

void	ft_color_init(t_map *map)
{
	map->colors[0][0] = 0xFFFF99;
	map->colors[0][1] = 0xFFFF00;
	map->colors[0][2] = 0xFF9900;
	map->colors[0][3] = 0xFFFFC9;
	map->colors[1][0] = 0xFF0000;
	map->colors[1][1] = 0xFFFF00;
	map->colors[1][2] = 0x0000FF;
	map->colors[1][3] = 0xFFFFFF;
	map->colors[2][0] = 0xF7F9D4;
	map->colors[2][1] = 0xC0510A;
	map->colors[2][2] = 0x000652;
	map->colors[2][3] = 0x226ECE;
	map->colors[3][0] = 0x000070;
	map->colors[3][1] = 0xFF0000;
	map->colors[3][2] = 0xFFFF00;
	map->colors[3][3] = 0xFF0000;
	map->colors[4][0] = 0x00FFFF;
	map->colors[4][1] = 0xFFFF00;
	map->colors[4][2] = 0xFF0000;
	map->colors[4][3] = 0x0000FF;
}

void	ft_map_init(t_map *map)
{
	map->window.x = 1200;
	map->window.y = 900;
	ft_color_init(map);
	if (map->fractal == MANDELBROT)
		ft_mandelbrot_init(map);
	else
		ft_julia_init(map);
	map->mouse_status = FALSE;
	map->inf_status = FALSE;
	map->color_status = TRUE;
	map->palette = 0;
}

void	ft_free_map(t_map *map)
{
	free(map->mlx_ptr);
	free(map->win_ptr);
	free(map);
}
