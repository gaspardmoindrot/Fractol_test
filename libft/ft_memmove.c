#include "libft.h"

void    *ft_memmove(void *dest, const void *src, size_t n)
{
    void    *buf;

    if (!(buf = (void *)malloc(n * sizeof(void *))))
        return (NULL);
    ft_memcpy(buf, src, n);
    ft_memcpy(dest, buf, n);
    free(buf);
    return (dest);
}
