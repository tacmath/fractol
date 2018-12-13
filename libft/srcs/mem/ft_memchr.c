/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_memchr.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mtaquet <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/02 14:47:33 by mtaquet      #+#   ##    ##    #+#       */
/*   Updated: 2018/10/16 11:27:56 by mtaquet     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include <string.h>

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned const char	*str;
	int					i;

	i = 0;
	str = s;
	while (n > 0)
	{
		if (str[i] == (unsigned char)c)
			return ((void*)&s[i]);
		i++;
		n--;
	}
	return (0);
}
