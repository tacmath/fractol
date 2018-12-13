/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strdup.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mtaquet <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/08/08 10:43:04 by mtaquet      #+#   ##    ##    #+#       */
/*   Updated: 2018/10/04 17:12:37 by mtaquet     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strdup(const char *src)
{
	int		taille;
	char	*str;

	taille = 0;
	while (src[++taille])
		;
	if (!(str = malloc(sizeof(char) * (taille + 1))))
		return (0);
	taille = 0;
	while (src[taille])
	{
		str[taille] = src[taille];
		taille++;
	}
	str[taille] = '\0';
	return (str);
}
