/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mardolin <mardolin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/18 07:35:48 by mardolin          #+#    #+#             */
/*   Updated: 2022/09/21 08:17:33 by mardolin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <stdlib.h>
# include <stdio.h>
# include "mlx/mlx/mlx.h"
# include <unistd.h>
# include <math.h>

# define WIDTH 600
# define HEIGHT 500
# define MAX_ITERATIONS 80

# define MLX_ERROR 1

typedef struct	s_i_point
{
	int	x;
	int	y;
} 				t_i_pnt;

typedef struct	s_f_point
{
	float	x;
	float	y;
} 				t_f_pnt;

typedef struct	s_itr_prms
{
	float	len;
	int		a;
	int		b;
}				t_itr_prms;

typedef struct	s_d 
{
    void		*mlx_ptr;
	void		*win_ptr;
	void		*img;
	char		*addr;
	int			btx;
	int			ll;
	int			en;
	int 		color;
	int			rt;                                                                                   
	int			zoom;
	float		x;
	float 		y;
	t_f_pnt		point1;
	t_itr_prms	params;
}				t_d;

void		tree(t_d *d, t_f_pnt start, t_itr_prms params);
void		my_mlx_pixel_put(t_d *d, int x, int y, int color);
void		draw_line(t_d *d, t_i_pnt *begin, t_i_pnt *end);
void		retrydraw(t_d *d);
int			treeinit(t_d *d);
int			main_loop(t_d *d);
int			close_window(t_d *d);
int			key_hook(int keycode, t_d *d);
int			mouse_hook(int button, int x, int y, t_d *d);
void		color_tree(int cc, t_d *d);
void		clear(t_d *d);
double		real_coordinate(t_d *d, int i, char axis);
void		mandelbr(t_d *d);
int 		mandel_init(t_d *d);
void		square_complex(double *re, double *im);

#endif