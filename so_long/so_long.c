/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tafanasi <tafanasi@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/26 22:26:09 by tafanasi          #+#    #+#             */
/*   Updated: 2025/04/27 00:54:41 by tafanasi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

#define TILE 32 // the size of a tile in pixels

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


void	load_images(t_game *game)
{
	int	w;
	int	h;
	
	game->img_wall = mlx_xpm_file_to_image(game->mlx, "wall.xpm", &w, &h);
	game->img_floor = mlx_xpm_file_to_image(game->mlx, "floor.xpm", &w, &h);
	// game->img_player = mlx_xpm_file_to_image(game->mlx, "player.xpm", &w, &h);
	// game->img_exit = mlx_xpm_file_to_image(game->mlx, "exit.xpm", &w, &h);
	// game->img_collect = mlx_xpm_file_to_image(game->mlx, "collect.xpm", &w, &h);
}

void	draw_map(t_game *game, int height, int width)
{
	int	i;
	int	j;

	i = 0;
	while (i < height)
	{
		j = 0;
		while (j < width)
		{
			if (game->map[i][j] == '1'){
				printf("drawing wall at %d %d\n", j, i);
				mlx_put_image_to_window(game->mlx, game->win, game->img_wall, j * TILE, i * TILE);

			}
			else if (game->map[i][j] == '0'){
				printf("drawing floor at %d %d\n", j, i);
				mlx_put_image_to_window(game->mlx, game->win, game->img_floor, j * TILE, i * TILE);
			}
			// else if (game->map[i][j] == 'C')
			// 	mlx_put_image_to_window(game->mlx, game->win, game->img_collect, j * TILE, i * TILE);
			// else if (game->map[i][j] == 'E')
			// 	mlx_put_image_to_window(game->mlx, game->win, game->img_exit, j * TILE, i * TILE);
			j++;
		}
		i++;
	}
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
	mlx_loop(game.mlx);

	free_2d(game.map);
	return (0);
}
