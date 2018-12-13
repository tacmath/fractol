/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strmap.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mtaquet <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/03 12:09:35 by mtaquet      #+#   ##    ##    #+#       */
/*   Updated: 2018/10/05 10:16:30 by mtaquet     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strmap(char const *s, char (*f)(char))
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
			str[n] = f(s[n]);
			n++;
		}
		str[n] = '\0';
	}
	return (str);
}
