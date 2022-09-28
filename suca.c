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
	float	MinRe;
	float	MaxRe;
	float	MinIm;
	float	MaxImm;
	float	Re_factor;
	float	Im_factor;
	float	c_im;
	float	c_re;
	float	Z_re;
	float	Z_im;
	float	Z_re2;
	float	Z_im2;
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
}				t_d;

void	my_mlx_pixel_put(t_d *d, int x, int y, int color)
{
	char	*dst;

	dst = d->addr + (y * d->ll + x * (d->btx / 8));
	*(unsigned int *)dst = color;
}

void mandelbrot(t_d *d, t_complex *reim)
{
	while(d->y < HEIGHT)
	{
		reim->c_im = reim->MaxImm - d->y * reim->Im_factor;
		d->x = 0;
		while(d->x < WIDTH)
		{
			reim->c_re = reim->MinRe + d->x * reim->Re_factor;
			reim->Z_re = reim->c_re; 
			reim->Z_im = reim->c_im;
			d->isInside = 1;
			d->n = 0;
			while(d->n < MAX_ITERATIONS)
			{
				reim->Z_re2 = reim->Z_re * reim->Z_re;
				reim->Z_im2 = reim->Z_im * reim->Z_im;
				if(reim->Z_re2 + reim->Z_im2 > 4)
				{
					d->isInside = 0;
					break;
				}
				reim->Z_im = 2 * reim->Z_re * reim->Z_im + reim->c_im;
				reim->Z_re = reim->Z_re2 - reim->Z_im2 + reim->c_re;
				++d->n;
			}
			if(d->isInside) 
				my_mlx_pixel_put(d, d->x, d->y, 0xFFFFFF);
		++d->x;
		}
	++d->y;
	}
	mlx_put_image_to_window(d->mlx_ptr, d->win_ptr, d->img, 0, 0);
}

int mandel_init(t_d *d, t_complex *reim)
{
	d->n = 0;
	d->x = 0;
	d->y = 0;
	reim->MinRe = -2.0;
	reim->MaxRe = 1.0;
	reim->MinIm = -1.2;
	reim->MaxImm = reim->MinIm + (reim->MaxRe - reim->MinRe) * HEIGHT / WIDTH;
	reim->Re_factor = (reim->MaxRe - reim->MinRe) / (WIDTH - 1);
	reim->Im_factor = (reim->MaxImm - reim->MinIm) / (HEIGHT - 1);
	return 0;
}

int	main(void)
{
	t_d	d;
	t_complex reim;

	// mandel_init(&d);
	mandel_init(&d, &reim);
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
	mandelbrot(&d, &reim);
	mlx_put_image_to_window(d.mlx_ptr, d.win_ptr, d.img, 0, 0);
	// mlx_key_hook(d.win_ptr, key_hook, &d);
	// mlx_mouse_hook(d.win_ptr, mouse_hook, &d);
	// mlx_loop_hook(d.mlx_ptr, main_loop, &d);
	// mlx_hook(d.win_ptr, 17, 0, close_window, &d);
	// configure_hook(&d);
	mlx_loop(d.mlx_ptr);
	free(d.mlx_ptr);
}