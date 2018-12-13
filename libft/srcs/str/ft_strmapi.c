/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strmapi.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mtaquet <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/03 12:16:59 by mtaquet      #+#   ##    ##    #+#       */
/*   Updated: 2018/10/05 10:11:17 by mtaquet     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	int		n;
	char	*str;

	n = 0;
	str = 0;
	if (s)
	{
		while (s[n])
			n++;
		if (!(str = malloc(sizeof(char) * (n + 1))))
			return (0);
		n = 0;
		while (s[n])
		{
			str[n] = f(n, s[n]);
			n++;
		}
		str[n] = '\0';
	}
	return (str);
}
