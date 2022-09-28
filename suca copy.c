# include <stdlib.h>
# include <stdio.h>
# include <mlx.h>
# include <unistd.h>
# include <math.h>

# define WIDTH 600
# define HEIGHT 500
# define MAX_ITERATIONS 500

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
	double		cre;
	double		cim;
	double		newre;
	double		newim;
	double		oldre;
	double		oldim;
}			t_complex;

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
	int			isInside;
	unsigned	n;
	double		zoom;
}				t_d;

void	my_mlx_pixel_put(t_d *d, int x, int y, int color)
{
	char	*dst;

	dst = d->addr + (y * d->ll + x * (d->btx / 8));
	*(unsigned int *)dst = color;
}

void	julia_init(t_d *d, t_complex *reim)
{
	d->color = 0x006600;
	reim->cre = -0.7;
	reim->cim = 0.27015;
	reim->newre = 0;
	reim->newim = 0;
	reim->oldre = 0;
	reim->oldim = 0;
	julia(d, reim);
}

/*
** number of iterations
*/

int		julia_n(t_complex *reim)
{
	int i;

	i = 0;
	while (i < MAX_ITERATIONS && reim->newre * reim->newre +
		reim->newim * reim->newim < 4)
	{
		reim->oldre = reim->newre;
		reim->oldim = reim->newim;
		reim->newre = reim->oldre * reim->oldre - reim->oldim *
			reim->oldim + reim->cre;
		reim->newim = 2 * reim->oldre * reim->oldim + reim->cim;
		i++;
	}
	return (i);
}

void	julia(t_d *d, t_complex *reim)
{
	d->n = 0;
	d->x = 100;
	d->y = 100;
	mlx_string_put(d->mlx_ptr, d->win_ptr, 500, 40, 0xffffff, "Julia");
	while (d->y < HEIGHT)
	{
		while (d->x < WIDTH)
		{
			reim->newre = 1.5 * (d->x - WIDTH / 2) / (0.3 * d->zoom *
				WIDTH);
			reim->newim = (y - HEIGHT / 2) / (0.3 * d->zoom *
				HEIGHT);
			d->n = julia_n(d);
			if (d->n < MAX_ITERATIONS)
				my_mlx_pixel_put(d->mlx_ptr, d->win_ptr, d->x, d->y,
					(d->color * n / 100));
			d->x++;
		}
		d->y++;
		d->x = 100;
	}
	//mlx_put_image_to_window(d->mlx_ptr, d->win_ptr, d->img, 0, 0);
}

int	main(void)
{
	t_d	d;
	t_complex reim;

	julia_init(&d, &reim);
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
	// mlx_fun();
	julia(&d, &reim);
	mlx_put_image_to_window(d.mlx_ptr, d.win_ptr, d.img, 0, 0);
	// mlx_key_hook(d.win_ptr, key_hook, &d);
	// mlx_mouse_hook(d.win_ptr, mouse_hook, &d);
	// mlx_loop_hook(d.mlx_ptr, main_loop, &d);
	// mlx_hook(d.win_ptr, 17, 0, close_window, &d);
	// configure_hook(&d);
	mlx_loop(d.mlx_ptr);
	free(d.mlx_ptr);
}