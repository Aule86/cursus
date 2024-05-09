#include "push_swap.h"

void	ft_add_back(t_stack **stack, t_stack *new_stack)
{
	if (!stack)
		return ;
	if (!*stack)
		*stack = new_stack;
	else
		(ft_lstlast(*stack))->next = new_stack;
}