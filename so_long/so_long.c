/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tafanasi <tafanasi@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/26 22:26:09 by tafanasi          #+#    #+#             */
/*   Updated: 2025/05/05 03:30:15 by tafanasi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <X11/keysym.h> // For key codes

#define TILE 64 // the size of a tile in pixels

typedef struct s_game {
	void	*mlx;
	void	*win;
	void	*img_wall;
	void	*img_floor;
	void	*img_player;
	void	*img_exit;
	void	*img_collect;
	char	**map;
}	t_game;


void free_game(t_game *game)
{
	if (game->img_wall)
		mlx_destroy_image(game->mlx, game->img_wall);
	if (game->img_floor)
		mlx_destroy_image(game->mlx, game->img_floor);
	if (game->img_player)
		mlx_destroy_image(game->mlx, game->img_player);
	if (game->img_exit)
		mlx_destroy_image(game->mlx, game->img_exit);
	if (game->img_collect)
		mlx_destroy_image(game->mlx, game->img_collect);
	if (game->win)
		mlx_destroy_window(game->mlx, game->win);
	if (game->map)
		free_2d(game->map);
	if (game->mlx)
	{
		mlx_destroy_display(game->mlx);
		free(game->mlx);
	}
	// == game is not allocated in the heap ==
	// if (game)
	// 	free(game);
}

void	load_images(t_game *game)
{
	int	w;
	int	h;
	
	game->img_wall = mlx_xpm_file_to_image(game->mlx, "assets/wall.xpm", &w, &h);
	game->img_floor = mlx_xpm_file_to_image(game->mlx, "assets/floor.xpm", &w, &h);
	game->img_player = mlx_xpm_file_to_image(game->mlx, "assets/player.xpm", &w, &h);
	game->img_exit = mlx_xpm_file_to_image(game->mlx, "assets/exit.xpm", &w, &h);
	game->img_collect = mlx_xpm_file_to_image(game->mlx, "assets/collect.xpm", &w, &h);
}

void	draw_map(t_game *game, int height, int width)
{
	int	i;
	int	j;

	i = 0;
	// floor layer
	while(i < height)
	{
		j = 0;
		while (j < width)
		{
			mlx_put_image_to_window(game->mlx, game->win, game->img_floor, j * TILE, i * TILE);
			j++;
		}
		i++;
	}
	i = 0;
	// walls, exit, coins and player layer
	while (i < height)
	{
		j = 0;
		while (j < width)
		{
			if (game->map[i][j] == '1')
				mlx_put_image_to_window(game->mlx, game->win, game->img_wall, j * TILE, i * TILE);
			else if (game->map[i][j] == '0')
				mlx_put_image_to_window(game->mlx, game->win, game->img_floor, j * TILE, i * TILE);
			else if (game->map[i][j] == 'C')
				mlx_put_image_to_window(game->mlx, game->win, game->img_collect, j * TILE, i * TILE);
			else if (game->map[i][j] == 'E')
				mlx_put_image_to_window(game->mlx, game->win, game->img_exit, j * TILE, i * TILE);
			else if (game->map[i][j] == 'P')
				mlx_put_image_to_window(game->mlx, game->win, game->img_player, j * TILE, i * TILE);
			j++;
		}
		i++;
	}
}

// Function to handle keypress events
int handle_keypress(int keycode, t_game *game)
{
    int player_x = -1;
    int player_y = -1;

    // Find the player's current position
    for (int i = 0; game->map[i]; i++)
    {
        for (int j = 0; game->map[i][j]; j++)
        {
            if (game->map[i][j] == 'P')
            {
                player_x = j;
                player_y = i;
                break;
            }
        }
        if (player_x != -1)
            break;
    }

    if (player_x == -1 || player_y == -1) {
        return (0); // Player not found
    }


	// any movement towards the exit
	if(keycode == XK_Left && game->map[player_y][player_x - 1] == 'E') // Move left
	{
		free_game(game);
		handle_exit(NULL);
		return (0);
	}
	else if (keycode == XK_Right && game->map[player_y][player_x + 1] == 'E') // Move right
	{
		free_game(game);
		handle_exit(NULL);
		return (0);
	}
	else if (keycode == XK_Up && game->map[player_y - 1][player_x] == 'E') // Move up
	{
		free_game(game);
		handle_exit(NULL);
		return (0);
	}
	else if (keycode == XK_Down && game->map[player_y + 1][player_x] == 'E') // Move down
	{
		free_game(game);
		handle_exit(NULL);
		return (0);
	}
	// any movement towards the coins
	if(keycode == XK_Left && game->map[player_y][player_x - 1] == 'C') // Move left
	{
		game->map[player_y][player_x] = '0';
		game->map[player_y][player_x - 1] = 'P';
	}
	else if (keycode == XK_Right && game->map[player_y][player_x + 1] == 'C') // Move right
	{
		game->map[player_y][player_x] = '0';
		game->map[player_y][player_x + 1] = 'P';
	}
	else if (keycode == XK_Up && game->map[player_y - 1][player_x] == 'C') // Move up
	{
		game->map[player_y][player_x] = '0';
		game->map[player_y - 1][player_x] = 'P';
	}
	else if (keycode == XK_Down && game->map[player_y + 1][player_x] == 'C') // Move down
	{
		game->map[player_y][player_x] = '0';
		game->map[player_y + 1][player_x] = 'P';
	}
	
	// Movement keys, avoiding the exit and coins	

	// walls
    if (keycode == XK_Left && game->map[player_y][player_x - 1] != '1') // Move left
    {
        game->map[player_y][player_x] = '0';
        game->map[player_y][player_x - 1] = 'P';
    }
    else if (keycode == XK_Right && game->map[player_y][player_x + 1] != '1') // Move right
    {
        game->map[player_y][player_x] = '0';
        game->map[player_y][player_x + 1] = 'P';
    }
    else if (keycode == XK_Up && game->map[player_y - 1][player_x] != '1') // Move up
    {
        game->map[player_y][player_x] = '0';
        game->map[player_y - 1][player_x] = 'P';
    }
    else if (keycode == XK_Down && game->map[player_y + 1][player_x] != '1') // Move down
    {
        game->map[player_y][player_x] = '0';
        game->map[player_y + 1][player_x] = 'P';
    }
	
	// escape key
	if (keycode == XK_Escape) 
	{
		// todo: free everything
		free_game(game);
		handle_exit(NULL);
		return (0);
	}

    // Redraw the map
    draw_map(game, map_height(game->map), ft_strlen(game->map[0]));

    return (0);
}

int	main(int argc, char **argv)
{
	t_game	game;
	int		width;
	int		height;

	if (argc != 2)
		return (handle_error("Usage: ./so_long <map_file.ber>", 1), 1);

	game.map = get_map(argv[1]);
	height = map_height(game.map);
	width = ft_strlen(game.map[0]);
	if (!game.map || !game.map[0])
		return (handle_error("Invalid map", 1), 1);
	printf("Map dimensions: %d x %d\n", height, width);

	game.mlx = mlx_init();
	if (!game.mlx)
		return (handle_error("mlx_init failed", 1), 1);
	game.win = mlx_new_window(game.mlx, width * TILE, height * TILE, "so_long");

	load_images(&game);
	draw_map(&game, height, width);

	mlx_hook(game.win, 17, 0, handle_exit, NULL); // Close window
	mlx_hook(game.win, 2, 1L << 0, handle_keypress, &game); // KeyPress event
	mlx_loop(game.mlx);
	// free_game(&game);
	return (0);
}
