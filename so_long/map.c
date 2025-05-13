/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tafanasi <tafanasi@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/26 23:12:00 by tafanasi          #+#    #+#             */
/*   Updated: 2025/05/13 15:15:57 by tafanasi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	validate_file(char *path)
{
	size_t	len = ft_strlen(path);

	if (len < 4 || ft_strncmp(path + len - 4, ".ber", 4) != 0)
		handle_error("Invalid map file format. Expected .ber", 1);
	if (access(path, F_OK) != 0)
		handle_error(strerror(errno), 1);
}

// TEGGRGRGR
char **cp_map(char **map, int height, int width)
{
	char **result;

	result = malloc((height + 1) * sizeof(char*));
	if(!result)
		handle_error("malloc failed", 1);
	result[height] = NULL;

	int i;
	int j;

	i = 0;
	while (i < height){
		j = 0;
		result[i] = malloc((width+1)*sizeof(char));
		if(!result[i])
			handle_error("malloc failed", 1);
		result[i][width] = '\0';
		while(j < width){
			result[i][j] = map[i][j];
			j++;
		}
		i++;
	}
	return(result);
}

// void dfs(char **map, int x, int y) {
//     if (map[y][x] == '1' || map[y][x] == 'V' || map[y][x] == 'E')
//         return;
//     map[y][x] = 'V';
//     dfs(map, x + 1, y);
//     dfs(map, x - 1, y);
//     dfs(map, x, y + 1);
//     dfs(map, x, y - 1);
// }

void dfs(char **map, int x, int y) {
	char yx = map[y][x];
	if (yx == '1' || yx == 'V')
		return;
	map[y][x] = 'V';
	if(yx != 'E'){
		dfs(map, x + 1, y);
		dfs(map, x - 1, y);
		dfs(map, x, y + 1);
		dfs(map, x, y - 1);  
	}

}

int validate_map(char **map, int height)
{
	// ft_printf("Validating the map...\n");
	int exit_count; // 1
	int collectibles_count; // 1+
	int start_pos_count; // 1
	int width; // less or more than rows (height) W ≥ 3,  H ≥ 3
	int i;
	// TODO
	//int valid_path;
	
	i = 0;
	exit_count = 0;
	start_pos_count = 0;
	collectibles_count = 0;
	width = ft_strlen(map[i]);
	while(i < height) {
		// ft_printf("iteration %d\n", i);
		char *row = map[i];
		int j = 0;
	
		int row_len = ft_strlen(map[i]);
		if(width != row_len) // row length is not equal
		{
			ft_printf("exiting at not equal row length\n");
			return(0);
		}
		// while(row[j]){
		while (j < row_len)
		{
			// surrounding walls
			if(i == 0 || i == (height - 1) || j == 0 || j == (row_len - 1))
				if(row[j] != '1'){
					ft_printf("exiting at walls\n");
					return(0);
				}
			// collectibles_count
			if(row[j] == 'C')
				collectibles_count++;
			// exits
			if(row[j] == 'E'){
				if(exit_count == 0)
					exit_count = 1;
				else {
					ft_printf("exiting at exits\n");
					return(0);
				}
			}
			// starting pos
			if(row[j] == 'P'){
				if(start_pos_count == 0)
					start_pos_count = 1;
				else {
					ft_printf("exiting at positions\n");
					return(0);
				}
			}
			j++;
			
		}
		i++;
	}
	if(collectibles_count < 1 || start_pos_count != 1 || exit_count != 1){
		ft_printf("exiting at final check\n");
		return(0);
	}
	// check if at least 1 C and one E is reachable from P
	char **copy = cp_map(map, height, width);
	// for (int i = 0; i < height; i++) {
	//     ft_printf("%s\n", copy[i]);
	// }
	// check if the map's exit is reachable
	Position start_pos_loc = find_pos(map, height, width, 'P');
	Position exit = find_pos(map, height, width, 'E');
	// Position coin = find_pos(map, height, width, 'C');
	dfs(copy, start_pos_loc.x, start_pos_loc.y);
	// if(copy[exit.y][exit.x] != 'V' || copy[coin.y][coin.x] != 'V'){
	//     free_2d(copy);
	//     handle_error("Could not find path to exit the map or at least one collectible", 1);
	//     return(0);
	// }
	/* 2.a Exit must be reachable */
	if (copy[exit.y][exit.x] != 'V')
	{
		free_2d(copy);
		handle_error("Exit is unreachable", 1);
		return (0);
	}

	/* 2.b All coins must be reachable: no 'C' should remain */
	for (int y = 0; y < height; y++)
	{
		for (int x = 0; x < width; x++)
		{
			if (map[y][x] == 'C' && copy[y][x] != 'V')
			{
				free_2d(copy);
				handle_error("At least one collectible is unreachable", 1);
				return (0);
			}
		}
	}
	free_2d(copy);
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
	int		map_height;

	validate_file(path);
	ft_printf("File `%s` is valid\n", path);
	fd = open(path, O_RDONLY);
	if (fd == -1)
		handle_error(strerror(errno), 1);
	map_height = count_lines_fd(path);
	map = malloc((map_height + 1) * sizeof(char *));
	if (!map)
		handle_error("malloc failed", 1);
	parse_map(&map, fd);
	result = validate_map(map, map_height);
	ft_printf("Map of file `%s` is valid\n", path);
	if(!result){
		free_2d(map);
		handle_error("Invalid map contents", 1);
	}
	close(fd);
	return (map);
}
