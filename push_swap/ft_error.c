/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aszamora <aszamora@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 12:06:16 by aszamora          #+#    #+#             */
/*   Updated: 2024/06/05 18:16:56 by aszamora         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_error(t_stack *lst, char **err)
{
	int	i;

	i = -1;
	if (err)
	{
		while (err[++i])
			free(err[i]);
		free(err);
	}
	if (lst != NULL)
		ft_free(&lst);
	write(2, "Error\n", 6);
	exit(1);
}
