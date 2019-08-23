#include "libft.h"

void    *ft_memccpy(void *dest, const void *src, int c, size_t n)
 {
     unsigned const char *str1;
     unsigned char       *str2;

     str1 = (unsigned const char *)src;
     str2 = (unsigned char *)dest;

     while (n > 0)
     {
         *str2++ = *str1;
         if (*str1++ == (unsigned char)c)
             return (dest);
         n--;
     }
     return (NULL);
 }
