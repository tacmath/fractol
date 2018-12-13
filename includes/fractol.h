/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   fractol.h                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mtaquet <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/12/05 14:37:32 by mtaquet      #+#   ##    ##    #+#       */
/*   Updated: 2018/12/10 02:18:51 by mtaquet     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "libft.h"
# include "mlx.h"
# define TRUE 1
# define FALSE 0
# define KEY_PRESS               2
# define BUTTON_RELEASE          5
# define MOTION_NOTIFY           6
# define DESTROY_NOTIFY          17
# define KEY_ESCAPE      53
# define KEY_PLUS        69
# define KEY_MINUS       78
# define KEY_UP          126
# define KEY_DOWN        125
# define KEY_RIGHT       124
# define KEY_LEFT        123
# define KEY_C           8
# define RIGHT_CLICK             1
# define ROULETTE_UP             5
# define ROULETTE_DOWN   4

struct			s_size
{
	int x;	
	int y;
};

typedef struct s_size	t_size;

struct				s_fractal
{
	double x1;
	double x2;
	double y1;
	double y2;
	double c_r;
	double c_i;
	double z_r;
	double z_i;
	int	i_max;
};

typedef struct s_fractal	t_fractal;

struct			s_map
{
	void	*mlx_ptr;
	void	*win_ptr;
	t_size	window;
	t_fractal mdb;
	t_fractal julia;
};

typedef struct s_map	t_map;

int	ft_rgb(unsigned char r, unsigned char g, unsigned char b);
void	ft_map_init(t_map *map);
void	ft_free_map(t_map *map);
int	ft_destroy(t_map *map);
int	deal_key(int key, t_map *map);

#endif
