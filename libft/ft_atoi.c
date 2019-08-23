#include "libft.h"

long    ft_atoi(const char *str)
{
    long    nb;
    long    sign;

    sign = 1;
    while (*str == ' ' || *str == '\f' || *str == '\n' || *str == '\r' ||
            *str == '\t' || *str == '\v')
        str++;
    if (*str == '-' || *str == '+')
    {
        if (*str == '-')
            sign = -1;
        str++;
    }
    nb = 0;
    while (ft_isdigit((int)*str))
    {
        nb = nb * 10 + *str - '0';
        str++;
    }
    return (sign * nb);
}
