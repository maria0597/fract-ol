/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mardolin <mardolin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/18 07:35:48 by mardolin          #+#    #+#             */
/*   Updated: 2022/09/29 18:33:54 by mardolin         ###   ########.fr       */
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
# define MAX_ITERATIONS 50
# define TITLE "Welcome to the Jungle"

# define MLX_ERROR 1

typedef struct s_color
{
	unsigned char	chan[3];
}							t_c;

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

/*
	Take z being a complex number:
		z = a + b*i
	
	Note:
		i = sqrt(-1)
		i * i = -1
	
	Useful link: https://acko.net/blog/how-to-fold-a-julia-fractal/

	a	: the real part of the complex number, moving on the x axis (Re)
	b	: the imaginary part (Im) of the complex number, moving on the y axis (Im)
*/
typedef struct s_complex
{
	float		cre;
	float		cim;
	float		newre;
	float		newim;
	float		oldre;
	float		oldim;
	float		MinRe;
	float		MaxRe;
	float		MinIm;
	float		MaxImm;
	float		Re_factor;
	float		Im_factor;
	float		c_im;
	float		c_re;
	float		Z_re;
	float		Z_im;
	float		Z_re2;
	float		Z_im2;
}			t_complex;

typedef struct	s_itr_prms
{
	float	len;
	int		a;
	int		b;
	int		row;
	int		col;
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
	float		x;
	float 		y;
	int			n;
	float		zoom;
	float		movex;
	float		movey;
	int			isInside;
	t_f_pnt		point1;
	t_itr_prms	params;
}				t_d;

void			tree(t_d *d, t_f_pnt start, t_itr_prms params);
void			my_mlx_pixel_put(t_d *d, int x, int y, int color);
void			draw_line(t_d *d, t_i_pnt *begin, t_i_pnt *end);
void			retrydraw(t_d *d);
int				treeinit(t_d *d);
int				main_loop(t_d *d);
int				close_window(t_d *d);
int				key_hook(int keycode, t_d *d);
int				mouse_hook(int button, int x, int y, t_d *d);
void			color_tree(int cc, t_d *d);
void			clear(t_d *d);
void 			configure_hook(t_d *d);
//double		real_coordinate(t_d *d, int i, char axis);
//int 			mandel_init(t_d *d);
//void			mlx_fun(void);
//void			square_complex(double *re, double *im);
int				julia_n(t_complex *reim);
void			julia(t_d *d, t_complex *reim);
void			julia_init(t_d *d, t_complex *reim);
void			mandelbrot(t_d *d, t_complex *reim);
int				mandel_init(t_d *d, t_complex *reim);
unsigned int	colormagic(int i, double x, double y);

#endif