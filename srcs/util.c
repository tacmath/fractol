# include "fractol.h"

void	ft_map_init(t_map *map)
{
	map->window.x = 1000;
	map->window.y = 700;
}

void	ft_free_map(t_map *map)
{
	free(map->mlx_ptr);
	free(map->win_ptr);
	free(map);
}
