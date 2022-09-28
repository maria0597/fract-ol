/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx2.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 21:55:53 by marvin            #+#    #+#             */
/*   Updated: 2022/09/27 21:55:53 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void mlx_fun(void)
{
    t_d	d;
    
    d.mlx_ptr = mlx_init();
	if (d.mlx_ptr == NULL)
		return (MLX_ERROR);
	d.win_ptr = mlx_new_window(d.mlx_ptr, WIDTH, HEIGHT, "Welcome to the jungle");
	d.img = mlx_new_image(d.mlx_ptr, WIDTH, HEIGHT);
	d.addr = mlx_get_data_addr(d.img, &d.btx, &d.ll, &d.en);
	if (d.win_ptr == NULL)
	{
		free(d.win_ptr);
		return (MLX_ERROR);
	}
}