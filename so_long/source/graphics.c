

#include "so_long.h"

void    place_textures(t_map *game)
{
    int i;
    int j;

    game->floor = mlx_xpm_file_to_image(game->mlxpointer,
                    "game_image/floor.xpm", &i, &j);
    game->wall = mlx_xpm_file_to_image(game->mlxpointer,
                    "game_image/wall.xpm", &i, &j);
    game->player1 = mlx_xpm_file_to_image(game->mlxpointer,
                    "game_image/player.xpm", &i, &j);
    game->exit = mlx_xpm_file_to_image(game->mlxpointer,
                    "game_image/exit.xpm", &i, &j);
    game->collectable = mlx_xpm_file_to_image(game->mlxpointer,
                    "game_image/item.xpm", &i, &j);
}

void    add_graphics(t_map *game)
{
    int height;
    int width;

    game->collectables = 0;
    height = 0;
    while (height < game->height)
    {
        width = 0;
        while (game->map[height][width])
        {
            if (game->map[height][width] == '1')
                mlx_put_image_to_window(game->mlxpointer,
                            game->winpointer, game->wall, width * 40, height *40);
            if (game->map[height][width] == 'C')
                place_collectable(game, height, width);
            if (game->map[height][width] == 'P')
                place_collectable(game, height, width);
            if (game->map[height][width] == 'E')
                mlx_put_image_to_window(game->mlxpointer,
                            game->winpointer, game->exit, width * 40, height * 40);
            if (game->map[height][width] == '0')
                mlx_put_image_to_window(game->mlxpointer,
                            game->winpointer, game->floor, width * 40, height *40);
            width++;

        }
        height++;
    }
}