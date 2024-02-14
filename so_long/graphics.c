/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphics.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aszamora <aszamora@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 11:20:50 by aszamora          #+#    #+#             */
/*   Updated: 2024/02/13 13:43:51 by aszamora         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	place_player(t_map *game, int height, int width)
{
	mlx_put_image_to_window(game->mlx_pointer,
		game->winpointer, game->player1, width * 40, height * 40);
	game->y_axis = height;
	game->x_axis = width;
}

void	place_collectable(t_map *game, int height, int width)
{
	mlx_put_image_to_window(game->mlx_pointer,
		game->winpointer, game->collectable, width * 40, height * 40);
	game->collectables++;
}

void	place_textures(t_map *game)
{
	int	i;
	int	j;

	game->floor = mlx_xpm_file_to_image(game->mlx_pointer,
			"images/floor.xpm", &i, &j);
	game->wall = mlx_xpm_file_to_image(game->mlx_pointer,
			"images/wall.xpm", &i, &j);
	game->player1 = mlx_xpm_file_to_image(game->mlx_pointer,
			"images/player.xpm", &i, &j);
	game->goal = mlx_xpm_file_to_image(game->mlx_pointer,
			"images/exit.xpm", &i, &j);
	game->collectable = mlx_xpm_file_to_image(game->mlx_pointer,
			"images/item.xpm", &i, &j);
	game->pl_exit = mlx_xpm_file_to_image(game->mlx_pointer,
			"images/player_exit.xpm", &i, &j);
}

void	place_graphics(t_map *game, int height, int width)
{
	if (game->map[height][width] == '1')
		mlx_put_image_to_window(game->mlx_pointer,
			game->winpointer, game->wall, width * 40, height * 40);
	if (game->map[height][width] == 'C')
		place_collectable(game, height, width);
	if (game->map[height][width] == 'P')
	{
		mlx_put_image_to_window(game->mlx_pointer,
			game->winpointer, game->floor, width * 40, height * 40);
		place_player(game, height, width);
	}
	if (game->map[height][width] == 'E')
		mlx_put_image_to_window(game->mlx_pointer,
			game->winpointer, game->goal, width * 40, height * 40);
	if (game->map[height][width] == '0')
		mlx_put_image_to_window(game->mlx_pointer,
			game->winpointer, game->floor, width * 40, height * 40);
	if (game->map[height][width] == 'I')
		mlx_put_image_to_window(game->mlx_pointer,
			game->winpointer, game->pl_exit, width * 40, height * 40);
}

void	add_graphics(t_map *game)
{
	int	height;
	int	width;

	game->collectables = 0;
	height = 0;
	while (height < game->height)
	{
		width = 0;
		while (game->map[height][width])
		{
			place_graphics(game, height, width);
			width++;
		}
		height++;
	}
}
