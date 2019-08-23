#include "printf.h"
#include <float.h>

t_printf        ft_conversion_e(t_printf p_l)
{
	if (p_l.L >= 1)
		p_l = ft_cl_print_e(va_arg(p_l.ap, long double), p_l);
	else
		p_l = ft_cl_print_e((long double)va_arg(p_l.ap, double), p_l);
	return (p_l);
}

int		ft_zero_plus(long double h)
{
	int	i;

	i = 0;
	if (h > 0)
	{
		while (h < 1)
		{
			h = h * 10;
			i++;
		}
	}
	else
	{
		while (h > -1)
		{
			h = h * 10;
			i++;
		}
	}
	return (i);
}

t_printf	ft_cl_print_e(long double h, t_printf p_l)
{
	char		*str;
	int		i;
	int		j;
	long double	ent;
	long double	dec;
	int		long_ent;
	int		r;

	if (p_l.prec > 0)
		i = p_l.prec + 1;
	else if (p_l.prec == 0 && p_l.ash == 0)
		i = 0;
	else if (p_l.prec == 0 && p_l.ash > 0)
		i = 1;
	else
		i = 7;
	i = i + ft_zero_plus(h);
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
	j = ft_len_double(h);
	r = 0;
	if (h > 0)
	{
		while (j > 1)
		{
			str[j] = str[j - 1];
			str[j - 1] = '.';
			j--;
			r++;
		}
		if (h < 1)
		{
			str[0] = str[ft_zero_plus(h) + 1];
			str[ft_zero_plus(h) + 1] = '0';
			j++;
			while (str[ft_zero_plus(h) + j])
			{
				str[j] = str[ft_zero_plus(h) + j];
				str[ft_zero_plus(h) + j] = '0';
				j++;
			}
			r = -ft_zero_plus(h);
		}
	}
	else
	{
		while (j > 2)
		{
			str[j] = str[j - 1];
			str[j - 1] = '.';
			j--;
			r++;
		}
		if (h > -1)
		{
			str[1] = str[ft_zero_plus(h) + 2];
                        str[ft_zero_plus(h) + 2] = '0';
                        j++;
                        while (str[ft_zero_plus(h) + j])
                        {
                                str[j] = str[ft_zero_plus(h) + j];
                                str[ft_zero_plus(h) + j] = '0';
                                j++;
                        }
			r = -ft_zero_plus(h);
		}
	}
	if (p_l.prec > 0)
                i = p_l.prec + 1;
        else if (p_l.prec == 0 && p_l.ash == 0)
                i = 0;
        else if (p_l.prec == 0 && p_l.ash > 0)
                i = 1;
        else
                i = 7;
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
		ft_putstr_e(str, i, r);
		p_l.ret = p_l.ret + ft_strlen_e(str, i);
		while (ft_strlen_e(str, i) + j < p_l.nb_t)
		{
			ft_putchar(' ');
			p_l.ret++;
			j++;
		}
	}
	else if (p_l.zero > 0)
	{
		if (p_l.sign_pos > 0 && h > 0)
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
		while (ft_strlen_e(str, i) + j < p_l.nb_t)
                {
                        ft_putchar('0');
			p_l.ret++;
                        j++;
                }
		p_l.ret = p_l.ret + ft_strlen_e(str, i);
		ft_putstr_e(str, i, r);
	}
	else
	{
		if (p_l.sign_pos > 0 && h > 0)
                        j++;
                else if (p_l.space > 0)
                        j++;
                while (ft_strlen_e(str, i) + j < p_l.nb_t)
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
		p_l.ret = p_l.ret + ft_strlen_e(str, i);
                ft_putstr_e(str, i, r);
	}
	free(str);
	return (p_l);
}

void		ft_putstr_e(char *str, int i, int j)
{
	int	r;

	if (str[0] != '-')
	{
		r = 1;
		ft_putchar(str[0]);
		while (i > 0)
		{
			ft_putchar(str[r]);
			r++;
			i--;
		}
	}
	else
	{
		r = 2;
		ft_putchar(str[0]);
		ft_putchar(str[1]);
		while (i > 0)
		{
			ft_putchar(str[r]);
			r++;
			i--;
		}
	}
	ft_putchar('e');
	if (j >= 0)
	{
		ft_putchar('+');
		if (j < 10)
		{
			ft_putchar('0');
			ft_putnbr(j);
		}
		else
			ft_putnbr(j);
	}
	else
	{
		ft_putchar('-');
		if (j > -10)
		{
			ft_putchar('0');
			ft_putnbr(-j);
		}
		else
			ft_putnbr(-j);
	}
}

int		ft_strlen_e(char *str, int i)
{
	int	count;

	count = 0;
	if (str[0] != '-')
	{
		count++;
		count = count + i;
	}
	else
	{
		count = count + 2;
		count = count + i;
	}
	count = count + 4;
	return (count);
}
