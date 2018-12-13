/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strjoin.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mtaquet <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/03 12:46:19 by mtaquet      #+#   ##    ##    #+#       */
/*   Updated: 2018/10/20 17:37:05 by mtaquet     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		n;
	int		m;
	char	*str;

	n = 0;
	m = 0;
	str = 0;
	if (!(s1 && s2))
		return (0);
	while (s1[n])
		n++;
	while (s2[m])
		m++;
	if (!(str = malloc(sizeof(char) * (m + n + 1))))
		return (0);
	n = -1;
	while (s1[++n])
		str[n] = s1[n];
	m = 0;
	while (s2[m])
		str[n++] = s2[m++];
	str[n] = '\0';
	return (str);
}
