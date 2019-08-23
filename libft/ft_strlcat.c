#include "libft.h"

size_t  ft_strlcat(char *dest, const char *src, size_t size)
{
    char		*d;
    const char	*s;
    size_t		n;
    size_t		dlen;

    d = dest;
    s = src;
    n = size;
    while (n-- != 0 && *d != '\0')
        d++;
    dlen = d - dest;
    n = size - dlen;
    if (n == 0)
        return (dlen + ft_strlen(s));
    while (*s != '\0')
    {
        if (n != 1)
        {
            *d++ = *s;
            n--;
        }
        s++;
    }
    *d = '\0';
    return (dlen + (s - src));
}
