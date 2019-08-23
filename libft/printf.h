#ifndef PRINTF_H
# define PRINTF_H

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>
# include <errno.h>
# include <stdio.h>
# include "libft.h"

typedef struct			s_printf
{
	int			i;
	int			i_prec;
	int			nb_p;
	va_list			ap;
	int			ret;

	char			ltr;
	int			ash;
	int			zero;
	int			sign_neg;
	int			sign_pos;
	int			space;
	int			nb_t;
	int			prec;
	int			h;
	int			l;
	int			L;
	int			nb_zero;
	int			count;
}				t_printf;

int				ft_printf(const char *format, ...);
int				ft_nb_parametre(const char *format);
t_printf			ft_printf_init(t_printf printf);

t_printf			ft_end(const char *f, t_printf p);
int				ft_puissance(int nb, int h);
t_printf			ft_end_second(const char *f, t_printf p);
t_printf			ft_end_third(const char *f, t_printf p);
t_printf			ft_end_four(const char *f, t_printf p);
t_printf			ft_end_bonus(const char *f, t_printf p);
int				ft_para(char c);

t_printf			ft_classe(t_printf p_l);

t_printf			ft_color(t_printf p_l, const char *f);

t_printf			ft_conversion_c(t_printf p_l);
t_printf			ft_conversion_pourc(t_printf p_l);
t_printf			ft_conversion_s(t_printf p_l);
t_printf			ft_cl_print_s(const char *h, t_printf p_l);

t_printf			ft_conversion_d(t_printf p_l);
int				len_nb_long(long h);
void				ft_putnbr_long(long n);
t_printf			ft_cl_print_d(long h, t_printf p_l);
t_printf			ft_cl_print_sh_d(long h, t_printf p_l);
t_printf			ft_cl_print_ch_d(long h, t_printf p_l);
t_printf			ft_cl_print_in_d(long h, t_printf p_l);

t_printf			ft_conversion_u(t_printf p_l);
t_printf			ft_cl_print_in_u(unsigned long h, t_printf p_l);
t_printf			ft_cl_print_sh_u(unsigned long h, t_printf p_l);
t_printf			ft_cl_print_ch_u(unsigned long h, t_printf p_l);
int				len_nb_u_long(unsigned long h);
void				ft_putnbr_u_long(unsigned long n);
t_printf			ft_cl_print_u(unsigned long h, t_printf p_l);

char				*ft_itoa_base_long(unsigned long value, unsigned long base);
t_printf			ft_conversion_o(t_printf p_l);
t_printf			ft_cl_print_in_o(unsigned long h, t_printf p_l);
t_printf			ft_cl_print_sh_o(unsigned long h, t_printf p_l);
t_printf			ft_cl_print_ch_o(unsigned long h, t_printf p_l);
t_printf			ft_cl_print_o(unsigned long h, t_printf p_l);

char				*ft_itoa_base_long_x(unsigned long value, unsigned long base);
t_printf			ft_conversion_x(t_printf p_l);
t_printf			ft_cl_print_in_x(unsigned long h, t_printf p_l);
t_printf			ft_cl_print_sh_x(unsigned long h, t_printf p_l);
t_printf			ft_cl_print_ch_x(unsigned long h, t_printf p_l);
t_printf			ft_cl_print_x(unsigned long h, t_printf p_l);

t_printf			ft_conversion_x_maj(t_printf p_l);
t_printf			ft_cl_print_in_x_m(unsigned long h, t_printf p_l);
t_printf			ft_cl_print_sh_x_m(unsigned long h, t_printf p_l);
t_printf			ft_cl_print_ch_x_m(unsigned long h, t_printf p_l);
t_printf			ft_cl_print_x_m(unsigned long h, t_printf p_l);

t_printf			ft_conversion_b(t_printf p_l);
t_printf			ft_cl_print_in_b(unsigned long h, t_printf p_l);
t_printf			ft_cl_print_sh_b(unsigned long h, t_printf p_l);
t_printf			ft_cl_print_ch_b(unsigned long h, t_printf p_l);
t_printf			ft_cl_print_b(unsigned long h, t_printf p_l);

t_printf			ft_conversion_p(t_printf p_l);
void				ft_print_hex(size_t nb);
int				ft_len_hex(size_t nb);
t_printf			ft_cl_print_p(size_t h, t_printf p_l);

char				*ft_comp_char_l(char *str, int i, long double ent, long double dec);
t_printf			ft_cl_print_f(long double h, t_printf p_l);
long double			ft_simpl(long double dec, int i);
long double			ft_ent_double(long double h, int i);
long double			ft_puissance_do(int i);
int				ft_len_double(long double h);
t_printf			ft_conversion_f(t_printf p_l);
char				*ft_comp_inf(char *str, long double dec, int i);

t_printf			ft_conversion_e(t_printf p_l);
t_printf			ft_cl_print_e(long double h, t_printf p_l);
int				ft_zero_plus(long double h);
int				ft_strlen_e(char *str, int i);
void				ft_putstr_e(char *str, int i, int j);

#endif
