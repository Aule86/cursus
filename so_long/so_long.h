/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aszamora <aszamora@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 11:58:53 by aszamora          #+#    #+#             */
/*   Updated: 2024/02/13 12:53:39 by aszamora         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <string.h>
# include <errno.h>
# include <limits.h>
# include "minilibx/mlx.h"
# include "get_next_line/get_next_line.h"
# include "printf/ft_printf.h"
# include "libft/libft.h"

typedef struct s_pos
{
	int		x;
	int		y;

}			t_pos;

typedef struct s_map
{
	char	**map;
	int		fd;
	int		width;
	int		height;
	int		player;
	int		exit;
	int		collectables;
	int		x_axis;
	int		y_axis;
	int		counter;
	t_pos	playerpos;

	void	*floor;
	void	*wall;
	void	*goal;
	void	*collectable;
	void	*player1;
	void	*winpointer;
	void	*mlx_pointer;
	void	*pl_exit;

}				t_map;

int			quit_game(t_map *game);
int			read_map(t_map *game, char **argv);
void		check_errors(t_map *game);
void		add_graphics(t_map *game);
void		correct_player(t_map *game);
void		place_textures(t_map *game);
int			controls_working(int command, t_map *game);
int			right_move(t_map *game, int i, int j);
void		correct_player(t_map *game);
void		place_graphics(t_map *game, int height, int width);
void		flood_fill(t_map *map);

#endif
