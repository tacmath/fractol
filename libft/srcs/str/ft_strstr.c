/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strstr.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mtaquet <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/08/06 17:29:11 by mtaquet      #+#   ##    ##    #+#       */
/*   Updated: 2018/10/15 14:00:01 by mtaquet     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

char	*ft_strstr(const char *str, const char *to_find)
{
	int n;
	int m;
	int taille;

	n = 0;
	m = 0;
	taille = 0;
	while (to_find[taille])
		taille++;
	if (taille == 0)
		return ((char*)str);
	while (str[n])
	{
		while (str[n + m] == to_find[m] && m < taille)
		{
			if (m == taille - 1)
				return ((char*)&str[n]);
			m++;
		}
		m = 0;
		n++;
	}
	return (0);
}
