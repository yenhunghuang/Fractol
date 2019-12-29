/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yehuang <yenhang1@gmail.co>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/25 14:36:17 by yehuang           #+#    #+#             */
/*   Updated: 2019/07/25 15:11:10 by yehuang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list	*link;

	link = (t_list *)ft_memalloc(sizeof(t_list));
	if (link == NULL)
		return (NULL);
	if (content == NULL)
	{
		content_size = 0;
		link->content = NULL;
	}
	else
	{
		link->content = ft_memalloc(content_size);
		if (link->content == NULL)
		{
			ft_memdel((void **)&link);
			return (NULL);
		}
		ft_memcpy(link->content, content, content_size);
	}
	link->content_size = content_size;
	link->next = NULL;
	return (link);
}
