/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yehuang <yenhang1@gmail.co>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/25 10:39:30 by yehuang           #+#    #+#             */
/*   Updated: 2019/07/26 22:30:38 by yehuang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

static int	whitespace(int c)
{
	return (c == ' ' || c == '\t' || c == '\n' || c == '\v' || \
			c == '\r' || c == '\f');
}

char		*ft_strtrim(char const *s)
{
	size_t	start;
	size_t	end;
	char	*new;

	if (s)
	{
		start = 0;
		end = ft_strlen(s);
		while (whitespace(s[start]))
			start++;
		while (whitespace(s[end - 1]))
			end--;
		if (end < start)
			end = start;
		new = ft_strnew(end - start);
		if (new == NULL)
			return (NULL);
		return (ft_strncpy(new, s + start, end - start));
	}
	return (NULL);
}
