/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yehuang <yenhang1@gmail.co>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/24 12:05:05 by yehuang           #+#    #+#             */
/*   Updated: 2019/07/24 13:46:32 by yehuang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strdup(const char *s1)
{
	size_t	len;
	char	*s2;

	len = ft_strlen(s1) + 1;
	s2 = (char *)malloc(sizeof(char) * len);
	if (s2 == NULL)
		return (NULL);
	ft_strcpy(s2, s1);
	return (s2);
}
