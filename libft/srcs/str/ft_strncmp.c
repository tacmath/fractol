/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strncmp.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mtaquet <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/08/06 13:12:58 by mtaquet      #+#   ##    ##    #+#       */
/*   Updated: 2018/10/16 12:10:07 by mtaquet     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include <string.h>

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	int					i;
	unsigned const char *str1;
	unsigned const char *str2;

	i = 0;
	str1 = (unsigned const char*)s1;
	str2 = (unsigned const char*)s2;
	if (n == 0)
		return (0);
	while (str1[i] == str2[i] && (str1[i] != '\0' || str2[i] != '\0') && n > 1)
	{
		i++;
		n--;
	}
	return (str1[i] - str2[i]);
}
