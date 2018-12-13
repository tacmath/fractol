/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_print_tables.c_fd                             .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mtaquet <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/16 15:40:26 by mtaquet      #+#   ##    ##    #+#       */
/*   Updated: 2018/10/16 15:44:09 by mtaquet     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include <unistd.h>

void	ft_print_tables_fd(char **tab, int fd)
{
	int n;
	int m;

	n = 0;
	m = 0;
	while (tab[m] != 0)
	{
		n = 0;
		while (tab[m][n])
			write(fd, &tab[m][n++], 1);
		write(fd, "\n", 1);
		m++;
	}
}
