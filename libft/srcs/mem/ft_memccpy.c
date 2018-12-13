/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_memccpy.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mtaquet <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/02 13:45:51 by mtaquet      #+#   ##    ##    #+#       */
/*   Updated: 2018/10/16 15:10:15 by mtaquet     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include <string.h>

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	size_t				i;
	unsigned char		*str;
	const unsigned char	*constr;

	i = -1;
	str = dst;
	constr = src;
	while (++i < n)
	{
		str[i] = constr[i];
		if (constr[i] == (unsigned char)c)
			return ((void*)&str[i + 1]);
	}
	return (0);
}
