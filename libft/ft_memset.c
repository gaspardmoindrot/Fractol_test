#include "libft.h"

void    *ft_memset(void *s, int c, size_t n)
{
    unsigned char   *str;
    int             a;

    str = (unsigned char*)s;
    a = 0;
    while (n > 0)
    {
        str[a] = (unsigned char)c;
        a++;
        n--;
    }
    return (s);
}
