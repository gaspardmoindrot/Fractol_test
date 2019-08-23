#include "libft.h"

char    *ft_strstr(const char *meule_de_foin, const char *aiguille)
{
   const char   *str_1;
   const char   *str_2;

   if (*aiguille == '\0')
       return ((char*)meule_de_foin);
   while (*meule_de_foin)
   {
       str_1 = meule_de_foin;
       str_2 = aiguille;
       while (*str_2 && *str_1 == *str_2)
       {
           str_1++;
           str_2++;
       }
       if (*str_2 == '\0')
           return ((char*)meule_de_foin);
       meule_de_foin++;
   }
   return (NULL);
}
