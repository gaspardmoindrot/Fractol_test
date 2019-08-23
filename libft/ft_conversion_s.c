#include "printf.h"

t_printf	ft_conversion_s(t_printf p_l)
{
	p_l = ft_cl_print_s(va_arg(p_l.ap, const char*), p_l);
	return (p_l);
}

t_printf	ft_cl_print_s(const char *h, t_printf p_l)
{
	int	i;

	i = 0;
	if (h == NULL)
		return (ft_cl_print_s("(null)", p_l));
	if (p_l.sign_neg > 0)
	{
		if (p_l.prec >= 0)
		{
			while (i < p_l.prec && h[i])
			{
				ft_putchar(h[i]);
				i++;
				p_l.ret++;
			}
		}
		else
		{
			while (h[i])
			{
				ft_putchar(h[i]);
				i++;
				p_l.ret++;
			}
		}
		while (i < p_l.nb_t)
		{
			ft_putchar(' ');
			i++;
			p_l.ret++;
		}
	}
	else if (p_l.zero > 0)
	{
		i = 0;
		if (p_l.prec >= 0 && p_l.prec < (int)ft_strlen(h))
			i = p_l.prec;
		else
			i = (int)ft_strlen(h);
		while (i < p_l.nb_t)
		{
			ft_putchar('0');
			i++;
			p_l.ret++;
		}
		i = 0;
		if (p_l.prec >= 0)
		{
			while (i < p_l.prec && h[i])
			{
				ft_putchar(h[i]);
				i++;
				p_l.ret++;
			}
		}
		else
		{
			while (h[i])
			{
				ft_putchar(h[i]);
				i++;
				p_l.ret++;
			}
		}
	}
	else
	{
		i = 0;
		if (p_l.prec >= 0 && p_l.prec < (int)ft_strlen(h))
			i = p_l.prec;
		else
			i = (int)ft_strlen(h);
		while (i < p_l.nb_t)
		{
			ft_putchar(' ');
			i++;
			p_l.ret++;
		}
		i = 0;
		if (p_l.prec >= 0)
		{
			while (i < p_l.prec && h[i])
			{
				ft_putchar(h[i]);
				i++;
				p_l.ret++;
			}
		}
		else
		{
			while (h[i])
			{
				ft_putchar(h[i]);
				i++;
				p_l.ret++;
			}
		}
	}
	return (p_l);
}
