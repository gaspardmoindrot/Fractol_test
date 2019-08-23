#include "printf.h"

int		ft_printf(const char *format, ...)
{
	t_printf	printf_l;

	va_start(printf_l.ap, format);
	printf_l.i = 0;
	printf_l.ret = 0;
	printf_l.nb_p = ft_nb_parametre(format);
	while (format[printf_l.i] != '\0')
	{
		printf_l = ft_printf_init(printf_l);
		if (format[printf_l.i] == '%')
		{
			printf_l = ft_end(format, printf_l);
			if (printf_l.ltr != ' ')
				printf_l = ft_classe(printf_l);
			else
				printf_l.i--;
		}
		else if (format[printf_l.i] == '{')
			printf_l = ft_color(printf_l, format);
		else
		{
			printf_l.ret++;
			ft_putchar(format[printf_l.i]);
		}
		printf_l.i++;
	}
	va_end(printf_l.ap);
	return (printf_l.ret);

}

t_printf	ft_printf_init(t_printf printf)
{
	printf.ltr = ' ';
	printf.ash = 0;
	printf.zero = 0;
	printf.sign_neg = 0;
	printf.sign_pos = 0;
	printf.space = 0;
	printf.nb_t = 0;
	printf.prec = -1;
	printf.h = 0;
	printf.l = 0;
	printf.L = 0;
	return (printf);
}

int		ft_nb_parametre(const char *f)
{
	int	i;
	int	count;

	count = 0;
	i = 0;
	while (f[i])
	{
		if (f[i] == '%')
		{
			i++;
			while (!((f[i] > 64 && f[i] < 91 ) || (f[i] > 96 && f[i] < 123 ) 
						|| f[i] == '%') && f[i] != '\0')
				i++;
			if (f[i] != '%' && f[i] != '\0')
				count++;
		}
		i++;
	}
	return (count);
}
