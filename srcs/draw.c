/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yehuang <yehuang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/18 16:30:47 by yehuang           #+#    #+#             */
/*   Updated: 2019/12/20 17:27:15 by yehuang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

double	calc_cor(t_mlx *m, int cor, int md)
{
	if (md == 0)
		return (((m->xy_mnmx[0] + m->xy_mnmx[1]) / 2 +
					(cor - (double)WIN_W / 2) * m->scale[0]));
	else
		return (((m->xy_mnmx[2] + m->xy_mnmx[3]) / 2 -
				(cor - (double)WIN_H / 2) * m->scale[1]));
}

int		julia_converge(t_mlx *m, int x, int y)
{
	double	i;
	double	r;
	double	tmp;
	int		iter;

	iter = 0;
	i = calc_cor(m, x, 0);
	r = calc_cor(m, y, 1);
	while (iter++ < m->mx_i && i * i + r * r <= m->mx_d)
	{
		tmp = i * i - r * r + m->init_c[1];
		r = 2 * i * r + m->init_c[0];
		i = tmp;
	}
	return (iter);
}

int		man_converge(t_mlx *m, int x, int y)
{
	double	i;
	double	r;
	double	tmp;
	int		iter;
	double	pxl_to_coor[2];

	iter = 0;
	i = 0;
	r = 0;
	pxl_to_coor[0] = calc_cor(m, x, 0);
	pxl_to_coor[1] = calc_cor(m, y, 1);
	while (iter++ < m->mx_i && i * i + r * r <= m->mx_d)
	{
		tmp = i * i - r * r + pxl_to_coor[0];
		r = m->set_mode == 0 ? 2 * i * r + pxl_to_coor[1] :
								-2 * i * r + pxl_to_coor[1];
		i = tmp;
	}
	return (iter);
}

int		dispatch(t_mlx *m, int x, int y)
{
	if (m->set_mode == 1)
		return (julia_converge(m, x, y));
	else if (m->set_mode == 0 || m->set_mode == 3)
		return (man_converge(m, x, y));
	else if (m->set_mode == 2)
		return (ship_converge(m, x, y));
	else if (m->set_mode == 4)
		return (lauren_converge(m, x, y));
	else if (m->set_mode == 5)
		return (threeman_converge(m, x, y));
	else if (m->set_mode == 6)
		return (fiveman_converge(m, x, y));
	else
		return (0);
}

void	draw(t_mlx *m)
{
	int		i;
	int		x;
	int		y;

	y = -1;
	while (++y < WIN_H)
	{
		x = -1;
		while (++x < WIN_W)
		{
			i = dispatch(m, x, y);
			((unsigned int *)m->ad)[((WIN_H - (y + 1)) * WIN_W + x)] =
			i <= m->mx_i ? m->color[i % 16] : 0;
		}
	}
	mlx_put_image_to_window(m->mlx, m->win, m->img, 0, 0);
}
