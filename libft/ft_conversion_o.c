#include "printf.h"

t_printf	ft_conversion_o(t_printf p_l)
{
	if (p_l.l == 1)
		p_l = ft_cl_print_o(va_arg(p_l.ap, unsigned long), p_l);
	else if (p_l.l == 2)
		p_l = ft_cl_print_o((unsigned long)va_arg(p_l.ap, unsigned long long), p_l);
	else if (p_l.h == 1)
		p_l = ft_cl_print_sh_o((unsigned long)va_arg(p_l.ap, unsigned int), p_l);
	else if (p_l.h == 2)
		p_l = ft_cl_print_ch_o((unsigned long)va_arg(p_l.ap, unsigned int), p_l);
	else
		p_l = ft_cl_print_in_o((unsigned long)va_arg(p_l.ap, unsigned int), p_l);
	return (p_l);
}

t_printf	ft_cl_print_in_o(unsigned long h, t_printf p_l)
{
	if (h >= 4294967296)
		h = h % 4294967296;
	return (ft_cl_print_o(h, p_l));
}

t_printf	ft_cl_print_sh_o(unsigned long h, t_printf p_l)
{
	if (h >= 65536)
		h = h % 65536;
	return (ft_cl_print_o(h, p_l));
}

t_printf	ft_cl_print_ch_o(unsigned long h, t_printf p_l)
{
	if (h >= 256)
		h = h % 256;
	return (ft_cl_print_o(h, p_l));
}

t_printf	ft_cl_print_o(unsigned long h, t_printf p_l)
{
	int	len;
	int	i;

	i = 0;
	len = ft_strlen(ft_itoa_base_long(h, 8));
	if (p_l.prec == 0 && h == 0 && p_l.nb_t > 0)
		p_l.nb_t++;
	if (p_l.sign_neg > 0)
	{
		if ((p_l.ash > 0 && h != 0 && p_l.prec < len)
				|| (h == 0 && p_l.ash > 0 && p_l.prec == 0))
		{
			ft_putchar('0');
			p_l.ret++;
			i++;
		}
		if (p_l.prec != 0 || h != 0)
			p_l.ret = p_l.ret + len;
		while (len < p_l.prec)
		{
			ft_putchar('0');
			p_l.ret++;
			len++;
		}
		if (p_l.prec != 0 || h != 0)
			ft_putstr(ft_itoa_base_long(h, 8));
		if (len > p_l.prec)
		{
			while (i + len < p_l.nb_t)
			{
				i++;
				ft_putchar(' ');
				p_l.ret++;
			}
		}
		else
		{
			while (i + p_l.prec < p_l.nb_t)
			{
				i++;
				ft_putchar(' ');
				p_l.ret++;
			}
		}
		return (p_l);
	}
	else if (p_l.zero > 0 && p_l.prec < 0)
	{
		p_l.ret = p_l.ret + len;
		if ((p_l.ash > 0 && h != 0)
				|| (h == 0 && p_l.ash > 0 && p_l.prec == 0))
			i++;
		while ((len + i) < p_l.nb_t)
		{
			ft_putchar('0');
			p_l.ret++;
			len++;
		}
		if ((p_l.ash > 0 && h != 0 && p_l.prec < len)
				|| (h == 0 && p_l.ash > 0 && p_l.prec == 0))
		{
			ft_putchar('0');
			p_l.ret++;
		}
		ft_putstr(ft_itoa_base_long(h, 8));
	}
	else
	{
		if ((p_l.ash > 0 && h != 0 && p_l.prec < len)
				|| (h == 0 && p_l.ash > 0 && p_l.prec == 0))
                        i++;
		if (p_l.prec != 0 || h != 0)
			p_l.ret = p_l.ret + len;
		if (p_l.prec > len)
		{
			while ((i + p_l.prec) < p_l.nb_t)
			{
				ft_putchar(' ');
				i++;
				p_l.ret++;
			}
			while (len < p_l.prec)
			{
				ft_putchar('0');
				p_l.ret++;
				len++;
			}
			if ((p_l.ash > 0 && h != 0 && p_l.prec < len)
					|| (h == 0 && p_l.ash > 0 && p_l.prec == 0))
                	{
                        	ft_putchar('0');
                       		p_l.ret++;
                	}
			ft_putstr(ft_itoa_base_long(h, 8));
		}
		else
		{
			while ((i + len) < p_l.nb_t)
			{
				ft_putchar(' ');
				i++;
				p_l.ret++;
			}
			if ((p_l.ash > 0 && h != 0)
					|| (h == 0 && p_l.ash > 0 && p_l.prec == 0))
                	{
                        	ft_putchar('0');
                        	p_l.ret++;
                	}
			if (p_l.prec != 0 || h != 0)
				ft_putstr(ft_itoa_base_long(h, 8));
		}
	}
	return (p_l);
}
