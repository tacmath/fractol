/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_memmove.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mtaquet <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/03 10:18:49 by mtaquet      #+#   ##    ##    #+#       */
/*   Updated: 2018/10/04 16:49:53 by mtaquet     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include <string.h>

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char		*dest;
	const char	*str;
	size_t		n;

	dest = dst;
	str = src;
	n = -1;
	if (src < dst)
	{
		while (++n < len)
			dest[len - n - 1] = str[len - n - 1];
	}
	else
	{
		while (++n < len)
			dest[n] = str[n];
	}
	return (dest);
}
