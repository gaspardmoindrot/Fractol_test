#include "printf.h"

t_printf	ft_conversion_p(t_printf p_l)
{
	p_l = ft_cl_print_p((size_t)va_arg(p_l.ap, void *), p_l);
	return (p_l);
}

void	ft_print_hex(size_t nb)
{
	char	*str;

	str = "0123456789abcdef";
	if (nb >= 16)
		ft_print_hex(nb / 16);
	ft_putchar(str[nb % 16]);
}

int	ft_len_hex(size_t nb)
{
	int	count;

	count = 1;
	while (nb > 15)
	{
		nb = nb / 16;
		count++;
	}
	return (count);
}

t_printf	ft_cl_print_p(size_t h, t_printf p_l)
{
	int	len;
	int	i;

	i = 0;
	if (h != 0 || p_l.prec != 0)
		len = ft_len_hex(h);
	else
		len = 0;
	if (p_l.sign_neg > 0)
	{
		ft_putstr("0x");
		i = i + 2;
		p_l.ret = p_l.ret + 2;
		p_l.ret = p_l.ret + len;
		while (len < p_l.prec)
		{
			ft_putchar('0');
			p_l.ret++;
			len++;
		}
		if (h != 0 || p_l.prec != 0)
			ft_print_hex(h);
		i = i + len;
		while (i < p_l.nb_t)
		{
			ft_putchar(' ');
			p_l.ret++;
			i++;
		}

	}
	else if (p_l.zero > 0 && p_l.prec < 0)
	{
		ft_putstr("0x");
		i = i + 2;
		p_l.ret = p_l.ret + 2;
		while (len + i < p_l.nb_t)
		{
			ft_putchar('0');
			p_l.ret++;
			i++;
		}
		if (h != 0 || p_l.prec != 0)
			ft_print_hex(h);
		p_l.ret = p_l.ret + len;
	}
	else
	{
		i = i + 2;
		p_l.ret = p_l.ret + len;
		if (len < p_l.prec)
			len = p_l.prec;
		while (len + i < p_l.nb_t)
		{
			ft_putchar(' ');
			p_l.ret++;
			i++;
		}
		ft_putstr("0x");
		p_l.ret = p_l.ret + 2;
		if (h != 0 || p_l.prec != 0)
			len = ft_len_hex(h);
		while (len < p_l.prec)
		{
			ft_putchar('0');
			p_l.ret++;
			len++;
		}
		if (h != 0 || p_l.prec != 0)
			ft_print_hex(h);
	}
	return (p_l);
}
