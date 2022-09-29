/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Tree.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mardolin <mardolin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 18:06:21 by mardolin          #+#    #+#             */
/*   Updated: 2022/09/29 17:29:39 by mardolin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
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
forms an angle of b with the affine hull of the branch of length r1. 
The binary tree is the object obtained by applying the branching process
ad infinitum.

Useful links:
https://www.math.union.edu/research/fractaltrees/
https://larryriddle.agnesscott.org/ifs/pythagorean/symbinarytreeShape.htm
*/
void	tree(t_d *d, t_f_pnt start, t_itr_prms params)
{
	t_f_pnt	f_end;
	t_i_pnt	i_end;
	t_i_pnt	i_start;

	i_start.x = start.x;
	i_start.y = start.y;
	if (params.len < 10)
	{
		my_mlx_pixel_put(d, start.x, start.y, 0x0000FF);
		return ;
	}
	color_tree(params.len, d);
	f_end.x = start.x + params.len * cos(M_PI * params.a / 180);
	f_end.y = start.y - params.len * sin(M_PI * params.a / 180);
	i_end.x = f_end.x;
	i_end.y = f_end.y;
	draw_line(d, &i_start, &i_end);
	params.len *= 0.75;
	params.a = params.a - params.b;
	tree(d, f_end, params);
	params.b *= -1;
	tree(d, f_end, params);
}


void	color_tree(int cc, t_d *d)
{
	if (cc == 20)
		d->color = 0x00b8b2;
	else if (cc == 19)
		d->color = (0x00b89e);
	else if (cc == 18)
		d->color = (0x76b874);
	else if (cc == 17)
		d->color = (0xa0b85e);
	else if (cc == 16)
		d->color = (0xc6b644);
	else if (cc == 15)
		d->color = (0xfeb500);
	else if (cc == 14)
		d->color = (0xff8c00);
	else if (cc == 13)
		d->color = (0xfb7700);
	else if (cc == 12)
		d->color = (0xec4e02);
	else if (cc == 11)
		d->color = (0xFC0909);
	else if (cc == 10)
		d->color = (0xdf210b);
}
