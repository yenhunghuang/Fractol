/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handler.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yehuang <yenhang1@gmail.co>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/20 17:12:00 by yehuang           #+#    #+#             */
/*   Updated: 2019/12/20 17:13:04 by yehuang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	setup(t_mlx *m)
{
	m->mx_i = 50;
	m->mx_d = 4;
	m->xy_mnmx[0] = -2;
	m->xy_mnmx[1] = 2;
	m->xy_mnmx[2] = -2;
	m->xy_mnmx[3] = 2;
	m->scale[0] = (m->xy_mnmx[1] - m->xy_mnmx[0]) / WIN_W;
	m->scale[1] = (m->xy_mnmx[3] - m->xy_mnmx[2]) / WIN_H;
	m->init_c[0] = 0;
	m->init_c[1] = 0;
	m->mouse[0] = 0;
	m->mouse[1] = 0;
	m->hold = 0;
	m->b_p_p = 8;
	m->s_l = WIN_W;
	m->end = 1;
	m->color_index = 0;
	change_color(m);
	m->ad = mlx_get_data_addr(m->img, &(m->b_p_p), &(m->s_l), &(m->end));
}

int		mouse_move(int x, int y, t_mlx *m)
{
	m->mouse[0] = x;
	m->mouse[1] = y;
	if (m->set_mode == 1 && !m->hold)
	{
		m->init_c[0] = calc_cor(m, x, 0);
		m->init_c[1] = calc_cor(m, y, 1);
		draw(m);
	}
	return (0);
}

int		mouse_handler(int b, int x, int y, t_mlx *m)
{
	double	x_mid;
	double	y_mid;
	double	n_mid[2];

	if (b == 4 || b == 5)
	{
		m->scale[0] = m->scale[0] / ((b == 4) ? 1.5 : 0.9);
		m->scale[1] = m->scale[1] / ((b == 4) ? 1.5 : 0.9);
	}
	n_mid[0] = calc_cor(m, x, 0);
	n_mid[1] = calc_cor(m, WIN_H - y, 1);
	x_mid = (m->xy_mnmx[0] + m->xy_mnmx[1]) / 2;
	y_mid = (m->xy_mnmx[2] + m->xy_mnmx[3]) / 2;
	m->xy_mnmx[0] -= (x_mid - n_mid[0]);
	m->xy_mnmx[1] -= (x_mid - n_mid[0]);
	m->xy_mnmx[2] -= (y_mid - n_mid[1]);
	m->xy_mnmx[3] -= (y_mid - n_mid[1]);
	draw(m);
	return (0);
}

int		key_handler(int k, t_mlx *m)
{
	if (k == 53)
		exit(0);
	else if (k == 4)
		m->hold = !m->hold;
	else if (k == 15)
		setup(m);
	else if (k >= 123 && k <= 126)
		shift(k, m, 0.1);
	else if (k == 69 || k == 78)
		m->mx_i = k == 78 ? m->mx_i - 5 : m->mx_i + 5;
	else if (k == 18 || k == 19 || k == 20 || k == 21 || k == 22 || k == 23)
		m->set_mode = k - 18;
	else if (k == 26)
		m->set_mode = 6;
	else if (k == 8)
		change_color(m);
	draw(m);
	if (k == 34)
		print_instructions(m);
	return (0);
}
