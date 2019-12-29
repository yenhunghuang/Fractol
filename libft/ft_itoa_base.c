/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yehuang <yenhang1@gmail.co>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/31 18:51:06 by yehuang           #+#    #+#             */
/*   Updated: 2019/07/31 20:53:13 by yehuang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_itoa_base(int value, int base)
{
	char	*s;
	long	number;
	int		sign;
	int		i;

	number = (value < 0) ? -value : value;
	sign = (value < 0 && base == 10) ? -1 : 0;
	i = (sign == -1) ? 2 : 1;
	while ((number /= base) >= 1)
		i++;
	if (!(s = (char *)malloc(sizeof(char) * (i + 1))))
		return (NULL);
	s[i] = '\0';
	number = (value < 0) ? -value : value;
	while (i-- + sign)
	{
		s[i] = (number % base < 10) ? number % base + '0' : \
			number % base + 'A' - 10;
		number /= base;
	}
	(i == 0) ? s[i] = '-' : 0;
	return (s);
}
