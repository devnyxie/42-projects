/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tafanasi <tafanasi@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 13:24:31 by tafanasi          #+#    #+#             */
/*   Updated: 2025/05/16 16:30:11 by tafanasi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "ft_printf.h"
# include "get_next_line.h"
# include "libft.h"
# include "mlx/mlx.h"
# include <X11/keysym.h>
# include <errno.h>
# include <fcntl.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>

# define TILE 64

typedef struct s_game
{
	void	*mlx;
	void	*win;
	int		width;
	int		height;
	void	*img_wall;
	void	*img_floor;
	void	*img_player;
	void	*img_exit;
	void	*img_collect;
	char	**map;
	int		moves;
}			t_game;

typedef struct map_counts
{
	int		exits;
	int		start_positions;
	int		collectibles;
}			t_map_counts;

typedef struct pos
{
	int		x;
	int		y;
}			t_pos;

// map
char		**get_map(char *str);

// utils
int			handle_exit(void *param);
void		free_game(t_game *game);
void		free_2d(char **arr);
void		handle_error(const char *message, int exit_code);
int			count_lines_fd(char *filename);
int			map_height(char **map);
t_pos		find_pos(char **map, int height, int width, char c);

// movement
int			handle_keypress(int keycode, t_game *game);

// mlx_utils
void		load_images(t_game *game);
void		draw_map(t_game *game, int height, int width);

#endif
