/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tree.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mardolin <mardolin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 18:06:21 by mardolin          #+#    #+#             */
/*   Updated: 2022/09/18 12:04:40 by mardolin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*

A binary fractal tree T(r1,r2,a,b) is specified by four parameters. The first 2 
are the scaling rations r1 & r2, which can take any real values between 0 and 1. 
The last two parameters are the branching angles a and b, which can take any 
real values beetween 0 and 360 degrees. 
Every tree has a trunk, which is closed vertical line segment of unit lenght. 
This trunk splits into two new branches at the top. One branch has length r1 
and form an angle of a with the affine hull of the trunk, and other branch has 
length r2 and form an angle of b with the affine hull of the trunk. Each of 
these two branchs forms the trunk of a subtree splits into two more branches, 
following the same rule. 
So the branch of length r1 splits into one branch that has length r1ˆ2 
and forms an angle of a, with the affine hull of the branch of length r1r2 and 
forms an angle of b with the affine hull of the branch of length r1. The binary 
tree is the object obtained by applying the branching process
ad infinitum.

Useful links:
https://www.math.union.edu/research/fractaltrees/
https://larryriddle.agnesscott.org/ifs/pythagorean/symbinarytreeShape.htm
*/

#include "fractol.h"

void	tree(t_data *data, t_f_pnt start, t_itr_prms params)
{
	t_f_pnt	f_end;
	t_i_pnt	i_end;
	t_i_pnt	i_start;

	i_start.x = start.x;
	i_start.y = start.y;
	if (params.len < 5)
	{
		my_mlx_pixel_put(data, start.x, start.y, 0xFF0000);
		return ;
	}
	f_end.x = start.x + params.len * cos(M_PI * params.a / 180);
	f_end.y = start.y - params.len * sin(M_PI * params.a / 180);
	i_end.x = f_end.x;
	i_end.y = f_end.y;
	draw_line(data, &i_start, &i_end);
	params.len *= 0.75;
	params.a = params.a - params.b;
	tree(data, f_end, params);
	params.b *= -1;
	tree(data, f_end, params);
}

int	treeinit(t_data *data)
{
	data->point1.x = WINDOW_WIDTH / 2;
	data->point1.y = WINDOW_HEIGHT - 60;
	data->color = 0x00FFFF;
	data->params.len = 100;
	data->params.a = 90;
	data->params.b = 30;
	return (0);
}
