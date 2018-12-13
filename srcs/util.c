# include "fractol.h"

void	ft_map_init(t_map *map)
{
	map->window.x = 1000;
	map->window.y = 700;
	map->mdb.x1 = -2.1;
	map->mdb.x2 = 0.6;
	map->mdb.y1 = -1.2;
	map->mdb.y2 = 1.2;
	map->mdb.i_max = 15;
	map->mdb.status = FALSE;
	map->julia.x1 = -1.6;
	map->julia.x2 = 1.6;
	map->julia.y1 = -1.2;
	map->julia.y2 = 1.2;
	map->julia.i_max = 50;
	map->julia.status = FALSE;
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
