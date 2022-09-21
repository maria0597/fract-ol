typedef struct s_param{
	void			*mlx_ptr;
	void			*win_ptr;
	void			*img;
	char			*addr;
	int				bits_per_pixel;
	int				line_length;
	int				endian;
	int				width;
	int				height;
	char			set;
	double			x;
	double			y;
	double			dx;
	double			dy;
	int				lim;
	double			c[2];
	double			color;
}					t_param;

void	init_param(t_param *param, int width, int height)
{
	param->mlx_ptr = NULL;
	param->win_ptr = NULL;
	param->img = NULL;
	param->addr = NULL;
	param->bits_per_pixel = 0;
	param->line_length = 0;
	param->endian = 0;
	param->width = width;
	param->height = height;
	param->set = 'M';
	param->x = 0;
	param->y = 0;
	param->dx = 4;
	param->dy = 4;
	param->lim = 500;
	param->color = 0;
}
​
double	ft_abs(double x)
{
	if (x >= 0)
		return (x);
	return (-x);
}
​
void	square_complex(double *re, double *im)
{
	double	tmp;
​
	tmp = *re;
	*re = (*re) * (*re) - (*im) * (*im);
	*im = 2.0 * (*im) * tmp;
}
​
int	create_trgb(unsigned char t, unsigned char r, \
				unsigned char g, unsigned char b)
{
	return (*(int *)(unsigned char [4]){b, g, r, t});
}

int	mandelbrot_pshyco(double re, double im, double n, double color_type)
{
	double	intensity;
	double	r;
	double	g;
	double	b;
​
	intensity = 255 * pow(1 - n, 6);
	r = intensity;
	g = pow(intensity, 2) / pow(255.0, 1);
	b = pow(intensity, 3) / pow(255.0, 2);
	re = 0;
	im = 0;
	color_type = 0;
	return (create_trgb(0, ft_abs(r), ft_abs(g), ft_abs(b)));
}
​
int	mandelbrot_point_color(double x, double y, int lim, double color_type)
{
	double	im;
	double	re;
	int		n;
​
	n = 0;
	re = x;
	im = y;
	while (n < lim)
	{
		if (re * re + im * im > 4)
			return (julia_pshyco(re, im, (double)n / (double)lim, \
					color_type));
		square_complex(&re, &im);
		re += x;
		im += y;
		n++;
	}
	return (create_trgb(0, 0, 0, 0));
}

double	real_coordinate(t_param *p, int i, char axis)
{
	if (axis == 'x')
		return ((p->x - 0.5 * p->dx) + p->dx * ((double)i / (double)p->width));
	else
		return ((p->y - 0.5 * p->dy) + p->dy * ((double)i / (double)p->height));
}
​
int	is_point_in_set(t_param *p, int i, int j)
{
	double	point[2];
​
	point[0] = real_coordinate(p, i, 'x');
	point[1] = real_coordinate(p, j, 'y');
	if (p->set == 'M')
		return (mandelbrot_point_color(point[0], point[1], p->lim, p->color));
	else if (p->set == 'J')
		return (julia_point_color(point, p->c, p->lim, p->color));
	else if (p->set == 'N')
		return (newton_point_color(point[0], point[1], 100));
	return (0);
}
​
void	draw_fractal(t_param *param)
{
	int	i;
	int	j;
	int	color;
​
	i = 0;
	while (i < param->width)
	{
		j = 0;
		while (j < param->height)
		{
			color = is_point_in_set(param, i, j);
			my_mlx_pixel_put(param, i, j, color);
			j++;
		}
		i++;
	}
}

void	deal_space_key(t_param *p)
{
	if (p->set == 'J')
		change_julia_c(p);
	else
	{
		p->x = 0;
		p->y = 0;
		p->dx = 4;
		p->dy = 4;
	}
	p->color = (p->color + 0.05) * (-1.1);
}
​
int	close_every(void *param)
{
	t_param	*p;
​
	p = (t_param *)param;
	mlx_destroy_window(p->mlx_ptr, p->win_ptr);
	exit (0);
	return (0);
}
​
int	mouse_hook(int button, int x, int y, t_param *p)
{
	if ((button == 1 || button == 4) && p->dx > 0.00001)
	{
		p->dx = p->dx / 1.5;
		p->dy = p->dy / 1.5;
	}
	else if ((button == 2 || button == 5) && p->dx < 10)
	{
		p->dx = p->dx * 1.5;
		p->dy = p->dy * 1.5;
	}
	if (button == 1 || button == 2 || button == 4 || button == 5)
	{
		p->x = real_coordinate(p, x, 'x');
		p->y = real_coordinate(p, y, 'y');
		draw_fractal(p);
		mlx_put_image_to_window(p->mlx_ptr, p->win_ptr, p->img, 0, 0);
	}
	return (0);
}
​
int	deal_key(int key, void *param)
{
	t_param	*p;
​
	p = (t_param *)param;
	if (key == 53 || key == 17)
	{
		mlx_destroy_window(p->mlx_ptr, p->win_ptr);
		exit (0);
	}
	if (key == 49)
		deal_space_key(p);
	if (key == 124)
		p->x += 0.2 * p->dx;
	else if (key == 123)
		p->x -= 0.2 * p->dx;
	else if (key == 126)
		p->y -= 0.2 * p->dy;
	else if (key == 125)
		p->y += 0.2 * p->dy;
	if (key == 124 || key == 125 || key == 126 || key == 123 || key == 49)
	{
		draw_fractal(p);
		mlx_put_image_to_window(p->mlx_ptr, p->win_ptr, p->img, 0, 0);
	}
	return (0);
}