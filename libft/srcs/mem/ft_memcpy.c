/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_memcpy.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mtaquet <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/02 13:05:29 by mtaquet      #+#   ##    ##    #+#       */
/*   Updated: 2018/10/02 14:12:58 by mtaquet     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include <string.h>

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	int			i;
	char		*str;
	const char	*constr;

	i = 0;
	str = dst;
	constr = src;
	while (n > 0)
	{
		str[i] = constr[i];
		i++;
		n--;
	}
	dst = str;
	return (dst);
}
