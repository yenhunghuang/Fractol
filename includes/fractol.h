/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yehuang <yehuang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/18 16:33:39 by yehuang           #+#    #+#             */
/*   Updated: 2019/12/20 17:45:52 by yehuang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <stdlib.h>
# include <math.h>
# include <fcntl.h>
# include <unistd.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <stdio.h>
# include <pthread.h>
# include "../minilibx/mlx.h"
# include "../libft/libft.h"

# define WIN_H 800
# define WIN_W 800

typedef struct	s_mlx
{
	void		*mlx;
	void		*win;
	void		*img;
	int			b_p_p;
	int			s_l;
	int			end;
	char		*ad;
	double		scale[2];
	int			set_mode;
	double		init_c[2];
	int			mx_i;
	double		mx_d;
	double		xy_mnmx[4];
	int			color_index;
	const int	*color;
	char		hold;
	int			mouse[2];
}				t_mlx;

void			setup(t_mlx *m);
void			print_instructions(t_mlx *m);
int				mouse_move(int x, int y, t_mlx *m);
int				mouse_handler(int b, int x, int y, t_mlx *m);
int				key_handler(int k, t_mlx *m);
double			calc_cor(t_mlx *m, int cor, int md);
void			draw(t_mlx *m);
void			change_color(t_mlx *m);
void			shift(int k, t_mlx *m, double scale);
int				ship_converge(t_mlx *m, int x, int y);
int				lauren_converge(t_mlx *m, int x, int y);
int				threeman_converge(t_mlx *m, int x, int y);
int				fiveman_converge(t_mlx *m, int x, int y);
void			print_instructions(t_mlx *m);

#endif
