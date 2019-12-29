/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yehuang <yehuang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/31 23:38:28 by xzhu              #+#    #+#             */
/*   Updated: 2019/12/19 23:35:16 by yehuang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

static void	colorset0(t_mlx *m)
{
	const int color[16] = {
		0xffff7d,
		0xffee7d,
		0xffdf7e,
		0xffcf7e,
		0xffbf7e,
		0xffaf7e,
		0xff9f7e,
		0xff8f7f,
		0xfe7e7f,
		0xee6f7f,
		0xde5e7f,
		0xce4f7f,
		0xbe3f7f,
		0xae2f7f,
		0x9d1f7f,
		0x8d0e7f
	};

	m->color = color;
}

static void	colorset1(t_mlx *m)
{
	const int color[16] = {
		65536 * 60 + 256 * 30 + 10,
		65536 * 25 + 256 * 7 + 25,
		65536 * 10 + 256 * 1 + 50,
		65536 * 5 + 256 * 4 + 70,
		65536 * 0 + 256 * 7 + 100,
		65536 * 12 + 256 * 40 + 140,
		65536 * 24 + 256 * 80 + 170,
		65536 * 36 + 256 * 125 + 200,
		65536 * 100 + 256 * 180 + 230,
		65536 * 200 + 256 * 230 + 250,
		65536 * 225 + 256 * 240 + 190,
		65536 * 250 + 256 * 200 + 95,
		65536 * 255 + 256 * 170 + 0,
		65536 * 200 + 256 * 130 + 0,
		65536 * 150 + 256 * 80 + 2,
		65536 * 100 + 256 * 50 + 5
	};

	m->color = color;
}

static void	colorset2(t_mlx *m)
{
	const int color[16] = {
		0xffffff,
		0xdfffff,
		0xbfffff,
		0xa0ffff,
		0x80ffff,
		0x60dfff,
		0x3fbfff,
		0x1f9fff,
		0x7efe,
		0x5edf,
		0x3fbf,
		0x1fa0,
		0x80,
		0x60,
		0x3f,
		0x1f
	};

	m->color = color;
}

static void	colorset3(t_mlx *m)
{
	const int color[16] = {
		0xFF0005,
		0xFD5800,
		0xFCB600,
		0xE3FB00,
		0x85FA00,
		0x27F900,
		0x00F836,
		0x00F791,
		0x01F5EC,
		0x01A2F4,
		0x0147F3,
		0x1501F2,
		0x6E01F1,
		0xC701F0,
		0xEF01BF,
		0xED0166
	};

	m->color = color;
}

void		change_color(t_mlx *m)
{
	m->color_index = (m->color_index) + 1;
	if (m->color_index == 4)
		m->color_index = 0;
	if (m->color_index == 0)
		colorset0(m);
	else if (m->color_index == 1)
		colorset1(m);
	else if (m->color_index == 2)
		colorset2(m);
	else if (m->color_index == 3)
		colorset3(m);
}
