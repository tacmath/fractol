/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strsplit.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mtaquet <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/03 14:50:31 by mtaquet      #+#   ##    ##    #+#       */
/*   Updated: 2018/10/17 10:11:54 by mtaquet     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include <stdlib.h>

static int	nb_word(char const *s, char c)
{
	int n;
	int m;

	n = 0;
	m = 0;
	if (s[n] != c && s[n] != '\0')
		m++;
	n--;
	while (s[++n])
		if (s[n] == c && s[n + 1] != c && s[n + 1] != '\0')
			m++;
	return (m);
}

static int	len_word(char const *s, char c, int nb)
{
	int n;
	int m;
	int len;

	n = 0;
	m = 0;
	len = 1;
	if (s[n] != c)
		m++;
	n--;
	while (s[++n])
	{
		if (nb == m && s[n] != c)
			len++;
		if (s[n] == c && s[n + 1] != c && s[n + 1] != '\0')
			m++;
	}
	return (len);
}

static char	**split(char const *s, char c, char **tab, int n)
{
	int i;
	int m;

	m = 0;
	i = 0;
	if (s[n] != c && s[n] != '\0')
		m++;
	n--;
	while (s[++n])
	{
		if (m > 0 && s[n] != c)
			tab[m - 1][i++] = s[n];
		if (m > 0 && s[n - 1] != c && (s[n] == c || s[n] == '\0'))
		{
			tab[m - 1][i] = '\0';
			i = 0;
		}
		if (s[n] == c && s[n + 1] != c && s[n + 1] != '\0')
			m++;
	}
	if (m > 0 && s[n - 1] != c && s[n] == '\0')
		tab[m - 1][i] = '\0';
	return (tab);
}

char		**ft_strsplit(char const *s, char c)
{
	int		n;
	int		m;
	char	**tab;

	m = -1;
	n = 0;
	tab = 0;
	if (s)
	{
		if (!(tab = malloc(sizeof(*tab) * (nb_word(s, c) + 1))))
			return (0);
		while (++m < nb_word(s, c))
			if (!(tab[m] = malloc(sizeof(tab[m]) * len_word(s, c, (m + 1)))))
				return (0);
		tab[nb_word(s, c)] = 0;
		tab = split(s, c, tab, 0);
	}
	return (tab);
}
