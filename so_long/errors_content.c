/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors_content.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aszamora <aszamora@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 11:50:11 by aszamora          #+#    #+#             */
/*   Updated: 2024/02/12 13:58:01 by aszamora         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/* verificar si el mapa tiene el contenido necesario */
void	check_content(t_map *game, int height, int width)
{
	if (game->map[height][width] != '1' &&
		game->map[height][width] != '0' &&
		game->map[height][width] != 'P' &&
		game->map[height][width] != 'E' &&
		game->map[height][width] != 'C' &&
		game->map[height][width] != '\n')
	{
		ft_printf("\nError here!%c\n", game->map[height][width]);
		quit_game(game);
	}
	if (game->map[height][width] == 'C')
		game->collectables++;
	if (game->map[height][width] == 'P')
		game->player++;
	if (game->map[height][width] == 'E')
		game->exit++;
}

/* recorrer la altura y anchura del mapa llamando a la función check_content */
void	correct_player(t_map *game)
{
	int	width;
	int	height;

	height = 0;
	while (height < game->height - 1)
	{
		width = 0;
		while (width <= game->width)
		{
			check_content(game, height, width);
			width++;
		}
		height++;
	}
	if (!(game->player == 1 && game->collectables >= 1
			&& game->exit == 1))
	{
		ft_printf("\nError\nSomething is wrong!\n");
		ft_printf("missing player, exit or collectable\n");
		quit_game(game);
	}
}
