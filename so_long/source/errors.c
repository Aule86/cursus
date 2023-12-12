/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aszamora <aszamora@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 11:39:15 by aszamora          #+#    #+#             */
/*   Updated: 2023/12/12 16:04:55 by aszamora         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	walls(t_map *game)
{
	int	cols;
	int	rows;

	cols = verticalwall(game);
	rows = horizontalwall(game);
	if (!cols || !rows)
	{
		printf("\nThe map is missing walls\n");
		//quit_game(game);
	}
}

void	check_errors(t_map *game)
{
	walls(game);
}
