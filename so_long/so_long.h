
#ifndef SO_LONG_H
#define SO_LONG_H

#include "get_next_line.h"
#include "libft.h"
#include "mlx/mlx.h"
#include <errno.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

// map
char **get_map(char *str);

// utils
int handle_exit(void *param);
void free_2d(char **arr);
void handle_error(const char *message, int exit_code);
int count_lines(char *filename);

#endif
