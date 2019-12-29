/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yehuang <yehuang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/18 16:30:28 by yehuang           #+#    #+#             */
/*   Updated: 2019/12/20 17:11:25 by yehuang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

int			ft_exit(void)
{
	exit(0);
	return (0);
}

static void	check_input(t_mlx *m, int argc, char *arg)
{
	if (argc != 2)
		ft_errorexit(
	"usage: ./fractol <Mandelbrot, Julia, Ship, Tricorn ...>");
	if (!strcmp(arg, "Mandelbrot"))
		m->set_mode = 0;
	else if (!strcmp(arg, "Julia"))
		m->set_mode = 1;
	else if (!strcmp(arg, "Ship"))
		m->set_mode = 2;
	else if (!strcmp(arg, "Tricorn"))
		m->set_mode = 3;
	else if (!strcmp(arg, "Lauren"))
		m->set_mode = 4;
	else if (!strcmp(arg, "Test1"))
		m->set_mode = 5;
	else if (!strcmp(arg, "Test2"))
		m->set_mode = 6;
	else if (!strcmp(arg, "Test3"))
		m->set_mode = 7;
	else
		ft_errorexit(
		"valid set names: Mandelbrot, Julia, Ship, Tricorn ...");
}

int			main(int argc, char **argv)
{
	t_mlx	m;

	check_input(&m, argc, argv[1]);
	m.mlx = mlx_init();
	m.win = mlx_new_window(m.mlx, WIN_W, WIN_H, "fractol");
	m.img = mlx_new_image(m.mlx, WIN_W, WIN_H);
	setup(&m);
	draw(&m);
	print_instructions(&m);
	mlx_key_hook(m.win, key_handler, &m);
	mlx_mouse_hook(m.win, mouse_handler, &m);
	mlx_hook(m.win, 6, 0, mouse_move, &m);
	mlx_hook(m.win, 17, 0, ft_exit, &m);
	mlx_loop(m.mlx);
	return (0);
}
