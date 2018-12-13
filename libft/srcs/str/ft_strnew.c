/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strnew.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mtaquet <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/03 11:45:25 by mtaquet      #+#   ##    ##    #+#       */
/*   Updated: 2018/10/04 14:13:31 by mtaquet     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strnew(size_t size)
{
	char	*mem;
	int		n;

	mem = 0;
	n = 0;
	size++;
	if (!(mem = malloc(sizeof(char) * size)))
		return (0);
	while (size > 0)
	{
		mem[n] = '\0';
		n++;
		size--;
	}
	return (mem);
}
