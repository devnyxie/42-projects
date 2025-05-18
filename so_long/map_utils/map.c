/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tafanasi <tafanasi@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/26 23:12:00 by tafanasi          #+#    #+#             */
/*   Updated: 2025/05/18 11:49:12 by tafanasi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	validate_file(char *path)
{
	size_t	len;

	len = ft_strlen(path);
	if (len < 4 || ft_strncmp(path + len - 4, ".ber", 4) != 0)
		handle_error("Invalid map file format. Expected .ber", 1);
	if (access(path, F_OK) != 0)
		handle_error(strerror(errno), 1);
}

int	val_map_v2(char **map, int height, t_game *game)
{
	int	width;

	width = ft_strlen(map[0]);
	if (!check_counts(map, height, width, game))
		return (0);
	if (!check_reach(map, height, width))
		return (0);
	return (1);
}

// create 2D array, omiting the new lines
void	parse_map(char ***map, int fd)
{
	int		i;
	char	*line;
	int		len;

	i = 0;
	while (1)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break ;
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

char	**get_map(char *path, t_game *game)
{
	char	**map;
	int		fd;
	int		result;
	int		map_height;

	validate_file(path);
	fd = open(path, O_RDONLY);
	if (fd == -1)
		handle_error(strerror(errno), 1);
	map_height = count_lines_fd(path);
	map = malloc((map_height + 1) * sizeof(char *));
	if (!map)
		handle_error("Malloc failed", 1);
	parse_map(&map, fd);
	result = val_map_v2(map, map_height, game);
	if (!result)
	{
		free_2d(map);
		handle_error("Invalid map contents", 1);
	}
	close(fd);
	return (map);
}
