#include "libft.h"

void    ft_lstadd(t_list **alst, t_list *news)
{
    if (alst && news)
	{
		news->next = *alst;
		*alst = news;
	}
}
