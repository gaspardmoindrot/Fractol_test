#ifndef FDF_H
# define FDF_H

# include "../libft/libft.h"
# include "mlx.h"
# include <math.h>
# include <stdlib.h>
# include <stdio.h>
# include <string.h>
# include <fcntl.h>

typedef struct		s_vector
{
	int		x;
	int		y;
	int		z;
	int		x_c;
	int		y_c;
	int		r;
}			t_vector;

typedef struct		s_ptr
{
	void		*mlx;
	void		*win;
	void		*img;
	t_vector	*vector;
	int		x;
	int		y;
	int		h_max;
	int		h_min;
	int		lon;
	int		larg;
	int		haut;
	int		f_long;
	int		f_larg;
	int		color_on;
	int		rayon;
	int		iso;
}			t_ptr;

t_ptr			ft_dispach(char *str);
void			ligne(t_ptr ptr, int i, int f);
t_ptr			ft_cherche_coord(t_ptr ptr);
void			ft_put_line(t_ptr ptr);
t_ptr			have_coord_con(t_ptr ptr);
void			print_conique(t_ptr ptr);
void			ligne_co(t_ptr ptr, int j, int f);
void			cercle_co(t_ptr ptr, int r, int j, int f);

#endif
