/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tafanasi <tafanasi@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 21:35:07 by tafanasi          #+#    #+#             */
/*   Updated: 2025/05/06 23:47:03 by tafanasi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	handle_keypress(int keycode, t_game *game)
{
	Position	p;
	int			dx;
	int			dy;
	char		tile;

	p = find_pos(game->map, game->height, game->width, 'P');
	dx = 0;
	dy = 0;
	if (p.x < 0 || p.y < 0)
		return (0);
	if (keycode == XK_Left)
		dx = -1;
	else if (keycode == XK_Right)
		dx = 1;
	else if (keycode == XK_Up)
		dy = -1;
	else if (keycode == XK_Down)
		dy = 1;
	else if (keycode == XK_Escape)
		handle_exit(game);
	if (dx == 0 && dy == 0)
		return (0);
	tile = game->map[p.y + dy][p.x + dx];
	if (tile == '1')
		return (0);
	if (tile == 'E')
		handle_exit(game);
	game->map[p.y][p.x] = '0';
	game->map[p.y + dy][p.x + dx] = 'P';
	game->moves++;
	printf("Movements: %d\n", game->moves);
	draw_map(game, game->height, game->width);
	return (0);
}

// int handle_keypress(int keycode, t_game *game)
// {
//     Position player_pos;
//     player_pos = find_pos(game->map, game->height, game->width, 'P');
//     if (player_pos.x == -1 || player_pos.y == -1) {
//         return (0);
//     }

//     int moved = 0;
//     if(keycode == XK_Left && game->map[player_pos.y][player_pos.x
// 	- 1] == 'E')
//     {
//         free_game(game);
//         handle_exit(NULL);
//         return (0);
//     }
//     else if (keycode == XK_Right && game->map[player_pos.y][player_pos.x
// 	+ 1] == 'E')
//     {
//         free_game(game);
//         handle_exit(NULL);
//         return (0);
//     }
//     else if (keycode == XK_Up && game->map[player_pos.y
// 	- 1][player_pos.x] == 'E')
//     {
//         free_game(game);
//         handle_exit(NULL);
//         return (0);
//     }
//     else if (keycode == XK_Down && game->map[player_pos.y
// 	+ 1][player_pos.x] == 'E')
//     {
//         free_game(game);
//         handle_exit(NULL);
//         return (0);
//     }
//     if(keycode == XK_Left && game->map[player_pos.y][player_pos.x
// 	- 1] == 'C')
//     {
//         game->map[player_pos.y][player_pos.x] = '0';
//         game->map[player_pos.y][player_pos.x - 1] = 'P';
//         moved = 1;
//     }
//     else if (keycode == XK_Right && game->map[player_pos.y][player_pos.x
// 	+ 1] == 'C')
//     {
//         game->map[player_pos.y][player_pos.x] = '0';
//         game->map[player_pos.y][player_pos.x + 1] = 'P';
//         moved = 1;
//     }
//     else if (keycode == XK_Up && game->map[player_pos.y
// 	- 1][player_pos.x] == 'C')
//     {
//         game->map[player_pos.y][player_pos.x] = '0';
//         game->map[player_pos.y - 1][player_pos.x] = 'P';
//         moved = 1;
//     }
//     else if (keycode == XK_Down && game->map[player_pos.y
// 	+ 1][player_pos.x] == 'C')
//     {
//         game->map[player_pos.y][player_pos.x] = '0';
//         game->map[player_pos.y + 1][player_pos.x] = 'P';
//         moved = 1;
//     }
//     if (keycode == XK_Left && game->map[player_pos.y][player_pos.x
// 	- 1] != '1')
//     {
//         game->map[player_pos.y][player_pos.x] = '0';
//         game->map[player_pos.y][player_pos.x - 1] = 'P';
//         moved = 1;
//     }
//     else if (keycode == XK_Right && game->map[player_pos.y][player_pos.x
// 	+ 1] != '1')
//     {
//         game->map[player_pos.y][player_pos.x] = '0';
//         game->map[player_pos.y][player_pos.x + 1] = 'P';
//         moved = 1;
//     }
//     else if (keycode == XK_Up && game->map[player_pos.y
// 	- 1][player_pos.x] != '1')
//     {
//         game->map[player_pos.y][player_pos.x] = '0';
//         game->map[player_pos.y - 1][player_pos.x] = 'P';
//         moved = 1;
//     }
//     else if (keycode == XK_Down && game->map[player_pos.y
// 	+ 1][player_pos.x] != '1')
//     {
//         game->map[player_pos.y][player_pos.x] = '0';
//         game->map[player_pos.y + 1][player_pos.x] = 'P';
//         moved = 1;
//     }
//     if (keycode == XK_Escape)
//     {
//         free_game(game);
//         handle_exit(NULL);
//         return (0);
//     }
//     if (moved) {
//         game->moves++;
//         printf("Movements: %d\n", game->moves);
//     }
//     draw_map(game, map_height(game->map), ft_strlen(game->map[0]));
//     return (0);
// }
