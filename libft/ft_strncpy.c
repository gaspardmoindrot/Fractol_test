#include "libft.h"

char    *ft_strncpy(char *dest, const char *src, size_t n)
{
    char    *str_dest;

    str_dest = dest;
    while (*src && n > 0)
    {
        *str_dest++ = *src++;
        n--;
    }
    while (n > 0)
    {
        *str_dest++ = '\0';
        n--;
    }
    return (dest);
}
