
int     ft_rgb(unsigned char r, unsigned char g, unsigned char b)
{
	return ((r << 16) | (g << 8) | b);
}

unsigned char ft_hextor(int color)
{
	return (color >> 16);
}

unsigned char ft_hextog(int color)
{
	return ((color << 16) >> 24);
}

unsigned char ft_hextob(int color)
{
	return ((color << 24) >> 24);
}
