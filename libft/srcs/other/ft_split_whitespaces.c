/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_split_whitespaces.c                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mtaquet <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/08/08 14:40:06 by mtaquet      #+#   ##    ##    #+#       */
/*   Updated: 2018/10/16 16:05:03 by mtaquet     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include <stdlib.h>

static int	nombre(char *str, int m, int n)
{
	while (str[n])
	{
		n++;
		if ((str[n] == ' ' || str[n] == 9 || str[n] == '\n')
				&& (str[n - 1] != ' ' || str[n - 1] != 9 || str[n - 1] != '\n'))
		{
			m++;
			n++;
		}
		while (str[n] == ' ' || str[n] == 9 || str[n] == '\n')
			n++;
	}
	if (str[n - 1] != ' ' && str[n - 2] != 9 && str[n - 2] != '\n')
		m++;
	return (m);
}

static int	taille(int nb_mot, char *str, int m)
{
	int i;
	int n;

	n = 0;
	i = 0;
	while (str[n])
	{
		if (m == nb_mot)
			i++;
		n++;
		if ((str[n] == ' ' || str[n] == 9 || str[n] == '\n')
				&& (str[n - 1] != ' ' || str[n - 1] != 9 || str[n - 1] != '\n'))
		{
			m++;
			n++;
		}
		while (str[n] == ' ' || str[n] == 9 || str[n] == '\n')
			n++;
	}
	return (i);
}

static char	**split_whitespaces(char **mot, char *str, int m, int n)
{
	int i;

	i = 0;
	while (str[n] == ' ' || str[n] == 9 || str[n] == '\n')
		n++;
	while (str[n])
	{
		mot[m][i] = str[n];
		i++;
		n++;
		if ((str[n] == ' ' || str[n] == 9 || str[n] == '\n')
				&& (str[n - 1] != ' ' || str[n - 1] != 9 || str[n - 1] != '\n'))
		{
			mot[m][i] = '\0';
			i = 0;
			m++;
			n++;
		}
		while (str[n] == ' ' || str[n] == 9 || str[n] == '\n')
			n++;
	}
	if (str[n - 1] != ' ' && str[n - 2] != 9 && str[n - 2] != '\n')
		m++;
	mot[m] = 0;
	return (mot);
}

char		**ft_split_whitespaces(char *str)
{
	char	**mot;
	int		nb_mot;
	int		m;
	int		n;
	int		i;

	m = 0;
	n = 0;
	i = 0;
	nb_mot = nombre(str, m, n) + 1;
	mot = malloc(sizeof(*mot) * (nb_mot));
	while (i < nb_mot)
	{
		mot[i] = malloc(sizeof(mot[i]) * taille(nb_mot, str, m));
		i++;
	}
	mot = split_whitespaces(mot, str, m, n);
	return (mot);
}
