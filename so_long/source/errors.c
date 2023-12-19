/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aszamora <aszamora@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 11:39:15 by aszamora          #+#    #+#             */
/*   Updated: 2023/12/19 13:02:28 by aszamora         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/* verificar si hay una pared horizontal compuesta por 1 */
static int	horizontalwall(t_map *game)
{
	int	height;
	int	width;

	width = 0;
	height = game->height;
	while (width < game->height)
	{
		if (!(game->map[width][0] == '1'
			&& game->map[width][height -1] == '1'))
			return (0);
		width++;
	}
	return (1);
}

/* verificar si hay una pared vertical compuesta por 1 */
static int	verticalwall(t_map *game)
{
	int	height;
	int	width;

	height = 0;
	width = game->width;
	while (height < game->height)
	{
		if (!(game->map[height][0] == '1'
			&& game->map[height][width -1] == '1'))
			return (0);
		height++;
	}
	return (1);
}

/* verificar si hay columnas y filas correctamente y sino mensaje de error */
static void	check_walls(t_map *game)
{
	int	cols;
	int	rows;

	cols = verticalwall(game);
	rows = horizontalwall(game);
	if (!cols || !rows)
	{
		printf("\nThe map is missing walls\n");
		quit_game(game);
	}
}

/* verificar si el mapa tiene el contenido necesario */
static void	check_content(t_map *game, int height, int width)
{
	if (game->map[height][width] != '1' &&
		game->map[height][width] != '0' &&
		game->map[height][width] != 'P' &&
		game->map[height][width] != 'E' &&
		game->map[height][width] != 'C' &&
		game->map[height][width] != '\n')
	{
		printf("\nError here!%c\n", game->map[height][width]);
		quit_game(game);
	}
	if (game->map[height][width] == 'C')
		game->colums++;
	if (game->map[height][width] == 'P')
		game->player++;
	if (game->map[height][width] == 'E')
		game->exit++;
}

void	correct_player(t_map *game)
{
	int	width;
	int	height;

	height = 0;
	while (height <= game->height)
	{
		width = 0;
		while (width <= game->width)
		{
			check_content(game, height, width);
			width++;
		}
		height++;
	}
}
