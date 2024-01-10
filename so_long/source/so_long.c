/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asier <asier@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 11:01:33 by aszamora          #+#    #+#             */
/*   Updated: 2024/01/10 13:36:24 by asier            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned int	i;
	char			*dest;

	dest = b;
	i = 0;
	while (i < len)
	{
		dest[i] = c;
		i++;
	}
	return (dest);
}

int	quit_game(t_map *game)
{
	int	line;

	line = 0;
	if (game->winpointer)
		mlx_destroy_window(game->mlx_pointer, game->winpointer);
	free(game->mlx_pointer);
	while (line < game->height -1)
		free(game->map[line++]);
	free(game->map);
	exit(0);
}

void	check_errors(t_map *game)
{
	check_walls(game);
	correct_player(game);
}

int	main(int argc, char **argv)
{
	t_map	game;

	if (argc != 2)
		return (0);
	ft_memset(&game, 0, sizeof(t_map));
	read_map(&game, argv);
	check_errors(&game);
	game.mlx_connection = mlx_init();
	game.mlx_window = mlx_new_window(game.mlx_connection, (game.width * 40),
			(game.height * 40), "solong");
	place_textures(&game);
	add_graphics(&game);
}
