#include "../includes/fdf.h"

static int	ft_color_p(t_ptr ptr, int zi, int zf)
{
	int	a;
	int	z;
	int	i;

	if (ptr.color_on == 0)
		return (0xFFFFFF);
	if (ptr.color_on == -1)
		return (0x0);
	a = 0xFFFFFF;
	if (zi < 0)
	{
		if (zf < 0)
		{
			if (zf <= zi)
				z = zf;
			else
				z = zi;
		}
		else
		{
			if (-zf <= zi)
				z = zf;
			else
				z = zi;
		}
	}
	else
	{
		if (zf < 0)
		{
			if (-zf > zi)
				z = zf;
			else
				z = zi;
		}
		else
		{
			if (zf > zi)
				z = zf;
			else
				z = zi;
		}
	}
	if (z == 0)
		return (0xAAAAFF);
	else if (z > 0)
	{
		i = ptr.h_max / z;
		if (i < 1)
			i = 1;
		i = 15 / i;
		a = a - i;
		a = a - i * 16;
		a = a - i * 16 * 16;
		a = a - i * 16 * 16 * 16;
	}
	else
	{
		i = ptr.h_min / z;
		if (i < 1)
			i = 1;
		i = 15 / i;
		a = a - i * 16 * 16;
		a = a - i * 16 * 16 * 16;
		a = a - i * 16 * 16 * 16 * 16;
		a = a - i * 16 * 16 * 16 * 16 * 16;
	}
	return (a);
}

void		ligne(t_ptr ptr, int j, int f)
{
	int xi = ptr.vector[j].x_c;
	int yi = ptr.vector[j].y_c;
	int xf = ptr.vector[f].x_c;
	int yf = ptr.vector[f].y_c;
	int dx;
	int dy;
	int i;
	int xinc;
	int yinc;
	int cumul;
	int x;
	int y;

	x = xi;
	y = yi;
	dx = xf - xi;
	dy = yf - yi;
	xinc = ( dx > 0 ) ? 1 : -1;
	yinc = ( dy > 0 ) ? 1 : -1;
	dx = abs(dx);
	dy = abs(dy);
	mlx_pixel_put(ptr.mlx, ptr.win, x, y, ft_color_p(ptr, ptr.vector[j].z, ptr.vector[f].z));
	if (dx > dy)
	{
		cumul = dx / 2;
		for (i = 1 ; i <= dx ; i++)
		{
			x += xinc;
			cumul += dy;
			if (cumul >= dx)
			{
				cumul -= dx;
				y += yinc;
			}
			mlx_pixel_put(ptr.mlx, ptr.win, x, y, ft_color_p(ptr, ptr.vector[j].z, ptr.vector[f].z));
		}
	}
	else
	{
		cumul = dy / 2;
		for (i = 1 ; i <= dy ; i++)
		{
			y += yinc;
			cumul += dx;
			if (cumul >= dy)
			{
				cumul -= dy;
				x += xinc;
			}
			mlx_pixel_put(ptr.mlx, ptr.win, x, y, ft_color_p(ptr, ptr.vector[j].z, ptr.vector[f].z));
		}
	}
}

t_ptr	ft_cherche_coord(t_ptr ptr)
{
	int	t;

	t = 0;
	while (t < ptr.x * ptr.y)
	{
		ptr.vector[t].x_c = (ptr.vector[t].x - ptr.vector[t].y) * (ptr.lon) + ptr.f_long / 2;
		ptr.vector[t].y_c = (ptr.vector[t].x + ptr.vector[t].y) * (ptr.larg) - ptr.haut * ptr.vector[t].z + ptr.f_larg / 5;
		t++;
	}
	return (ptr);
}

void	ft_put_line(t_ptr ptr)
{
	int	x;
	int	y;

	y = 0;
	while (y < ptr.y)
	{
		x = 0;
		while (x < ptr.x)
		{
			if (x != ptr.x - 1)
				ligne(ptr, y * ptr.x + x, y * ptr.x + x + 1);
			if (y != ptr.y - 1)
				ligne(ptr, y * ptr.x + x, y * ptr.x + x + ptr.x);
			x++;
		}
		y++;
	}
}
