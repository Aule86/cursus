/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aszamora <aszamora@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 12:06:46 by aszamora          #+#    #+#             */
/*   Updated: 2024/05/30 14:04:24 by aszamora         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//ra, (rotate a) mueve arriba todos los elementos de A,
// el primer elemento se vuelve el ultimo
void	ft_ra(t_stack **a, int j)
{
	t_stack	*temp;

	if ((!*a || !(*a)->next))
		return ;
	temp = *a;
	*a = ft_lstlast(*a);
	(*a)->next = temp;
	*a = temp->next;
	temp->next = NULL;
	if (j == 0)
		write(1, "ra\n", 3);
}

// sa, intercambia los 2 primeros elementos
// no hace nada si no hay o solo hay 1 elemento
void	ft_sa(t_stack **a, int j)
{
	t_stack	*temp;
	t_stack *temp2;

	if ((!*a || !(*a)->next))
		return ;
	temp = *a;
	*a = (*a)->next;
	temp2 = (*a)->next;
	(*a)->next = temp;
	temp->next = temp2;
	if (j == 0)
	{
		write(1, "sa\n", 3);
	}
}

// pa, (push a) coge el primer elemento de B y lo pone
// en la parte superior de A
void	ft_pa(t_stack **a, t_stack **b, int j)
{
	t_stack	*temp;

	if (!*b)
		return ;
	temp = *a;
	*a = *b;
	*b = (*b)->next;
	(*b)->next = temp;
	if (j == 0)
		write(1, "pa\n", 3);
}

//rra, (reverse rotate a) mueve abajo todos los elemento de A
// el ultimo elemento queda el primero
void	ft_rra(t_stack **a, int j)
{
	printf("ROTO DE ROTAR\n");
	t_stack	*temp;
	int		i;

	if (!*a || !((*a)->next))
		return ;
	i = 0;
	temp = *a;
	while ((*a)->next)
	{
		*a = (*a)->next;
		i++;
	}
	(*a)->next = temp;
	while (i > 1)
	{
		temp = temp->next;
		i--;
	}
	temp->next = NULL;
	if (j == 0)
		write(1, "rra\n", 4);
}

// ss, sa y sb al mismo tiempo
void	ft_ss(t_stack **a, t_stack **b, int j)
{
	t_stack	*temp;

	if (!*a || !((*a)->next) || !*b || !((*b)->next))
		return ;
	temp = *a;
	*a = (*a)->next;
	temp->next = (*a)->next;
	(*a)->next = temp;
	temp = *b;
	*b = (*b)->next;
	temp->next = (*b)->next;
	(*b)->next = temp;
	if (j == 0)
		write(1, "ss\n", 3);
}
