#include "mlx/mlx.h"
#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
#include "get_next_line.h"
#include "libft.h"


int	handle_exit(void *param)
{
	(void)param;
	exit(0);
	return (0);
}

void free_2d(char **arr)
{
    int i = 0;
    while (arr[i])
    {
        free(arr[i]);
        i++;
    }
    free(arr);
    
}

void handle_error(const char *message, int exit_code)
{
    perror(message);
    exit(exit_code);
}

// @return FD of the file, or -1 if it fails
int validate_file(char *str)
{
    int fd;

    if(ft_strnstr(str, ".ber", ft_strlen(str)) == NULL)
        handle_error("Invalid map file format. Expected .ber", 1);
    if(access(str, F_OK) != 0)
        handle_error(strerror(errno), 1);
    fd = open(str, O_RDONLY);
    if (fd == -1)
        handle_error(strerror(errno), 1);
    return (fd);
}

void parse_map(char ***map, int *map_size, int *i, int fd){
    char *line;

    while ((line = get_next_line(fd)) != NULL)
    {
        if (*i >= *map_size) {
            *map_size *= 2;
            char **tmp = malloc(*map_size * sizeof(char *));
            if (!tmp) handle_error("Reallocation failed", 1);
            memmove(tmp, *map, *i * sizeof(char *));
            free(*map);
            *map = tmp;
        }
        (*map)[(*i)++] = line;
    }
    (*map)[*i] = NULL;
}

char **get_map(char *str){
    char **map;

    int fd;
    int i;

    fd = validate_file(str);
    if (fd == -1) handle_error("Invalid file", 1);

    i = 0;
    int map_size = 10;
    map = malloc((map_size + 1) * sizeof(char *));
    if (!map) handle_error("malloc failed", 1);
    parse_map(&map, &map_size, &i, fd);

    if (i == 0) {
        free(map);
        handle_error("Empty map file", 1);
    }
    close(fd);
    return(map);
}

int	main(int argc, char **argv)
{
    if (argc != 2)
    {
        handle_error("Usage: ./so_long <map_file.ber>", 1);
        return (1);
    }
    printf("Map file: %s\n", argv[1]);
    char **map = get_map(argv[1]);
    int i = 0;
    while(map[i] != NULL){
        printf("Line %d: ", i);
        printf("%s", map[i]);
        i++;
    }

    printf("\nMap loaded successfully.\n");
    // printf("\n");
	// void *mlx = mlx_init();
	// void *win = mlx_new_window(mlx, 640, 480, "so_long v0");
	// mlx_hook(win, 17, 0, handle_exit, NULL); // 17 = X11 DestroyNotify
	// mlx_loop(mlx);
    free_2d(map);
	return (0);
}