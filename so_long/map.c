/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tafanasi <tafanasi@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/26 23:12:00 by tafanasi          #+#    #+#             */
/*   Updated: 2025/04/27 01:00:40 by tafanasi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	validate_file(char *path)
{
	if (ft_strnstr(path, ".ber", ft_strlen(path)) == NULL)
		handle_error("Invalid map file format. Expected .ber", 1);
	if (access(path, F_OK) != 0)
		handle_error(strerror(errno), 1);
}

int validate_map(char **map, int height)
{
    printf("Validating the map...\n");
    int exit_count; // 1
    int collectibles; // 1+
    int start_pos; // 1
    int width; // less or more than rows (height) W ≥ 3,  H ≥ 3
    int i;
    // TODO
    //int valid_path;
    
    i = 0;
    exit_count = 0;
    start_pos = 0;
    collectibles = 0;
    width = ft_strlen(map[i]);
    while(i < height) {
        // printf("iteration %d\n", i);
        char *row = map[i];
        int j = 0;
    
        int row_len = ft_strlen(map[i]);
        if(width != row_len) // row length is not equal
        {
            printf("exiting at not equal row length\n");
            return(0);
        }
        // while(row[j]){
        while (j < row_len)
        {
            // surrounding walls
            if(i == 0 || i == (height - 1) || j == 0 || j == (row_len - 1))
                if(row[j] != '1'){
                    printf("exiting at walls\n");
                    return(0);
                }
            // collectibles
            if(row[j] == 'C')
                collectibles++;
            // exits
            if(row[j] == 'E'){
                if(exit_count == 0)
                    exit_count = 1;
                else {
                    printf("exiting at exits\n");
                    return(0);
                }
            }
            // starting pos
            if(row[j] == 'P'){
                if(start_pos == 0)
                    start_pos = 1;
                else {
                    printf("exiting at positions\n");
                    return(0);
                }
            }
            j++;
            
        }
        i++;
    }
    if(collectibles < 1 || start_pos != 1 || exit_count != 1){
        printf("exiting at final check\n");
        return(0);
    }
    return(1);
}

// created 2D array, omiting the new lines
void parse_map(char ***map, int fd)
{
    int   i;
    char  *line;
    int   len;

    i = 0;
    while ((line = get_next_line(fd)) != NULL)
    {
        len = ft_strlen(line);
        if (len > 0 && line[len - 1] == '\n')
            line[len - 1] = '\0';
        (*map)[i++] = line;
    }
    (*map)[i] = NULL;
    if (i == 0)
    {
        free(*map);
        handle_error("Empty map file", 1);
    }
}

char	**get_map(char *path)
{
	char	**map;
	int		fd;
    int     result;
	int		map_size;

    validate_file(path);
    fd = open(path, O_RDONLY);
	if (fd == -1)
		handle_error(strerror(errno), 1);
	map_size = count_lines(path);
	map = malloc((map_size + 1) * sizeof(char *));
	if (!map)
		handle_error("malloc failed", 1);
	parse_map(&map, fd);
    result = validate_map(map, map_size);
    if(!result){
        free_2d(map);
        handle_error("Invalid map contents", 1);
    }
    close(fd);
	return (map);
}