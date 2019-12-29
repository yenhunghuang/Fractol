/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shift.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yehuang <yehuang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/19 21:47:51 by yehuang           #+#    #+#             */
/*   Updated: 2019/12/20 17:28:43 by yehuang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	shift(int k, t_mlx *m, double scale)
{
	double	shift;

	shift = WIN_W * scale * fabs(m->scale[0]);
	if (k >= 125)
		shift = WIN_H * scale * fabs(m->scale[1]);
	if (k == 126)
	{
		m->xy_mnmx[2] += shift;
		m->xy_mnmx[3] += shift;
	}
	else if (k == 125)
	{
		m->xy_mnmx[2] -= shift;
		m->xy_mnmx[3] -= shift;
	}
	else if (k == 123)
	{
		m->xy_mnmx[0] += shift;
		m->xy_mnmx[1] += shift;
	}
	else if (k == 124)
	{
		m->xy_mnmx[0] -= shift;
		m->xy_mnmx[1] -= shift;
	}
}
