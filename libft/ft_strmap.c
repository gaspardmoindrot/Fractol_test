#include "libft.h"

char    *ft_strmap(char const *s, char (*f)(char))
{
    size_t	n;
    char	*str;
    int		i;

    if (s == NULL || f == NULL)
        return (NULL);
    n = ft_strlen(s);
    str = malloc((n + 1) * sizeof(char));
    if (str == NULL)
        return (NULL);
    i = 0;
    str[n] = '\0';
    while (s[i] != '\0')
    {
        str[i] = (*f)(s[i]);
        i++;
    }
    return (str);
}
