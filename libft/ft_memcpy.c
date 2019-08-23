#include "libft.h"

void    *ft_memcpy(void *dest, const void *src, size_t n)
{
    unsigned char       *str_dest;
    unsigned char const *str_src;

    str_dest = (unsigned char*)dest;
    str_src = (unsigned char const*)src;

    while (n > 0)
    {
        *str_dest++ = *str_src++;
        n--;
    }
    return (dest);
}
