/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mardolin <mardolin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/18 07:35:48 by mardolin          #+#    #+#             */
/*   Updated: 2022/09/19 22:04:52 by mardolin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <stdlib.h>
# include <stdio.h>
# include "mlx/mlx/mlx.h"
# include <unistd.h>
# include <math.h>

# define WINDOW_WIDTH 600
# define WINDOW_HEIGHT 500

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

typedef struct	s_data 
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
	t_f_pnt		point1;
	t_itr_prms	params;
}				t_data;

void		tree(t_data *data, t_f_pnt start, t_itr_prms params);
void		my_mlx_pixel_put(t_data *data, int x, int y, int color);
void		draw_line(t_data *data, t_i_pnt *begin, t_i_pnt *end);
void		retrydraw(t_data *data);
int			treeinit(t_data *data);
int			main_loop(t_data *data);
int			close_window(t_data *data);
int			key_hook(int keycode, t_data *data);
int			mouse_hook(int button, int x, int y, t_data *data);
void		color_tree(int cc, t_data *data);
void		clear(t_data *data);

#endif