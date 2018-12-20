#include "fractol.h"

void    ft_controls(t_map *map)
{
	char *tmp;

	mlx_clear_window(map->mlx_ptr, map->win_ptr);
	if (map->color_status == TRUE)
	{
		mlx_string_put(map->mlx_ptr, map->win_ptr, 5, 210, map->colors[map->palette][1], "< C >  colors  :    on");
		mlx_string_put(map->mlx_ptr, map->win_ptr, 30, 240, map->colors[map->palette][2], "< P >  palette :");
		tmp = ft_itoa(map->palette + 1);
		mlx_string_put(map->mlx_ptr, map->win_ptr, 205, 240, map->colors[map->palette][2], tmp);
		free(tmp);
		if (map->palette == 4)
		{
			mlx_string_put(map->mlx_ptr, map->win_ptr, 50, 270,  map->colors[4][0], "< 1 > change first  color");
			mlx_string_put(map->mlx_ptr, map->win_ptr, 50, 300, map->colors[4][1], "< 2 > change second color");
			mlx_string_put(map->mlx_ptr, map->win_ptr, 50, 330, map->colors[4][2], "< 3 > change third  color");
			mlx_string_put(map->mlx_ptr, map->win_ptr, 50, 360, map->colors[4][3], "< 4 > change last   color");
		}
	}
	else
		mlx_string_put(map->mlx_ptr, map->win_ptr, 5, 210, 0xFFFFFF, "< C >  colors  :   off");
	mlx_string_put(map->mlx_ptr, map->win_ptr, 5, 10, 0xFFFFFF, "< ESCAPE >  Quit");
	mlx_string_put(map->mlx_ptr, map->win_ptr, 30, 40, 0xFFFFFF, "< R > reset");
	mlx_string_put(map->mlx_ptr, map->win_ptr, 30, 70, 0xFFFFFF, "< + > more iterations");
	mlx_string_put(map->mlx_ptr, map->win_ptr, 30, 100, 0xFFFFFF, "< - > less iterations");
	mlx_string_put(map->mlx_ptr, map->win_ptr, 140, 130, 0xFFFFFF, "iterations :");
	tmp = ft_itoa(map->frac.i_max);
	mlx_string_put(map->mlx_ptr, map->win_ptr, 270, 130, 0xFFFFFF, tmp);
	free(tmp);
	mlx_string_put(map->mlx_ptr, map->win_ptr, 30, 500, 0xFFFFFF, "utilisez les fleches directionelles"); 
	mlx_string_put(map->mlx_ptr, map->win_ptr, 30, 530, 0xFFFFFF, "pour vous deplacer dans la fractale");
	mlx_string_put(map->mlx_ptr, map->win_ptr, 40, 600, 0xFFFFFF, "utilisez la molette de la souris");
	mlx_string_put(map->mlx_ptr, map->win_ptr, 15, 630, 0xFFFFFF, "pour zomer sur un point de la fractale");
}
