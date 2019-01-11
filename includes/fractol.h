/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   fractol.h                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mtaquet <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/12/05 14:37:32 by mtaquet      #+#   ##    ##    #+#       */
/*   Updated: 2019/01/11 14:09:39 by mtaquet     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "libft.h"
# include "mlx.h"
# include <inttypes.h>
# define TRUE				1
# define FALSE				0
# define WIDTH				1300
# define LENGTH				900
# define NB_THREAD			90
# define MANDELBROT			1
# define JULIA				2
# define FLAT				3
# define BURNING_SHIP		4
# define KEY_PRESS			2
# define BUTTON_RELEASE		5
# define MOTION_NOTIFY		6
# define DESTROY_NOTIFY		17
# define KEY_ESCAPE			53
# define KEY_PLUS			69
# define KEY_MINUS			78
# define KEY_UP				126
# define KEY_DOWN			125
# define KEY_RIGHT			124
# define KEY_LEFT			123
# define KEY_ONE			18
# define KEY_TWO			19
# define KEY_THREE			20
# define KEY_FOUR			21
# define KEY_R				15
# define KEY_T				17
# define KEY_S				1
# define KEY_I				34
# define KEY_P				35
# define KEY_C				8
# define RIGHT_CLICK		1
# define ROULETTE_UP		4
# define ROULETTE_DOWN		5

struct						s_size
{
	int						x;
	int						y;
};

typedef struct s_size	t_size;

struct						s_fractal
{
	double					x1;
	double					x2;
	double					y1;
	double					y2;
	double					c_r;
	double					c_i;
	double					z_r;
	double					z_i;
	int						power;
	intmax_t				i_max;
};

typedef struct s_fractal	t_fractal;

struct						s_map
{
	void					*mlx_ptr;
	void					*win_ptr;
	void					*img_ptr;
	char					*data;
	t_size					window;
	int						img_bits_per_pix;
	int						img_size_line;
	int						colors[5][4];
	int						palette;
	int						thread;
	int						thread_length;
	char					fractal;
	char					mouse_status;
	char					color_status;
	char					inf_status;
	t_fractal				frac;
};

typedef struct s_map		t_map;

void						ft_fractal_init(t_map *map);
void						ft_map_init(t_map *map);
int							ft_image_init(t_map *map);
void						ft_color_init(t_map *map);
void						ft_free_map(t_map *map);
void						ft_threading(t_map *map, void *fractal(void *map));
int							ft_destroy(t_map *map);
int							deal_key(int key, t_map *map);
int							deal_mouse(int button, int x, int y, t_map *map);
int							deal_mv(int x, int y, t_map *map);
int							deal_key_press(int key, t_map *map);
void						ft_color_change(int *color);
void						ft_pixel_put(t_map *map, int x, int y, int color);
void						ft_color_pix(t_map *map, int x, int y, intmax_t i);
void						ft_infini(t_map *map);
void						ft_iterrations(t_map *map);
void						ft_color_controls(t_map *map);
void						ft_head(t_map *map);
void						ft_controls(t_map *map);
void						ft_otherbrot_pix(t_map *map, int x, int y);
void						ft_mandelbrot_pix(t_map *map, int x, int y);
void						ft_mandelbship_pix(t_map *map, int x, int y);
void						ft_draw(t_map *map);

#endif
