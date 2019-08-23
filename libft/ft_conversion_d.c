#include "printf.h"

t_printf	ft_conversion_d(t_printf p_l)
{
	if (p_l.l == 1)
		p_l = ft_cl_print_d(va_arg(p_l.ap, long), p_l);
	else if (p_l.l == 2)
		p_l = ft_cl_print_d((long)va_arg(p_l.ap, long long), p_l);
	else if (p_l.h == 1)
		p_l = ft_cl_print_sh_d((long)va_arg(p_l.ap, int), p_l);
	else if (p_l.h == 2)
		p_l = ft_cl_print_ch_d((long)va_arg(p_l.ap, int), p_l);
	else
		p_l = ft_cl_print_in_d((long)va_arg(p_l.ap, int), p_l);
	return (p_l);
}

t_printf	ft_cl_print_in_d(long h, t_printf p_l)
{
	if (h >= 0)
	{
		if (h >= 4294967294)
			h = h % 65536;
		if (h >= 2147483648)
			h = -2147483648 + (-2147483648 + h);
	}
	else
	{
		if (h <= -4294967294)
			h = h % 2147483648;
		if (h < -2147483648)
			h = 2147483648 - (-2147483648 - h);
	}
	return (ft_cl_print_d(h, p_l));
}

t_printf	ft_cl_print_sh_d(long h, t_printf p_l)
{
	if (h >= 0)
	{
		if (h >= 65536)
			h = h % 65536;
		if (h >= 32768)
			h = -32768 + (-32768 + h);
	}
	else
	{
		if (h <= -65536)
			h = h % 65536;
		if (h < -32768)
			h = 32767 - (-32769 - h);
	}
	return (ft_cl_print_d(h, p_l));
}

t_printf	ft_cl_print_ch_d(long h, t_printf p_l)
{
	if (h >= 0)
	{
		if (h >= 256)
			h = h % 256;
		if (h >= 128)
			h = -128 + (-128 + h);
	}
	else
	{
		if (h <= -256)
			h = h % 256;
		if (h < -128)
			h = 127 - (-129 - h);
	}
	return (ft_cl_print_d(h, p_l));
}

int		len_nb_long(long h)
{
	int	count;

	count = 1;
	if (h < 0)
		h = -h;
	while (h > 9)
	{
		h = h / 10;
		count++;
	}
	return (count);
}

void		ft_putnbr_long(long n)
{
	if (n < 0)
		n = -n;
	if (n > 9)
	{
		ft_putnbr_long(n / 10);
		ft_putchar(n % 10 + '0');
	}
	else
		ft_putchar(n + '0');
}

t_printf	ft_cl_print_d(long h, t_printf p_l)
{
	int	i;
	int	len;

	if (h < -9223372036854775807)
		len = 19;
	else
		len = len_nb_long(h);
	i = 0;
	if (p_l.prec == 0 && h == 0 && p_l.nb_t > 0)
		p_l.nb_t++;
	if (p_l.sign_neg > 0)
	{
		if (p_l.sign_pos > 0 && h >= 0)
		{
			ft_putchar('+');
			p_l.ret++;
			i++;
		}
		else if (h < 0)
		{
			ft_putchar('-');
			p_l.ret++;
			i++;
		}
		else if (p_l.space > 0)
		{
			ft_putchar(' ');
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
		if (h < -9223372036854775807)
			ft_putstr("9223372036854775808");
		else if (p_l.prec != 0 || h != 0)
			ft_putnbr_long(h);
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
		if (p_l.sign_pos > 0 && h >= 0)
		{
			ft_putchar('+');
			p_l.ret++;
			i++;
		}
		else if (h < 0)
		{
			ft_putchar('-');
			p_l.ret++;
			i++;
		}
		else if (p_l.space > 0)
		{
			ft_putchar(' ');
			p_l.ret++;
			i++;
		}
		p_l.ret = p_l.ret + len;
		while ((len + i) < p_l.nb_t)
		{
			ft_putchar('0');
			p_l.ret++;
			len++;
		}
		if (h < -9223372036854775807)
			ft_putstr("9223372036854775808");
		else
			ft_putnbr_long(h);
	}
	else
	{
		if (p_l.sign_pos > 0 && h >= 0)
			i++;
		else if (h < 0)
			i++;
		else if (p_l.space > 0)
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
			if (p_l.sign_pos > 0 && h >= 0)
			{
				ft_putchar('+');
				p_l.ret++;
			}
			else if (h < 0)
			{
				ft_putchar('-');
				p_l.ret++;
			}
			else if (p_l.space > 0)
			{
				ft_putchar(' ');
				p_l.ret++;
			}
			while (len < p_l.prec)
			{
				ft_putchar('0');
				p_l.ret++;
				len++;
			}
			if (h < -9223372036854775807)
				ft_putstr("9223372036854775808");
			else
				ft_putnbr_long(h);
		}
		else
		{
			while ((i + len) < p_l.nb_t)
			{
				ft_putchar(' ');
				i++;
				p_l.ret++;
			}
			if (p_l.sign_pos > 0 && h >= 0)
			{
				ft_putchar('+');
				p_l.ret++;
			}
			else if (h < 0)
			{
				ft_putchar('-');
				p_l.ret++;
			}
			else if (p_l.space > 0)
			{
				ft_putchar(' ');
				p_l.ret++;
			}
			if (h < -9223372036854775807)
				ft_putstr("9223372036854775808");
			else if (p_l.prec != 0 || h != 0)
				ft_putnbr_long(h);
		}
	}
	return (p_l);
}
