/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strcmp.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mtaquet <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/08/06 12:47:07 by mtaquet      #+#   ##    ##    #+#       */
/*   Updated: 2018/10/16 12:06:32 by mtaquet     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

int	ft_strcmp(const char *s1, const char *s2)
{
	int					n;
	unsigned const char	*str1;
	unsigned const char	*str2;

	n = 0;
	str1 = (unsigned const char*)s1;
	str2 = (unsigned const char*)s2;
	while (str1[n] == str2[n] && (str1[n] != '\0' || str2[n] != '\0'))
	{
		n++;
	}
	return (str1[n] - str2[n]);
}
