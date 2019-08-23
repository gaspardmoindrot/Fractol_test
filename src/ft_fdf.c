#include "../includes/fdf.h"

static int	ft_stop(char *str)
{
	ft_putstr(str);
	return (0);
}

static int	ft_error(char *str)
{
	int	fd;
	char	*line;
	int	i;
	int	count;
	int	count_prec;

	count_prec = -1;
	fd = open(str, O_RDONLY);
	if (fd < 0)
		return (1);
	while (get_next_line(fd, &line))
	{
		i = 0;
		count = 0;
		while (line[i] == ' ' || line[i] == '-'
				|| (line[i] > 47 && line[i] < 58))
		{
			if (line[i] == '-' || (line[i] > 47 && line[i] < 58))
			{
				i++;
				while (line[i] > 47 && line[i] < 58)
					i++;
				i--;
				count++;
			}
			i++;
		}
		if ((!(line[i] == ' ' || line[i] == '-' 
						|| (line[i] > 47 && line[i] < 58)))
				&& count == 0)
			return (1);
		if (count_prec != -1 && count_prec != count)
			return (1);
		count_prec = count;
	}
	close(fd);
	return (0);
}

static int	key_over(int key, void *param)
{
	t_ptr	*ptr;

	ptr = (t_ptr *)param;
	if (key == 53)
		exit(EXIT_SUCCESS);
	return (0);
}

static void	fractol_trace(t_ptr ptr, int x, int y)
{
	int	it_max = 50;
	int	c_r = x;
	int	c_i = y;
	double	z_r = 0;
	double	z_i = 0;
	int	i = 0;
	double	tmp;

	while (z_r * z_r + z_i * z_i < 4 && i < it_max)
	{
		tmp = z_r;
		z_r = z_r * z_r - z_i * z_i + c_r;
		z_i = 2 * z_i * tmp + c_i;
		i++;
	}
	if (i == it_max)
	{
		ft_putnbr(x);
		ft_putchar(' ');
		ft_putnbr(y);
		ft_putchar('\n');
		mlx_pixel_put(ptr.mlx, ptr.win, 100 + x, 100 + y, 0xFF0000);
	}
}

static void	fractol_1(t_ptr ptr)
{
	double	calcul;

	double	x;
	double	y;
	double	x1;
	double	y1 = -200;
	double	zoom = 10000000;
	if (zoom == 200)
		x1 = -200;
	else
		x1 = ((zoom - 200) / 100) * 25.01 - 200;
	double	iterations_max = 1500;
	double	image_x, image_y, c_r, c_i, z_r, z_i, i, tmp;
	image_x = 1280;
	image_y = 720;
	x = 0;
	while (x < image_x)
	{
		y = 0;
		while (y < image_y)
		{
			c_r = x / zoom + x1 / zoom;
			c_i = y / zoom + y1 / zoom;
			z_r = 0;
			z_i = 0;
			i = 0;
			while (z_r * z_r + z_i * z_i < 8 && i < iterations_max)
			{
				tmp = z_r;
				z_r = z_r * z_r - z_i * z_i + c_r;
				z_i = 2 * tmp * z_i + c_i;
				i++;
			}
			if (i == iterations_max)
				mlx_pixel_put(ptr.mlx, ptr.win, (int)x, (int)y, 0x0);
			else
				mlx_pixel_put(ptr.mlx, ptr.win, (int)x, (int)y, 16 * 17 * i * 255 / (iterations_max / 4));
			y++;
		}
		x++;
	}
}

static int      key_over2(int button, int x, int y, void *param)
{
        t_ptr   *ptr;

        ptr = (t_ptr *)param;
        return (0);
}

int	hook_mousemove(int x, int y, t_ptr *ptr)
{
	ft_putnbr(x);
	ft_putchar(' ');
	ft_putnbr(y);
	ft_putchar('\n');
}

int	main(int argc, char **argv)
{
	t_ptr	ptr;
	char	*ptr2;
	int	bpp;
	int	stride;
	int	endian;
	int	x;
	int	y;

	y = 0;
	ptr.mlx = mlx_init();
	ptr.win = mlx_new_window(ptr.mlx, 1280, 720, "Fractol");
	ptr.img = mlx_new_image(ptr.mlx, 1200, 720);
	fractol_1(ptr);
	ptr2 = mlx_get_data_addr(ptr.img, &bpp, &stride, &endian);
	ft_putnbr(bpp); // = 32
	ft_putchar(' ');
	ft_putnbr(stride); // = 5120
        ft_putchar(' ');
	ft_putnbr(endian); // = 0
        ft_putchar('\n');
	bpp /= 8;
	while (y < 720)
	{
		x = 0;
		while (x < 1200)
		{
			*(int *)(ptr2 + ((y * 1200 + x) * bpp)) = 0xFF;
			x++;
		}
		y++;
	}
	mlx_pixel_put(ptr.mlx, ptr.win, 100, 100, 0xFFFFFF);
	mlx_pixel_put(ptr.mlx, ptr.win, 200, 200, 0xFFFFFF);
	//mlx_put_image_to_window(ptr.mlx, ptr.win, ptr.img, 0, 0);
	mlx_key_hook(ptr.win, key_over, &ptr);
	mlx_mouse_hook(ptr.win, key_over2, &ptr);
	//mlx_expose_hook(ptr.win, key_over2, &ptr);
	mlx_hook(ptr.win, 6, 0, hook_mousemove, &ptr);
	mlx_loop(ptr.mlx);
	return (0);
}
