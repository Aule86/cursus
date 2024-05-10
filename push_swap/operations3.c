/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations3.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aszamora <aszamora@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 12:42:28 by aszamora          #+#    #+#             */
/*   Updated: 2024/05/10 10:51:39 by aszamora         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// rb, (rotate b) mueve arriba todos los elementos del stack B 1 vez
// el primer elemento se pasa a ser el ultimo.
void	ft_rb(t_stack **b, int j)
{
    t_stack	*temp;

	if ((!*b || !(*b)->next))
		return ;
	temp = *b;
	*b = ft_lstlast(*b);
	(*b)->next = temp;
	*b = temp->next;
	temp->next = NULL;
    if (j == 0)
		write(1, "rb\n", 3);
}

// sb, (swap b) intercambia los 2 primeros elementos del stack B
// no hace nada si solo hay 1 o ningun elemento
void	ft_sb(t_stack **b, int j)
{
	t_stack	*temp;

	if (!b || !((*b)->next))
		return ;
	temp = *b;
	*b = (*b)->next;
	temp->next = (*b)->next;
	(*b)->next = temp;
	if (j == 0)
		write(1, "sb\n", 3);
}