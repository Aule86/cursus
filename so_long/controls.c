/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controls.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aszamora <aszamora@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 12:22:58 by aszamora          #+#    #+#             */
/*   Updated: 2024/02/12 14:30:43 by aszamora         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	keyboard_w(t_map *game, int movement)
{
	int	i;
	int	j;
	int	k;

	i = game->x_axis;
	j = game->y_axis;
	if (movement == 13)
	{
		j--;
		if (game->map[j][i] == '1')
			return (0);
		k = right_move(game, i, j);
		if (!k)
			return (0);
		if (game->map[j + 1][i] == 'I')
			game->map[j + 1][i] = 'E';
		else
			game->map[j + 1][i] = '0';
	}
	ft_printf("Steps Taken: %i\n", game->counter);
	ft_printf("Collectables Remaining: %i\n", game->collectables);
	return (1);
}

static int	keyboard_s(t_map *game, int movement)
{
	int	i;
	int	j;
	int	k;

	i = game->x_axis;
	j = game->y_axis;
	if (movement == 1)
	{
		j++;
		if (game->map[j][i] == '1')
			return (0);
		k = right_move(game, i, j);
		if (!k)
			return (0);
		if (game->map[j - 1][i] == 'I')
			game->map[j - 1][i] = 'E';
		else
			game->map[j - 1][i] = '0';
	}
	ft_printf("Steps Taken: %i\n", game->counter);
	ft_printf("Collectables Remaining: %i\n", game->collectables);
	return (1);
}

static int	keyboard_d(t_map *game, int movement)
{
	int	i;
	int	j;
	int	k;

	i = game->x_axis;
	j = game->y_axis;
	if (movement == 2)
	{
		i++;
		if (game->map[j][i] == '1')
			return (0);
		k = right_move(game, i, j);
		if (!k)
			return (0);
		if (game->map[j][i - 1] == 'I')
			game->map[j][i - 1] = 'E';
		else
			game->map[j][i - 1] = '0';
	}
	ft_printf("Steps Taken: %i\n", game->counter);
	ft_printf("Collectables Remaining: %i\n", game->collectables);
	return (1);
}

static int	keyboard_a(t_map *game, int movement)
{
	int	i;
	int	j;
	int	k;

	i = game->x_axis;
	j = game->y_axis;
	if (movement == 0)
	{
		i--;
		if (game->map[j][i] == '1')
			return (0);
		k = right_move(game, i, j);
		if (!k)
			return (0);
		if (game->map[j][i + 1] == 'I')
			game->map[j][i + 1] = 'E';
		else
			game->map[j][i + 1] = '0';
	}
	ft_printf("Steps Taken: %i\n", game->counter);
	ft_printf("Collectables Remaining: %i\n", game->collectables);
	return (1);
}

int	controls_working(int command, t_map *game)
{
	int	works;

	if (command == 53)
		quit_game(game);
	if (command == 13)
		works = keyboard_w(game, command);
	if (command == 1)
		works = keyboard_s(game, command);
	if (command == 0)
		works = keyboard_a(game, command);
	if (command == 2)
		works = keyboard_d(game, command);
	if (works)
		add_graphics(game);
	return (1);
}
