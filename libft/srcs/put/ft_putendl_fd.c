/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_putendl_fd.c                                  .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mtaquet <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/03 16:50:20 by mtaquet      #+#   ##    ##    #+#       */
/*   Updated: 2018/10/05 10:21:12 by mtaquet     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putendl_fd(char const *s, int fd)
{
	int n;

	n = -1;
	if (s)
	{
		while (s[++n])
			write(fd, &s[n], 1);
	}
	write(fd, "\n", 1);
}
