#ifndef SO_LONG_H
#define SO_LONG_H

#include "get_next_line.h"
#include "libft.h"
#include "mlx/mlx.h"
#include "ft_printf.h"
#include <X11/keysym.h>
#include <errno.h>
#include <fcntl.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define TILE 64

typedef struct s_game {
	void	*mlx;
	void	*win;
    int      width;
    int      height;
	void	*img_wall;
	void	*img_floor;
	void	*img_player;
	void	*img_exit;
	void	*img_collect;
	char	**map;
	int	moves;
} t_game;

typedef struct {
    int x;
    int y;
} Position;

// map
char **get_map(char *str);

// utils
int handle_exit(void *param);
void free_game(t_game *game);
void free_2d(char **arr);
void handle_error(const char *message, int exit_code);
int count_lines_fd(char *filename);
int map_height(char **map);
Position find_pos(char **map, int height, int width, char c);

// movement
int handle_keypress(int keycode, t_game *game);

// mlx_utils
void load_images(t_game *game);
void draw_map(t_game *game, int height, int width);

#endif
