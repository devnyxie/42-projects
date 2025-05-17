/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tafanasi <tafanasi@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 22:05:27 by tafanasi          #+#    #+#             */
/*   Updated: 2025/05/17 12:10:28 by tafanasi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	load_images(t_game *game)
{
	int	w;
	int	h;

	game->img_wall = mlx_xpm_file_to_image(game->mlx, "assets/wall.xpm", &w,
			&h);
	game->img_floor = mlx_xpm_file_to_image(game->mlx, "assets/floor.xpm", &w,
			&h);
	game->img_player = mlx_xpm_file_to_image(game->mlx, "assets/player.xpm", &w,
			&h);
	game->img_exit = mlx_xpm_file_to_image(game->mlx, "assets/exit.xpm", &w,
			&h);
	game->img_collect = mlx_xpm_file_to_image(game->mlx, "assets/collect.xpm",
			&w, &h);
}

static void	draw_floor(t_game *game, int height, int width)
{
	int	i;
	int	j;

	i = 0;
	while (i < height)
	{
		j = 0;
		while (j < width)
		{
			mlx_put_image_to_window(game->mlx, game->win, game->img_floor, j
				* TILE, i * TILE);
			j++;
		}
		i++;
	}
}

static void	draw_elements(t_game *game, int height, int width)
{
	int	i;
	int	j;

	i = 0;
	while (i < height)
	{
		j = 0;
		while (j < width)
		{
			if (game->map[i][j] == '1')
				mlx_put_image_to_window(game->mlx, game->win, game->img_wall, j
					* TILE, i * TILE);
			else if (game->map[i][j] == 'C')
				mlx_put_image_to_window(game->mlx, game->win, game->img_collect,
					j * TILE, i * TILE);
			else if (game->map[i][j] == 'E')
				mlx_put_image_to_window(game->mlx, game->win, game->img_exit, j
					* TILE, i * TILE);
			else if (game->map[i][j] == 'P')
				mlx_put_image_to_window(game->mlx, game->win, game->img_player,
					j * TILE, i * TILE);
			j++;
		}
		i++;
	}
}

void	draw_map(t_game *game, int height, int width)
{
	draw_floor(game, height, width);
	draw_elements(game, height, width);
}
