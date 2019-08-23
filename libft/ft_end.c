#include "printf.h"

t_printf	ft_end_second(const char *f, t_printf p)
{
	while (f[p.i] == '0')
	{
		p.zero++;
		p.i++;
		p.count++;
	}
	while (f[p.i] == '-')
	{
		p.sign_neg++;
		p.i++;
		p.count++;
	}
	while (f[p.i] == '+')
	{
		p.sign_pos++;
		p.i++;
		p.count++;
	}
	while (f[p.i] == ' ')
	{
		p.space++;
		p.i++;
		p.count++;
	}
	while (f[p.i] == '#')
	{
		p.ash++;
		p.i++;
		p.count++;
	}
	return (p);
}

t_printf	ft_end_third(const char *f, t_printf p)
{
	int	h;

	h = 0;
	if (f[p.i] > 48 && f[p.i] < 58)
	{
		p.nb_t = 0;
		while (f[p.i] > 47 && f[p.i] < 58)
			p.i++;
		p.i--;
		while (f[p.i] > 47 && f[p.i] < 58)
		{
			p.nb_t = p.nb_t + (f[p.i] - '0') * (ft_puissance(10, h));
			h++;
			p.i--;
		}
		p.i++;
		while (f[p.i] > 47 && f[p.i] < 58)
			p.i++;
		h = 0;
		p.count++;
	}
	if (f[p.i] == '.')
	{
		p.prec = 0;
		p.i++;
		while (f[p.i] > 47 && f[p.i] < 58)
			p.i++;
		p.i--;
		while (f[p.i] > 47 && f[p.i] < 58)
		{
			p.prec = p.prec + (f[p.i] - '0') * (ft_puissance(10, h));
			h++;
			p.i--;
		}
		p.i++;
		while (f[p.i] > 47 && f[p.i] < 58)
			p.i++;
		p.count++;
	}
	return (p);
}

t_printf	ft_end_four(const char *f, t_printf p)
{
	if (f[p.i] == 'h')
	{
		if (f[p.i] == 'h' && f[p.i + 1] == 'h')
		{
			p.i++;
			p.h = 2;
		}
		else if (f[p.i] == 'h')
			p.h = 1;
		p.i++;
		p.count++;
	}
	else if (f[p.i] == 'l')
	{
		if (f[p.i] == 'l' && f[p.i + 1] == 'l')
		{
			p.i++;
			p.l = 2;
		}
		else if (f[p.i] == 'l')
			p.l = 1;
		p.i++;
		p.count++;
	}
	return (p);
}

t_printf	ft_end_bonus(const char *f, t_printf p)
{
	if (f[p.i] == '*')
	{
		if (f[p.i - 1] != '.')
		{
			p.nb_t = va_arg(p.ap, int);
			if (p.nb_t < 0)
			{
				p.nb_t = -p.nb_t;
				p.sign_neg++;
			}
			p.count++;
			p.i++;
		}
		else
		{
			p.prec = va_arg(p.ap, int);
			if (p.prec < 0)
				p.prec = -1;
			p.count++;
			p.i++;
		}
	}
	return (p);
}

t_printf	ft_end(const char *f, t_printf p)
{
	p.i++;
	p.i_prec = 0;
	while (f[p.i])
	{
		p.count = 0;
		p = ft_end_second(f, p);
		p = ft_end_third(f, p);
		p = ft_end_four(f, p);
		p = ft_end_bonus(f, p);
		if (f[p.i] == 'L')
		{
			p.L = 1;
			p.i++;
			p.count++;
		}
		else if (f[p.i] == 'c' || f[p.i] == 's' || f[p.i] == 'p' || f[p.i] == 'd'
				|| f[p.i] == 'i' || f[p.i] == 'o' || f[p.i] == 'u'
				|| f[p.i] == 'x' || f[p.i] == 'X' || f[p.i] == 'f'
				|| f[p.i] == '%' || f[p.i] == 'b' || f[p.i] == 'e')
		{
			if (f[p.i] == '%' && p.i_prec != 0)
			{
				p.i = p.i_prec;
				return (p);
			}
			p.ltr = f[p.i];
			return (p);
		}
		if (f[p.i] == '\0' || f[p.i + 1] == '\0')
		{
			if (p.i_prec != 0)
				p.i = p.i_prec;
			else if (ft_para(f[p.i]) == 1)
				p.i++;
			break;
		}
		if (p.count == 0)
		{
			if (p.i_prec == 0)
				p.i_prec = p.i;
			p.i++;
		}
	}
	return (p);
}

int		ft_para(char c)
{
	if ((c > 47 && c < 58) || c == '#' || c == '-' || c == '+'
			|| c == ' ' || c == '.' || c == 'h' || c == 'l'
			|| c == 'L')
		return (1);
	return (0);
}

int		ft_puissance(int nb, int h)
{
	int	result;

	result = 1;
	while (h > 0)
	{
		result = result * nb;
		h--;
	}
	return (result);
}
