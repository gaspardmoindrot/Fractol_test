#include "libft.h"

void    *ft_memalloc(size_t size)
{
    void    *mal;

    mal = malloc(size);
    if (mal == NULL)
        return (NULL);
    else
        return (ft_memset(mal, 0, size));
}
