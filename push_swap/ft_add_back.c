/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_add_back.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aszamora <aszamora@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 12:05:56 by aszamora          #+#    #+#             */
/*   Updated: 2024/05/09 12:55:50 by aszamora         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
