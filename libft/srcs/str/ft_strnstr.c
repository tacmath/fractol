/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strnstr.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mtaquet <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/02 15:58:19 by mtaquet      #+#   ##    ##    #+#       */
/*   Updated: 2018/10/04 09:31:02 by mtaquet     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include <string.h>

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t n;
	size_t m;
	size_t taille;

	n = 0;
	taille = 0;
	while (needle[taille])
		taille++;
	if (taille == 0)
		return ((char*)haystack);
	while (haystack[n])
	{
		m = 0;
		while (haystack[n + m] == needle[m] && m < taille && len > (n + m))
		{
			if (m == taille - 1)
				return ((char*)&haystack[n]);
			m++;
		}
		n++;
	}
	return (0);
}
