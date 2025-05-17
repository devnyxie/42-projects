/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tafanasi <tafanasi@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 13:24:31 by tafanasi          #+#    #+#             */
/*   Updated: 2025/05/17 14:13:39 by tafanasi         ###   ########.fr       */
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

typedef struct map_counts
{
	int				exits;
	int				start_positions;
	int				collectibles;
}					t_map_counts;

typedef struct s_game
{
	void			*mlx;
	void			*win;
	int				width;
	int				height;
	void			*img_wall;
	void			*img_floor;
	void			*img_player;
	void			*img_exit;
	void			*img_collect;
	char			**map;
	int				acquired_collectibles;
	int				moves;
	t_map_counts	map_counts;
}					t_game;

typedef struct pos
{
	int				x;
	int				y;
}					t_pos;

// map_utils -> map
char				**get_map(char *str, t_game *game);

// map_utils -> map_counts
int					check_counts(char **map, int height, int width,
						t_game *game);

// map_utils -> map_check_reach
int					check_reach(char **map, int height, int width);

// map_utils -> map_utils
int					count_newlines(char *buf, int bytes_read,
						int *last_char_was_nl);
int					count_lines_fd(char *filename);
t_pos				find_pos(char **map, int height, int width, char c);

// utils
int					handle_exit(void *param);
void				free_game(t_game *game);
void				free_2d(char **arr);
void				handle_error(const char *message, int exit_code);
int					map_height(char **map);

// movement
int					handle_keypress(int keycode, t_game *game);

// mlx_utils
void				load_images(t_game *game);
void				draw_map(t_game *game, int height, int width);

#endif
