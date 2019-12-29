/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yehuang <yenhang1@gmail.co>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/24 20:10:00 by yehuang           #+#    #+#             */
/*   Updated: 2019/07/26 22:19:35 by yehuang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(const char *s, char (*f)(char))
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
			result[i] = (*f)(s[i]);
			i++;
		}
		return (result);
	}
	return (NULL);
}
