/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strcat.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mtaquet <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/08/07 12:31:09 by mtaquet      #+#   ##    ##    #+#       */
/*   Updated: 2018/10/15 13:49:39 by mtaquet     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

char	*ft_strcat(char *dest, const char *src)
{
	int taille;
	int n;

	taille = 0;
	n = 0;
	while (dest[taille])
		taille++;
	while (src[n])
	{
		dest[taille + n] = src[n];
		n++;
	}
	dest[taille + n] = '\0';
	return (dest);
}
