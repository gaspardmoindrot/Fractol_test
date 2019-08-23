#include "../includes/fdf.h"

void	cercle_co(t_ptr ptr, int r, int j, int f)
{
	int x;
	int y;
	int d;
	int col;

	if (ptr.color_on == -1)
		col = 0x0;
	else if (ptr.vector[j].z == ptr.vector[f].z)
		col = 0xAFFFFF - 67 * ptr.vector[j].z;
	else
		col = 0x8FFFFF - 1241 * ptr.vector[j].z;
	x = 0;
	y = r;
	d = 1 - r;
	if (ptr.f_long / 2 + x >= ptr.vector[j].x_c && ptr.f_long / 2 + x - 1 <= ptr.vector[f].x_c)
		mlx_pixel_put(ptr.mlx, ptr.win, ptr.f_long / 2 + x, ptr.f_larg / 5 + y, col);
	if (ptr.f_long / 2 - x >= ptr.vector[j].x_c && ptr.f_long / 2 - x - 1<= ptr.vector[f].x_c)
		mlx_pixel_put(ptr.mlx, ptr.win, ptr.f_long / 2 - x, ptr.f_larg / 5 + y, col);
	if (ptr.f_long / 2 + y >= ptr.vector[j].x_c && ptr.f_long / 2 + y - 1 <= ptr.vector[f].x_c)
		mlx_pixel_put(ptr.mlx, ptr.win, ptr.f_long / 2 + y, ptr.f_larg / 5 + x, col);
	if (ptr.f_long / 2 - y >= ptr.vector[j].x_c && ptr.f_long / 2 - y - 1 <= ptr.vector[f].x_c)
		mlx_pixel_put(ptr.mlx, ptr.win, ptr.f_long / 2 - y, ptr.f_larg / 5 + x, col);
	while (y > x)
	{
		if (d < 0)
			d += 2 * x + 3;
		else
		{
			d += 2 * (x - y) + 5;
			y--;
		}
		x++;
		if (ptr.f_long / 2 + x >= ptr.vector[j].x_c && ptr.f_long / 2 + x - 1 <= ptr.vector[f].x_c)
			mlx_pixel_put(ptr.mlx, ptr.win, ptr.f_long / 2 + x, ptr.f_larg / 5 + y, col);
		if (ptr.f_long / 2 - x >= ptr.vector[j].x_c && ptr.f_long / 2 - x - 1 <= ptr.vector[f].x_c)
			mlx_pixel_put(ptr.mlx, ptr.win, ptr.f_long / 2 - x, ptr.f_larg / 5 + y, col);
		if (ptr.f_long / 2 + y >= ptr.vector[j].x_c && ptr.f_long / 2 + y - 1 <= ptr.vector[f].x_c)
			mlx_pixel_put(ptr.mlx, ptr.win, ptr.f_long / 2 + y, ptr.f_larg / 5 + x, col);
		if (ptr.f_long / 2 - y >= ptr.vector[j].x_c && ptr.f_long / 2 - y - 1 <= ptr.vector[f].x_c)
			mlx_pixel_put(ptr.mlx, ptr.win, ptr.f_long / 2 - y, ptr.f_larg / 5 + x, col);
	}
}

void		ligne_co(t_ptr ptr, int j, int f)
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
	int col;

	if (ptr.color_on == -1)
		col = 0x0;
	else if (ptr.vector[j].z == ptr.vector[f].z)
		col = 0xAFFFFF - 67 * ptr.vector[j].z;
	else
		col = 0x8FFFFF - 1241 * ptr.vector[j].z;
	x = xi;
	y = yi;
	dx = xf - xi;
	dy = yf - yi;
	xinc = ( dx > 0 ) ? 1 : -1;
	yinc = ( dy > 0 ) ? 1 : -1;
	dx = abs(dx);
	dy = abs(dy);
	mlx_pixel_put(ptr.mlx, ptr.win, x, y, col);
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
			mlx_pixel_put(ptr.mlx, ptr.win, x, y, col);
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
			mlx_pixel_put(ptr.mlx, ptr.win, x, y, col);
		}
	}
}

void	print_conique(t_ptr ptr)
{
	int	x;
	int	y;

	y = 0;
	while (y < ptr.y)
	{
		x = 0;
		while (x < ptr.x)
		{
			if (x < ptr.x - 1)
				ligne_co(ptr, y * ptr.x + x, y * ptr.x + x + 1);
			if (y < ptr.y - 1)
				cercle_co(ptr, ptr.vector[y * ptr.x + x].r, y * ptr.x + x, y * ptr.x + x + ptr.x);
			x++;
		}
		y++;
	}
}

t_ptr	have_coord_con(t_ptr ptr)
{
	double	alpha;
	int	x;
	int	y;
	int	r;
	double	a;
	int	b;

	alpha = 3.1416 / (ptr.y - 1);
	y = 0;
	while (y < ptr.y)
	{
		r = 0;
		x = 0;
		while (x < ptr.x)
		{
			a = (-cos(alpha * y) * r) + ptr.f_long / 2;
			b = (int)a;
			ptr.vector[y * ptr.x + ptr.x - 1 - x].x_c = b;
			a = (sin(alpha * y) * r) + ptr.f_larg / 5;
			b = (int)a;
			ptr.vector[y * ptr.x + ptr.x - 1 - x].y_c = b;
			ptr.vector[y * ptr.x + ptr.x - 1 - x].r = r;
			x++;
			r = r + ptr.rayon;
		}
		y++;
	}
	return (ptr);
}
