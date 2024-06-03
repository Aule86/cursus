/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cases.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aszamora <aszamora@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 10:53:06 by aszamora          #+#    #+#             */
/*   Updated: 2024/06/03 11:04:34 by aszamora         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_case_rarb(t_stack *a, t_stack *b, int c)
{
	int	i;

	i = ft_find_place_b(b, c);
	if (i < ft_find_index(a, c))
		i = ft_find_index(a, c);
	return (i);
}

int	ft_case_rrarrb(t_stack *a, t_stack *b, int c)
{
	int	i;

	i = 0;
	if (ft_find_place_b(b, c))
		i = ft_lstsize(b) - ft_find_place_b(b, c);
	if ((i < (ft_lstsize(a) - ft_find_index(a, c))) && ft_find_index(a, c))
		i = ft_lstsize(a) - ft_find_index(a, c);
	return (i);
}

int	ft_case_rrarb(t_stack *a, t_stack *b, int c)
{
	int	i;

	i = 0;
	if (ft_find_index(a, c))
		i = ft_lstsize(a) - ft_find_index(a, c);
	i = ft_find_place_b(b, c) + i;
	return (i);
}

int	ft_case_rarrb(t_stack *a, t_stack *b, int c)
{
	int	i;

	i = 0;
	if (ft_find_place_b(b, c))
		i = ft_lstsize(b) - ft_find_place_b(b, c);
	i = ft_find_index(a, c) + i;
	return (i);
}
