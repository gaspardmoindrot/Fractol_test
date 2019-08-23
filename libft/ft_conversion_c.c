#include "printf.h"

t_printf	ft_conversion_c(t_printf p_l)
{
	if (p_l.sign_neg > 0)
	{
		ft_putchar(va_arg(p_l.ap, int));
		if (p_l.nb_t > 0)
                        p_l.ret = p_l.ret + p_l.nb_t;
                else
                        p_l.ret++;
		while (p_l.nb_t > 1)
		{
			ft_putchar(' ');
			p_l.nb_t--;
		}
	}
	else if (p_l.zero > 0)
	{
		if (p_l.nb_t > 0)
                        p_l.ret = p_l.ret + p_l.nb_t;
                else
                        p_l.ret++;
		while (p_l.nb_t > 1)
		{
			ft_putchar('0');
			p_l.nb_t--;
		}
		ft_putchar(va_arg(p_l.ap, int));
	}
	else
	{
		if (p_l.nb_t > 0)
                        p_l.ret = p_l.ret + p_l.nb_t;
                else
                        p_l.ret++;
		while (p_l.nb_t > 1)
		{
			ft_putchar(' ');
			p_l.nb_t--;
		}
		ft_putchar(va_arg(p_l.ap, int));
	}
	return (p_l);
}
