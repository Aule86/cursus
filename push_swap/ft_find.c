/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aszamora <aszamora@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 12:46:01 by aszamora          #+#    #+#             */
/*   Updated: 2024/05/30 13:26:20 by aszamora         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//Esta función chequea el index del numero en el stack.
int	ft_find_index(t_stack *a, int nbr)
{
	int	i;

	i = 0;
	while (a->nbr != nbr)
	{	
		i++;
		a = a->next;
	}
	a->index = 0;
	return (i);
}
//Esta función encuentra el lugar correcto del número en stack_b.
// En otras palabras, comprueba qué número de índice obtendrá nbr_push
// después de ser enviado a stack_b.
int	ft_find_place_b(t_stack *stack_b, int nbr_push)
{
	int		i;
	t_stack	*temp;

	i = 1;
	if (nbr_push > stack_b->nbr && nbr_push < ft_lstlast(stack_b)->nbr)
		i = 0;
	else if (nbr_push > ft_max(stack_b) || nbr_push < ft_min(stack_b))
		i = ft_find_index(stack_b, ft_min(stack_b));
	else
	{
		temp = stack_b->next;
		while (stack_b->nbr > nbr_push || temp->nbr < nbr_push)
		{
			stack_b = stack_b->next;
			temp = stack_b->next;
			i++;
		}
	}
	return (i);
}
//Esta función encuentra el lugar correcto del número en stack_a.
// En otras palabras, comprueba qué número de índice obtendrá nbr_push
// después de ser enviado a stack_a.

int	ft_find_place_a(t_stack *stack_a, int nbr_push)
{
	int		i;
	t_stack	*temp;

	i = 1;
	if (nbr_push < stack_a->nbr && nbr_push > ft_lstlast(stack_a)->nbr)
		i = 0;
	else if (nbr_push > ft_max(stack_a) || nbr_push < ft_min(stack_a))
		i = ft_find_index(stack_a, ft_min(stack_a));
	else
	{
		temp = stack_a->next;
		while (stack_a->nbr > nbr_push || temp->nbr < nbr_push)
		{
			stack_a = stack_a->next;
			temp = stack_a->next;
			i++;
		}
	}
	return (i);
}