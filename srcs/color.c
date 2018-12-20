#include "fractol.h"

void			ft_color_change(int *color)
{
	unsigned char r;
	unsigned char g;
	unsigned char b;

	r = ft_hextor(*color);
	g = ft_hextog(*color);
	b = ft_hextob(*color);
	if (b < 255 && g == 0)
		b += 15;
	else if (g < 255 && r == 0)
		g += 15;
	else if (g == 255 && b > 0)
		b -= 15;
	else if (r < 255 && b == 0)
		r += 15;
	else if (r == 255 && g > 0)
		g -= 15;
	else if (r > 0)
		r -= 15;
	(*color) = ft_rgb(r, g, b);
}
