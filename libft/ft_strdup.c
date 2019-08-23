#include "libft.h"

char    *ft_strdup(const char *s)
{
    char    *str;

    str = (char *)malloc(sizeof(char) * (ft_strlen(s) + 1));
    if (!str)
        return (NULL);
    else
        return (ft_strcpy(str, s));
}
