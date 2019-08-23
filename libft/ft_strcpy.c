#include "libft.h"

char    *ft_strcpy(char *dest, const char *src)
{
    char    *str_dest;

    str_dest = dest;
    while (*src)
        *str_dest++ = *src++;
    *str_dest = '\0';
    return (dest);
}
