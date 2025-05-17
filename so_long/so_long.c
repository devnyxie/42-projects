/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tafanasi <tafanasi@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/26 22:26:09 by tafanasi          #+#    #+#             */
/*   Updated: 2025/05/17 12:00:32 by tafanasi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char **argv)
{
	t_game	game;

	if (argc != 2)
		return (handle_error("Usage: ./so_long <map_file.ber>", 1), 1);
	game.moves = 0;
	game.map = get_map(argv[1]);
	game.height = map_height(game.map);
	game.width = ft_strlen(game.map[0]);
	if (!game.map || !game.map[0])
		return (handle_error("Invalid map", 1), 1);
	game.mlx = mlx_init();
	if (!game.mlx)
		return (handle_error("mlx_init failed", 1), 1);
	game.win = mlx_new_window(game.mlx, game.width * TILE, game.height * TILE,
			"so_long");
	load_images(&game);
	draw_map(&game, game.height, game.width);
	mlx_hook(game.win, 17, 0, handle_exit, &game);
	mlx_hook(game.win, 2, 1L << 0, handle_keypress, &game);
	mlx_loop(game.mlx);
	return (0);
}
