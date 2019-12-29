/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yehuang <yenhang1@gmail.co>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/24 20:17:24 by yehuang           #+#    #+#             */
/*   Updated: 2019/07/26 22:21:18 by yehuang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(const char *s, char (*f)(unsigned int, char))
{
	char			*result;
	unsigned int	i;

	if (s)
	{
		i = 0;
		result = ft_strnew(ft_strlen(s));
		if (result == NULL)
			return (NULL);
		while (s[i])
		{
			result[i] = (*f)(i, s[i]);
			i++;
		}
		return (result);
	}
	return (NULL);
}
