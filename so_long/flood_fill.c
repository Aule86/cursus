/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aszamora <aszamora@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 13:27:04 by aszamora          #+#    #+#             */
/*   Updated: 2024/02/14 11:39:33 by aszamora         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	fill(char **map, t_pos size, t_pos cur, char to_fill)
{
	if (((cur.y < 0 || cur.y > size.y) || (cur.x < 0 || cur.x > size.x))
		|| map[cur.y][cur.x] == '1' || map[cur.y][cur.x] == to_fill)
		return ;
	map[cur.y][cur.x] = 'P';
	fill(map, size, (t_pos){cur.x - 1, cur.y}, to_fill);
	fill(map, size, (t_pos){cur.x + 1, cur.y}, to_fill);
	fill(map, size, (t_pos){cur.x, cur.y - 1}, to_fill);
	fill(map, size, (t_pos){cur.x, cur.y + 1}, to_fill);
}

// Save the position of the character you want

static t_pos	find_char(char **map, char character)
{
	t_pos	position;
	int		x;
	int		y;

	position.x = -1;
	position.y = -1;
	y = 0;
	while (map[y] != NULL)
	{
		x = 0;
		while (map[y][x] != '\0')
		{
			if (map[y][x] == character)
			{
				position.x = x;
				position.y = y;
				return (position);
			}
			x++;
		}
		y++;
	}
	return (position);
}

void	flood_fill(t_map *map)
{
	char	**tmp;
	int		i;

	i = 0;
	tmp = (char **)malloc(sizeof(*map) * (map->height + 1));
	while (i < map->height)
	{
		tmp[i] = ft_strdup(map->map[i]);
		i++;
	}
	tmp[i] = NULL;
	map->playerpos = find_char(map->map, 'P');
	tmp[map->playerpos.y][map->playerpos.x] = '0';
	fill(tmp, (t_pos){map->width - 1, map->height - 1}, map->playerpos, 'P');
	if (find_char(tmp, 'C').x != -1 || find_char(tmp, 'E').x != -1)
	{
		ft_printf("Map is not valid");
		quit_game(map);
	}
}
