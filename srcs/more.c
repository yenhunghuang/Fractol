/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   more.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yehuang <yehuang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/19 22:37:22 by yehuang           #+#    #+#             */
/*   Updated: 2019/12/20 17:15:09 by yehuang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	print_instructions(t_mlx *m)
{
	mlx_string_put(m->mlx, m->win, 5, 0, 0xFFFFFF, "Zoom: mouse wheel");
	mlx_string_put(m->mlx, m->win, 5, 20, 0xFFFFFF, "Recenter: mouse click");
	mlx_string_put(m->mlx, m->win, 5, 40, 0xFFFFFF,
		"Hold: h ");
	mlx_string_put(m->mlx, m->win, 5, 60, 0xFFFFFF, "Change color set: c");
	mlx_string_put(m->mlx, m->win, 5, 80, 0xFFFFFF, "Shift: arrows");
	mlx_string_put(m->mlx, m->win, 5, 100, 0xFFFFFF,
		"Change Fractols: 1 2 3...");
	mlx_string_put(m->mlx, m->win, 5, 120, 0xFFFFFF,
		"Print Instructions: i");
}

int		ship_converge(t_mlx *m, int x, int y)
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
		i = fabs(i);
		r = fabs(r);
		tmp = i * i - r * r + pxl_to_coor[0];
		r = 2 * i * r + pxl_to_coor[1];
		i = tmp;
	}
	return (iter);
}

int		lauren_converge(t_mlx *m, int x, int y)
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
		tmp = fabs(i * i - r * r) + pxl_to_coor[0];
		r = 2 * i * r + pxl_to_coor[1];
		i = tmp;
	}
	return (iter);
}

int		threeman_converge(t_mlx *m, int x, int y)
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
		tmp = r * r * r - 3 * r * i * i + pxl_to_coor[0];
		i = 3 * r * r * i - i * i * i + pxl_to_coor[1];
		r = tmp;
	}
	return (iter);
}

int		fiveman_converge(t_mlx *m, int x, int y)
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
		tmp = r * r * r * r * r - 10 * r * r * r * i * i +
			5 * r * i * i * i * i + pxl_to_coor[0];
		i = 5 * r * r * r * r * i - 10 * r * r * i * i * i +
			i * i * i * i * i + pxl_to_coor[1];
		r = tmp;
	}
	return (iter);
}
