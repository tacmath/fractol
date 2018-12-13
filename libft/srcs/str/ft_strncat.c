/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strncat.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mtaquet <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/08/07 13:02:07 by mtaquet      #+#   ##    ##    #+#       */
/*   Updated: 2018/10/15 16:45:42 by mtaquet     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include <string.h>

char	*ft_strncat(char *dest, const char *src, size_t nb)
{
	size_t	taille;
	size_t	n;

	taille = 0;
	n = 0;
	taille = 0;
	while (dest[taille])
		taille++;
	while (nb > n && src[n] != '\0')
	{
		dest[taille + n] = src[n];
		n++;
	}
	dest[taille + n] = '\0';
	return (dest);
}
