/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_big.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aszamora <aszamora@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 10:57:00 by aszamora          #+#    #+#             */
/*   Updated: 2024/05/10 12:56:14 by aszamora         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sort_b_till_3(t_stack **stack_a, t_stack **stack_b)
{
	int		i;
	t_stack	*temp;

	while(ft_lstsize(*stack_a) > 3 && !ft_checksorted(*stack_a))
	{
		temp = *stack_a;
		i = ft_rotate_ab(*stack_a, *stack_b);
		while (i >= 0)
		{
			if (i == ft_type_rarb(*stack_a, *stack_b, temp->nbr))
				i = ft_apply_rarb(stack_a, stack_b, temp->nbr, 'a');
			else if (i == ft_type_rrarrb(*stack_a, *stack_b, temp->nbr))
				i = ft_apply_rrarrb(stack_a, stack_b, temp->nbr, 'a');
			else if (i == ft_type_rarrb(*stack_a, *stack_b, temp->nbr))
				i = ft_apply_rarrb(stack_a, stack_b, temp->nbr, 'a');
			else if (i == ft_type_rrarb(*stack_a, *stack_b, temp->nbr))
				i = ft_apply_rrarb(stack_a, stack_b, temp->nbr, 'a');
			else
				temp = temp->next;
		}
	}
}

t_stack	*ft_sort_b(t_stack **stack_a)
{
	t_stack	*stack_b;

	stack_b = NULL;
	if (ft_lstsize(*stack_a) > 3 && !ft_checksorted(*stack_a))
		ft_pb(stack_a, &stack_b, 0);
	if (ft_lstsize(*stack_a) > 3 && !ft_checksorted(*stack_a))
		ft_pb(stack_a, &stack_b, 0);
	if (ft_lstsize(*stack_a) > 3 && !ft_checksorted(*stack_a))
		ft_sort_b_till_3(stack_a, &stack_b);
	if (!ft_checksorted(*stack_a))
		ft_sort_theree(stack_a);
		
	
}
t_stack	**ft_sort_a(t_stack **stack_a, t_stack **stack_b)
{
	int		i;
	t_stack	*temp;

	while (*stack_b)
	{
		temp = *stack_b;
		i = ft_rotate_type_ba(*stack_a, *stack_b);
		while (i >= 0)
		{
			if (i == ft_type_rarb_a(*stack_a, *stack_b, temp->nbr))
				i = ft_apply_rarb(stack_a, stack_b, temp->nbr, 'b');
			else if (i == ft_type_rarrb_a(*stack_a, *stack_b, temp->nbr))
				i = ft_apply_rarrb(stack_a, stack_b, temp->nbr, 'b');
			else if (i == ft_type_rrarrb_a(*stack_a, *stack_b, temp->nbr))
				i = ft_apply_rrarrb(stack_a, stack_b, temp->nbr, 'b');
			else if (i == ft_type_rrarb_a(*stack_a, *stack_b, temp->nbr))
				i = ft_apply_rrarb(stack_a, stack_b, temp->nbr, 'b');
			else
				temp = temp->next;
		}
	}
	return (stack_a);
}

void	ft_sort(t_stack **stack_a)
{
	t_stack	*stack_b;
	int		i;

	stack_b = NULL;
	if (ft_lstsize(*stack_a) == 2)
		ft_sa(stack_a, 0);
	else
	{
		stack_b = ft_sort_b(stack_a);
		stack_a = ft_sort_a(stack_a, &stack_b);
	}
}