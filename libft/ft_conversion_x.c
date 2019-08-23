#include "printf.h"

t_printf	ft_conversion_x(t_printf p_l)
{
	if (p_l.l == 1)
		p_l = ft_cl_print_x(va_arg(p_l.ap, unsigned long), p_l);
	else if (p_l.l == 2)
		p_l = ft_cl_print_x((unsigned long)va_arg(p_l.ap, unsigned long long), p_l);
	else if (p_l.h == 1)
		p_l = ft_cl_print_sh_x((unsigned long)va_arg(p_l.ap, unsigned int), p_l);
	else if (p_l.h == 2)
		p_l = ft_cl_print_ch_x((unsigned long)va_arg(p_l.ap, unsigned int), p_l);
	else
		p_l = ft_cl_print_in_x((unsigned long)va_arg(p_l.ap, unsigned int), p_l);
	return (p_l);
}

t_printf	ft_cl_print_in_x(unsigned long h, t_printf p_l)
{
	if (h >= 4294967296)
		h = h % 4294967296;
	return (ft_cl_print_x(h, p_l));
}

t_printf	ft_cl_print_sh_x(unsigned long h, t_printf p_l)
{
	if (h >= 65536)
		h = h % 65536;
	return (ft_cl_print_x(h, p_l));
}

t_printf	ft_cl_print_ch_x(unsigned long h, t_printf p_l)
{
	if (h >= 256)
		h = h % 256;
	return (ft_cl_print_x(h, p_l));
}

t_printf	ft_cl_print_x(unsigned long h, t_printf p_l)
{
	int	len;
	int	i;

	i = 0;
	len = ft_strlen(ft_itoa_base_long_x(h, 16));
	if (p_l.prec == 0 && h == 0 && p_l.nb_t > 0)
		p_l.nb_t++;
	if (p_l.sign_neg > 0)
	{
		if (p_l.ash > 0 && h != 0)
		{
			ft_putstr("0x");
			p_l.ret = p_l.ret + 2;
			i = i + 2;;
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
			ft_putstr(ft_itoa_base_long_x(h, 16));
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
		if (p_l.ash > 0 && h != 0)
		{
			ft_putstr("0x");
			i = i + 2;
			p_l.ret = p_l.ret + 2;
		}
		while ((len + i) < p_l.nb_t)
		{
			ft_putchar('0');
			p_l.ret++;
			len++;
		}
		ft_putstr(ft_itoa_base_long_x(h, 16));
	}
	else
	{
		if (p_l.ash > 0 && h != 0)
			i = i + 2;
		if (p_l.prec != 0 || h != 0)
			p_l.ret = p_l.ret + len;
		if (p_l.prec > len)
		{
			if (p_l.ash > 0 && h != 0)
                        {
                                ft_putstr("0x");
                                p_l.ret = p_l.ret + 2;
                        }
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
			ft_putstr(ft_itoa_base_long_x(h, 16));
		}
		else
		{
			while ((i + len) < p_l.nb_t)
			{
				ft_putchar(' ');
				i++;
				p_l.ret++;
			}
			if (p_l.ash > 0 && h != 0)
			{
				ft_putstr("0x");
				p_l.ret = p_l.ret + 2;
			}
			if (p_l.prec != 0 || h != 0)
				ft_putstr(ft_itoa_base_long_x(h, 16));
		}
	}
	return (p_l);
}
