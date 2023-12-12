/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aszamora <aszamora@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 11:01:33 by aszamora          #+#    #+#             */
/*   Updated: 2023/12/12 16:05:08 by aszamora         ###   ########.fr       */
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

/* int	quit_game(t_map *game)
{
	
} */

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
}
