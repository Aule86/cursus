/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   right_move.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aszamora <aszamora@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 14:19:35 by aszamora          #+#    #+#             */
/*   Updated: 2024/02/12 12:45:51 by aszamora         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	right_move(t_map *game, int i, int j)
{
	if (game->map[j][i] == 'E')
	{
		if (game->collectables == 0)
		{
			ft_printf("\nCongratulations, You Win!\n");
			quit_game(game);
		}
		else
		{
			game->map[j][i] = 'I';
			game->x_axis = i;
			game->y_axis = j;
			game->counter++;
		}
	}
	if (game->map[j][i] == '0' || game->map[j][i] == 'C')
	{
		game->map[j][i] = 'P';
		game->x_axis = i;
		game->y_axis = j;
		game->counter++;
	}
	if (game->map[j][i] == 'C')
		game->collectables--;
	return (1);
}
