/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_itoa.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mtaquet <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/03 16:31:30 by mtaquet      #+#   ##    ##    #+#       */
/*   Updated: 2018/10/15 16:28:13 by mtaquet     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include <stdlib.h>

static int	len_nb(int n)
{
	int len;

	len = 2;
	if (n < 0)
	{
		if (n == -2147483648)
			return (12);
		len++;
		n = -n;
	}
	while (n / 10 > 0)
	{
		n = n / 10;
		len++;
	}
	return (len);
}

static char	*n_pos(int len, int n, char *nb)
{
	while (n / 10 > 0)
	{
		len--;
		nb[len] = n % 10 + '0';
		n = n / 10;
	}
	len--;
	nb[len] = n % 10 + '0';
	return (nb);
}

char		*ft_itoa(int n)
{
	char	*nb;
	int		len;

	nb = 0;
	len = len_nb(n);
	if (!(nb = malloc(sizeof(char) * len)))
		return (0);
	len--;
	nb[len] = '\0';
	if (n < 0)
	{
		nb[0] = '-';
		if (n == -2147483648)
		{
			nb[len - 1] = '8';
			n = -214748364;
			len--;
		}
		n = -n;
	}
	nb = n_pos(len, n, nb);
	return (nb);
}
