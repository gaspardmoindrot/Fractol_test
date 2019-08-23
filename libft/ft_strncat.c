#include "libft.h"

char    *ft_strncat(char *dest, const char *src, size_t n)
{
    int i;
    int j;

    i = 0;
    j = 0;
    while (dest[i])
        i++;
    while (src[j] && n > 0)
    {
        dest[i++] = src[j++];
        n--;
    }
    if (n > 0)
        dest[i] = '\0';
    return (dest);
}
