/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_memalloc.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mtaquet <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/03 11:29:52 by mtaquet      #+#   ##    ##    #+#       */
/*   Updated: 2018/10/04 14:17:55 by mtaquet     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include <stdlib.h>

void	*ft_memalloc(size_t size)
{
	char	*mem;
	size_t	n;

	mem = 0;
	n = -1;
	if (!(mem = (char*)malloc(sizeof(void) * size)))
		return (0);
	while (size > ++n)
		mem[n] = '\0';
	return (mem);
}
