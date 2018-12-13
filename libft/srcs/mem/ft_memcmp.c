/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_memcmp.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mtaquet <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/02 14:17:32 by mtaquet      #+#   ##    ##    #+#       */
/*   Updated: 2018/10/15 16:17:44 by mtaquet     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include <string.h>

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	int					i;
	unsigned const char	*se1;
	unsigned const char	*se2;

	i = 0;
	se1 = s1;
	se2 = s2;
	if (n == 0)
		return (0);
	while (se1[i] == se2[i] && n > 1)
	{
		i++;
		n--;
	}
	return (se1[i] - se2[i]);
}
