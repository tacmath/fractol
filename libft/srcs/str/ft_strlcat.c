/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strlcat.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mtaquet <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/03 10:01:26 by mtaquet      #+#   ##    ##    #+#       */
/*   Updated: 2018/10/05 12:35:53 by mtaquet     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include <string.h>

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t len_dst;
	size_t len_src;
	size_t n;

	len_dst = -1;
	len_src = -1;
	n = 0;
	while (dst[++len_dst])
		;
	while (src[++len_src])
		;
	if (len_dst > size)
		return (size + len_src);
	while (len_dst + n + 1 < size && src[n] != '\0')
	{
		dst[len_dst + n] = src[n];
		n++;
	}
	dst[len_dst + n] = '\0';
	return (len_dst + len_src);
}
