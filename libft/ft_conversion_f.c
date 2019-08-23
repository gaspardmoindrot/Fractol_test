#include "printf.h"
#include <float.h>

t_printf	ft_conversion_f(t_printf p_l)
{
	if (p_l.L >= 1)
		p_l = ft_cl_print_f(va_arg(p_l.ap, long double), p_l);
	else
		p_l = ft_cl_print_f((long double)va_arg(p_l.ap, double), p_l);
	return (p_l);
}

int		ft_len_double(long double h)
{
	int	count;

	count = 1;
	if (h < 0)
	{
		count++;
		h = -h;
	}
	while (h >= 10)
	{
		h = h / 10;
		count++;
	}
	return (count);
}

long double	ft_puissance_do(int i)
{
	long double	h;

	h = 1;
	while (i > 1)
	{
		h = h * 10;
		i--;
	}
	return (h);
}

long double	ft_ent_double(long double h, int i)
{
	long double	end;
	long double	end2;

	end = 0;
	if (h >= 0)
	{
		while (i > 0)
		{
			while (end <= h)
			{
				end = end + ft_puissance_do(i);
				if (end == end2)
					break;
				end2 = end;
			}
			end = end - ft_puissance_do(i);
			i--;
		}
	}
	else
	{
		i--;
		while (i > 0)
		{
			while (end >= h)
			{
				end = end - ft_puissance_do(i);
				if (end == end2)
					break;
				end2 = end;
			}
			end = end + ft_puissance_do(i);
			i--;
		}
	}
	return (end);
}

long double	ft_simpl(long double dec, int i)
{
	long double	l;
	long double	l_2;
	long double	dec_2;

	dec_2 = dec;
	l = 1;
	while (i > 0)
	{
		l = l / 10;
		l_2 = l;
		while (l_2 <= dec_2)
			l_2 = l_2 + l;
		l_2 = l_2 - l;
		dec_2 = dec_2 - l_2;
		i--;
	}
	l = l / 2;
	dec = dec - dec_2;
	if (l < dec_2)
		dec = dec + (l * 2);
	return (dec);
}

char		*ft_comp_inf(char *str, long double dec, int i)
{
	long double	l;
	int		r;
	char		c;

	r = 3;
	l = 1;
	str[i + 2] = '\0';
	str[0] = '-';
	str[1] = '0';
	if (i > 0)
		str[2] = '.';
	while (i - 1 > 0)
	{
		l = l / 10;
		c = '0';
		while (dec >= 0 || (dec < 0 && dec > -0.0000000000000001))
		{
			c++;
			dec = dec - l;
		}
		c--;
		dec = dec + l;
		str[r] = c;
		r++;
		i--;
	}
	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] != '0' && str[i] != '-' && str[i] != '.')
			r = 0;
		i++;
	}
	if (r != 0)
		str[1] = '1';
	return (str);
}

t_printf	ft_cl_print_f(long double h, t_printf p_l)
{
	char		*str;
	int		i;
	int		j;
	long double	ent;
	long double	dec;
	int		long_ent;

	if (p_l.prec > 0)
		i = p_l.prec + 1;
	else if (p_l.prec == 0 && p_l.ash == 0)
		i = 0;
	else if (p_l.prec == 0 && p_l.ash > 0)
		i = 1;
	else
		i = 7;
	if (h != LDBL_MAX && h != LDBL_MIN)
		ent = ft_ent_double(h, ft_len_double(h));
	else if (h == LDBL_MAX)
		ent = LDBL_MAX;
	else
		ent = LDBL_MIN;
	dec = h - ent;
	if (dec < 0)
		dec = -dec;
	dec = ft_simpl(dec, i - 1);
	if (dec >= 1)
	{
		if (ent >= 0)
			ent++;
		else
			ent--;
		dec--;
	}
	long_ent = ft_len_double(h);
	str = (char *)malloc(sizeof(char) * (i + long_ent + 1));
	if (!str)
	{
		str = NULL;
		return (p_l);
	}
	str[i + long_ent] = '\0';
	while (i + long_ent >= 1)
	{
		str[i + long_ent - 1] = '0';
		long_ent--;
	}
	if (i > 0)
		str[ft_len_double(h)] = '.';
	if (h < 0)
		str[0] = '-';
	str = ft_comp_char_l(str, i, ent, dec);
	if (h < 0 && h > -1)
		str = ft_comp_inf(str, dec, i);
	j = 0;
	if (p_l.sign_neg > 0)
	{
		if (p_l.sign_pos > 0 && h > 0)
		{
			ft_putchar('+');
			p_l.ret++;
			j++;
		}
		else if (p_l.space > 0 && h > 0)
		{
			ft_putchar(' ');
			p_l.ret++;
			j++;
		}
		ft_putstr(str);
		p_l.ret = p_l.ret + (int)ft_strlen(str);
		while ((int)ft_strlen(str) + j < p_l.nb_t)
		{
			ft_putchar(' ');
			p_l.ret++;
			j++;
		}
	}
	else if (p_l.zero > 0)
	{
		if (str[0] == '-')
			ft_putchar('-');
		else if (p_l.sign_pos > 0 && h > 0)
                {
                        ft_putchar('+');
			p_l.ret++;
                        j++;
                }
                else if (p_l.space > 0)
                {
                        ft_putchar(' ');
			p_l.ret++;
                        j++;
                }
		while ((int)ft_strlen(str) + j < p_l.nb_t)
                {
                        ft_putchar('0');
			p_l.ret++;
                        j++;
                }
		p_l.ret = p_l.ret + (int)ft_strlen(str);
		if (str[0] != '-')
			ft_putstr(str);
		else
		{
			j = 1;
			while (str[j])
			{
				ft_putchar(str[j]);
				j++;
			}
		}
	}
	else
	{
		if (p_l.sign_pos > 0 && h > 0)
                        j++;
                else if (p_l.space > 0)
                        j++;
                while ((int)ft_strlen(str) + j < p_l.nb_t)
                {
                        ft_putchar(' ');
			p_l.ret++;
                        j++;
                }
		if (p_l.sign_pos > 0 && h > 0)
		{
                        ft_putchar('+');
			p_l.ret++;
		}
                else if (p_l.space > 0 && h > 0)
		{
                        ft_putchar(' ');
			p_l.ret++;
		}
		p_l.ret = p_l.ret + (int)ft_strlen(str);
                ft_putstr(str);
	}
	free(str);
	return (p_l);
}

char		*ft_comp_char_l(char *str, int i, long double ent, long double dec)
{
	long double	l;
	char		c;
	int		i_2;
	int		long_ent;
	int		long_ent2;

	long_ent = ft_len_double(ent);
	i_2 = i;
	l = 1;
	while (long_ent < ft_len_double(ent) + i - 1)
	{
		l = l / 10;
		c = '0';
		while (dec >= 0 || (dec < 0 && dec > -0.0000000000000001))
		{
			c++;
			dec = dec - l;
		}
		c--;
		dec = dec + l;
		str[long_ent + 1] = c;
		long_ent++;
	}
	long_ent = ft_len_double(ent);
	long_ent2 = long_ent;
	i = 0;
	if (ent < 0)
	{
		ent = -ent;
		i++;
		long_ent--;
	}
	while (i < long_ent2)
	{
		l = ft_puissance_do(long_ent);
		c = '0';
		while (ent >= 0)
		{
			c++;
			ent = ent - l;
		}
		c--;
		str[i] = c;
		i++;
		long_ent--;
		ent = ent + l;
	}
	return (str);
}
