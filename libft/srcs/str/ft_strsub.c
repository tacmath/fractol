/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strsub.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mtaquet <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/03 12:34:57 by mtaquet      #+#   ##    ##    #+#       */
/*   Updated: 2018/10/29 11:02:18 by mtaquet     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	size_t	n;
	char	*str;
	int		i;

	str = 0;
	i = 0;
	if (!s)
		return (0);
	if (!(str = malloc(sizeof(char) * (len + 1))))
		return (0);
	n = start;
	while (s[n] != '\0' && len > 0)
	{
		str[i++] = s[n];
		len--;
		n++;
	}
	str[i] = '\0';
	return (str);
}
