/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aszamora <aszamora@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 11:58:53 by aszamora          #+#    #+#             */
/*   Updated: 2023/12/14 13:41:33 by aszamora         ###   ########.fr       */
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
# include "../mlx/mlx.h"
# include "get_next_line.h"

typedef struct s_map
{
	char	**map;
	int		fd;
	int		width;
	int		height;
	int		colums;
	int		player;
	int		enemies;
	int		exit;
	int		collectables;
	void	*mlx_connection;
	void	*mlx_window;
	void	*winpointer;
	void	*mlx_pointer;

}				t_map;

int				main(int argc, char **argv);
void			*ft_memset(void *b, int c, size_t len);
int				quit_game(t_map *game);
static void		check_walls(t_map *game);
int				read_map(t_map *game, char **argv);
static int		add_line(t_map *game, char *line);
static int		map_width(char *str);
void			check_errors(t_map *game);
void			correct_player(t_map *game);
static void		check_content(t_map *game, int height, int width);
static void		check_walls(t_map *game);
static int		verticalwall(t_map *game);
static int		horizontalwall(t_map *game);

#endif