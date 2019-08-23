#include "libft.h"

char    *ft_strsub(char const *s, unsigned int start, size_t len)
{
    char            *str;
    unsigned int    i;
    
    i = 0;
    if (!s)
        return (NULL);
    str = (char *)ft_memalloc(sizeof(char) * (len + 1));
    if (!str)
        return (NULL);
    while (s[start] != '\0' && len > 0)
    {
        str[i] = s[start];
        i++;
        start++;
        len--;
    }
    return (str);
}
