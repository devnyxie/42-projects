/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tafanasi <tafanasi@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 21:35:07 by tafanasi          #+#    #+#             */
/*   Updated: 2025/05/17 11:59:17 by tafanasi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	update_player_position(t_game *game, t_pos p, int dx, int dy)
{
	game->map[p.y][p.x] = '0';
	game->map[p.y + dy][p.x + dx] = 'P';
	game->moves++;
	ft_printf("Movements: %d\n", game->moves);
	draw_map(game, game->height, game->width);
}

static int	handle_tile_interaction(t_game *game, char tile)
{
	if (tile == '1')
		return (0);
	if (tile == 'E')
		handle_exit(game);
	return (1);
}

static int	get_movement_delta(int keycode, int *dx, int *dy)
{
	*dx = 0;
	*dy = 0;
	if (keycode == XK_Left)
		*dx = -1;
	else if (keycode == XK_Right)
		*dx = 1;
	else if (keycode == XK_Up)
		*dy = -1;
	else if (keycode == XK_Down)
		*dy = 1;
	else if (keycode == XK_Escape)
		return (-1);
	return (*dx != 0 || *dy != 0);
}

int	handle_keypress(int keycode, t_game *game)
{
	t_pos	p;
	int		dx;
	int		dy;
	char	tile;

	p = find_pos(game->map, game->height, game->width, 'P');
	if (p.x < 0 || p.y < 0)
		return (0);
	if (get_movement_delta(keycode, &dx, &dy) == -1)
		handle_exit(game);
	if (dx == 0 && dy == 0)
		return (0);
	tile = game->map[p.y + dy][p.x + dx];
	if (!handle_tile_interaction(game, tile))
		return (0);
	update_player_position(game, p, dx, dy);
	return (0);
}
