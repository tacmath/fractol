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
# include <inttypes.h>
# define TRUE 1
# define FALSE 0
# define MANDELBROT 1
# define JULIA 2
# define FLAT 3
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
# define KEY_ONE	18
# define KEY_TWO	19
# define KEY_THREE	20
# define KEY_FOUR       21
# define KEY_R           15
# define KEY_S           1
# define KEY_I           34
# define KEY_P           35
# define KEY_C           8
# define RIGHT_CLICK             1
# define ROULETTE_UP		4
# define ROULETTE_DOWN		5

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
	intmax_t i_max;
};

typedef struct s_fractal	t_fractal;

struct			s_map
{
	void	*mlx_ptr;
	void	*win_ptr;
	t_size	window;
	int	colors[5][4];
	int	palette;
	char	fractal;
	char	mouse_status;
	char	color_status;
	char	inf_status;
	t_fractal frac;
};

typedef struct s_map	t_map;

void	ft_map_init(t_map *map);
void	ft_free_map(t_map *map);
int	ft_destroy(t_map *map);
int	deal_key(int key, t_map *map);
int     deal_mouse(int button, int x, int y, t_map *map);
int     deal_mv(int x, int y, t_map *map);
int     deal_key_press(int key, t_map *map);
void	ft_mandelbrot(t_map *map);
void	ft_color_change(int *color);
void	ft_controls(t_map *map);
void    ft_julia(t_map *map);
void	ft_draw(t_map *map);

#endif
