/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mardolin <mardolin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/18 07:35:48 by mardolin          #+#    #+#             */
/*   Updated: 2022/10/05 17:42:19 by mardolin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
They call us
fractals.		They call us
				monsters.
				We're young,
a rather new		
				mathematical idea.	
They thought us
				freaks,
useless discoveries.		
				Now mathematicians
know to the contrary.			
Fractals are		
				the geometry of
				nature.
Snowflakes,
ferns,		
				trees	
clouds,			dragons.	
You name it		
				we can describe it.	
We're fractals-
geometric.		We're fractals-
				random.	
No matter how	No matter how
small			strange

details remains the same.		
we can formulate it.	

Fractals
can paint
the universe.	

*/

#ifndef FRACTOL_H
# define FRACTOL_H

# include <stdlib.h>
# include <stdio.h>
# include "mlx/mlx/mlx.h"
# include <unistd.h>
# include <math.h>

# define WIDTH 500
# define HEIGHT 500
# define MAX_ITERATIONS 80
# define TITLE "Welcome to the Jungle"

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
	int			fractol;
	float		x;
	float 		y;
	float		movex;
	float 		movey;
	float		move;
	int			n;
	int			god;
	float		dx;
	float		dy;
	float		zoom;
	int			fractal;
	int			isInside;
	t_f_pnt		point1;
	t_itr_prms	params;
	t_complex	reim;
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
int				julia_n(t_d *d);
int 			mandel_n(t_d *d);
void			julia(t_d *d);
int				mlx_fun(t_d *d);
void			ft_putchar(char c);
int				julia_init(t_d *d);
void			mandelbrot(t_d *d);
int				mandel_init(t_d *d);
void			ft_putendl(char const *s);
int				ft_strcmp(char *s1, char *s2);
int				fract_select(int argc, char **argv, t_d *d);
void			ft_move(t_d *d, double distance, char direction);
void			ft_zoom(t_d *d);
void			mandel(t_d *d);
void			get_julia_starting_values(t_d *d, int argc, char **argv);
float			ft_atof(char *str);
int				skip(char *str, int *neg);
int				ft_isspace(int c);
int				ft_isdigit(int c);
char			*ft_strchr(const char *s, int c);
void			handle_args(t_d *d, int argc, char **argv);
void			whichfractol(t_d *d);
int				zoom_hook(int keycode, t_d *d);

#endif