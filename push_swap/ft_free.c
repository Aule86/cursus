#include "push_swap.h"

void	ft_freestr(char **lst)
{
	char	*a;

	if (!lst)
		return ;
	while (*lst)
	{
		a = *lst;
		lst++;
		free(a);
	}
	*lst = NULL;
}

void	ft_free(t_stack **lst)
{
	t_stack	*tmp;

	if (!lst)
		return ;
	while (*lst)
	{
		tmp = (*lst)->next;
		(*lst)->nbr = 0;
		free(*lst);
		*lst = tmp;
	}
}