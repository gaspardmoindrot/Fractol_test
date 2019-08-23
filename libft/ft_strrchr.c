#include "libft.h"

char    *ft_strrchr(const char *s, int c)
{
    char    *a;

    a = NULL;
    while (*s)
    {
        if (*s == (char)c)
            a = (char *)s;
        s++;
    }
    if (*s == (char)c)
        a = (char *)s;
    return (a);
}
