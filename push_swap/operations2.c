/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aszamora <aszamora@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 10:54:22 by aszamora          #+#    #+#             */
/*   Updated: 2024/06/03 10:54:28 by aszamora         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
// rr, ra y rb al mismo tiempo
void	ft_rr(t_stack **a, t_stack **b, int j)
{
	t_stack	*temp;

	if (!*a || !((*a)->next) || !*b || !((*b)->next))
		return ;
	temp = *a;
	*a = ft_lstlast(*a);
	(*a)->next = temp;
	*a = temp->next;
	temp->next = NULL;
	temp = *b;
	*b = ft_lstlast(*b);
	(*b)->next = temp;
	*b = temp->next;
	temp->next = NULL;
	if (j == 0)
		write(1, "rr\n", 3);
}

// pb (push b), el primer elemento de A lo pone el primero de B
// no hace nada si A esta vacio
void	ft_pb(t_stack **stack_a, t_stack **stack_b, int j)
{
	t_stack	*tmp;

	if (!*stack_a)
		return ;
	tmp = *stack_b;
	*stack_b = *stack_a;
	*stack_a = (*stack_a)->next;
	(*stack_b)->next = tmp;
	if (j == 0)
		write(1, "pb\n", 3);
}

// rrb (reverse rotate b) : nueve todos los elemento de B para abajo shift 
// el ultimo elemento se vuelve el primero
void	ft_rrb(t_stack **b, int j)
{
	t_stack	*temp;
	int		i;

	if (!*b || !((*b)->next))
		return ;
	i = 0;
	temp = *b;
	while ((*b)->next)
	{
		i++;
		*b = (*b)->next;
	}
	(*b)->next = temp;
	while (i > 1)
	{
		temp = temp->next;
		i--;
	}
	temp->next = NULL;
	if (j == 0)
		write(1, "rrb\n", 4);
}

// Seegunda parte de la funcion rrr
void	ft_rrr_sub(t_stack **b, int j)
{
	t_stack	*temp;
	int		i;

	i = 0;
	temp = *b;
	while ((*b)->next)
	{
		i++;
		*b = (*b)->next;
	}
	(*b)->next = temp;
	while (i > 1)
	{
		temp = temp->next;
		i--;
	}
	temp->next = NULL;
	if (j == 0)
		write(1, "rrr\n", 4);
}

// rrr : rra y rrb al mismo tiempo
void	ft_rrr(t_stack **a, t_stack **b, int j)
{
	t_stack	*temp;
	int		i;

	if (!*a || !((*a)->next) || !*b || !((*b)->next))
		return ;
	i = 0;
	temp = *a;
	while ((*a)->next)
	{
		i++;
		*a = (*a)->next;
	}
	(*a)->next = temp;
	while (i > 1)
	{
		temp = temp->next;
		i--;
	}
	temp->next = NULL;
	ft_rrr_sub(b, j);
}
