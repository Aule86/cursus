/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aszamora <aszamora@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 11:39:15 by aszamora          #+#    #+#             */
/*   Updated: 2024/02/12 13:26:46 by aszamora         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/* verificar si hay una pared horizontal compuesta por 1 */
static int	horizontalwall(t_map *game)
{
	int	height;
	int	width;

	height = game->height;
	width = 0;
	while (width < game->width)
	{
		if (!(game->map[0][width] == '1'
			&& game->map[height - 1][width] == '1'))
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
		ft_printf("\nThe map is missing walls\n");
		quit_game(game);
	}
}

void	check_errors(t_map *game)
{
	check_walls(game);
	correct_player(game);
	flood_fill(game);
}
