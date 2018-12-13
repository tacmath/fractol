/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_lstnew.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mtaquet <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/05 09:51:45 by mtaquet      #+#   ##    ##    #+#       */
/*   Updated: 2018/10/15 13:30:13 by mtaquet     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list		*list;

	if (!(list = malloc(sizeof(t_list))))
		return (0);
	if (!content)
	{
		list->content = 0;
		list->content_size = 0;
	}
	else
	{
		if (!(list->content = malloc(sizeof(content_size))))
			return (0);
		list->content_size = content_size;
		list->content = ft_memcpy(list->content, content, content_size);
	}
	list->next = 0;
	return (list);
}
