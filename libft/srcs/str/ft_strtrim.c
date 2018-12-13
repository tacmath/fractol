/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strtrim.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mtaquet <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/03 14:25:07 by mtaquet      #+#   ##    ##    #+#       */
/*   Updated: 2018/10/05 13:12:19 by mtaquet     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strtrim(char const *s)
{
	int		start;
	int		end;
	int		n;
	char	*str;

	n = -1;
	end = 0;
	if (!s)
		return (0);
	while (s[++n] != '\0' && (s[n] == ' ' || s[n] == '\n' || s[n] == '\t'))
		;
	start = n--;
	while (s[++n])
		if (s[n - 1] != ' ' && s[n - 1] != '\n' && s[n - 1] != '\t'
			&& (s[n] == ' ' || s[n] == '\n' || s[n] == '\t'))
			end = n;
	if (end == 0 || (s[n - 1] != ' ' && s[n - 1] != '\n' && s[n - 1] != '\t'))
		end = n;
	if (!(str = malloc(sizeof(char) * (end - start + 1))))
		return (0);
	n = start - 1;
	while (++n < end)
		str[n - start] = s[n];
	str[n - start] = '\0';
	return (str);
}
