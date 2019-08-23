#include "printf.h"

t_printf	ft_color(t_printf p_l, const char *f)
{
	if (f[p_l.i + 1] == 'c' && f[p_l.i + 2] == 'y'
                        && f[p_l.i + 3] == 'a' && f[p_l.i + 4] == 'n'
			&& f[p_l.i + 5] == '}')
	{
                ft_putstr("\033[36;01m");
		p_l.i = p_l.i + 5;
	}
        else if (f[p_l.i + 1] == 'b' && f[p_l.i + 2] == 'l'
                        && f[p_l.i + 3] == 'a' && f[p_l.i + 4] == 'k'
			&& f[p_l.i + 5] == '}')
	{
		ft_putstr("\033[30;01m");
		p_l.i = p_l.i + 5;
	}
        else if (f[p_l.i + 1] == 'g' && f[p_l.i + 2] == 'r'
                        && f[p_l.i + 3] == 'e' && f[p_l.i + 4] == 'e'
			&& f[p_l.i + 5] == '}')
	{
		ft_putstr("\033[32;01m");
		p_l.i = p_l.i + 5;
	}
        else if (f[p_l.i + 1] == 'y' && f[p_l.i + 2] == 'e'
                        && f[p_l.i + 3] == 'l' && f[p_l.i + 4] == 'l'
			&& f[p_l.i + 5] == '}')
	{
		ft_putstr("\033[33;01m");
		p_l.i = p_l.i + 5;
	}
        else if (f[p_l.i + 1] == 'b' && f[p_l.i + 2] == 'l'
                        && f[p_l.i + 3] == 'u' && f[p_l.i + 4] == 'e'
			&& f[p_l.i + 5] == '}')
	{
		ft_putstr("\033[34;01m");
		p_l.i = p_l.i + 5;
	}
        else if (f[p_l.i + 1] == 'm' && f[p_l.i + 2] == 'a'
                        && f[p_l.i + 3] == 'g' && f[p_l.i + 4] == 'e'
			&& f[p_l.i + 5] == '}')
	{
		ft_putstr("\033[35;01m");
		p_l.i = p_l.i + 5;
	}
        else if (f[p_l.i + 1] == 'w' && f[p_l.i + 2] == 'h'
                        && f[p_l.i + 3] == 'i' && f[p_l.i + 4] == 't'
			&& f[p_l.i + 5] == '}')
	{
		ft_putstr("\033[37;01m");
		p_l.i = p_l.i + 5;
	}
	else if (f[p_l.i + 1] == 'r' && f[p_l.i + 2] == 'e'
			&& f[p_l.i + 3] == 'd' && f[p_l.i + 4] == '}')
	{
		ft_putstr("\033[31;01m");
		p_l.i = p_l.i + 4;
	}
	else if (f[p_l.i + 1] == 'e' && f[p_l.i + 2] == 'o'
			&& f[p_l.i + 3] == 'c' && f[p_l.i + 4] == '}')
	{
		ft_putstr("\033[0;01m");
		p_l.i = p_l.i + 4;
	}
	else
	{
		p_l.ret++;
		ft_putchar(f[p_l.i]);
	}
	return (p_l);
}
