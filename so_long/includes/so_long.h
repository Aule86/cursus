/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aszamora <aszamora@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 11:58:53 by aszamora          #+#    #+#             */
/*   Updated: 2023/12/12 12:27:13 by aszamora         ###   ########.fr       */
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
	int		cols;
	int		rows;
	int		player;
	int		collectables;
	void	*mlx_connection;
	void	*mlx_window;

}				t_map;

int	read_map(t_map *game, char **argv);

#endif