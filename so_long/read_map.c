/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aszamora <aszamora@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 12:57:45 by aszamora          #+#    #+#             */
/*   Updated: 2023/12/12 11:51:16 by aszamora         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	map_width(char *str)
{
	int	width;

	width = 0;
	while (str[width] != '\0')
		width++;
	if (str[width - 1] == '\n')
		width--;
	return (width);
}

static int	add_line(t_map *game, char *line)
{
	char	**temp;
	int		i;

	if (!line)
		return (0);
	i = 0;
	game->height++;
	temp = (char **)malloc(sizeof(char *) * (game->height + 1));
	temp[game->height] = NULL;
	while (i < game->height - 1)
	{
		temp[i] = game->map[i];
		i++;
	}
	temp[i] = line;
	if (game->map)
		free(game->map);
	game->map = temp;
	return (1);
}

int	read_map(t_map *game, char **argv)
{
	char	*readmap;

	game->fd = open(argv[1], O_RDONLY);
	if (game->fd < 0)
		return (0);
	while (1)
	{
		readmap = get_next_line(game->fd);
		if (!add_line(game, readmap))
			break ;
	}
	close (game->fd);
	game->width = map_width(game->map[0]);
	return (1);
}
