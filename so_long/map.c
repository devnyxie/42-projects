/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tafanasi <tafanasi@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/26 23:12:00 by tafanasi          #+#    #+#             */
/*   Updated: 2025/05/16 19:06:08 by tafanasi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	validate_file(char *path)
{
	size_t	len;

	len = ft_strlen(path);
	if (len < 4 || ft_strncmp(path + len - 4, ".ber", 4) != 0)
		handle_error("Invalid map file format. Expected .ber", 1);
	if (access(path, F_OK) != 0)
		handle_error(strerror(errno), 1);
}

char	**cp_map(char **map, int height, int width)
{
	char	**result;
	int		i;
	int		j;

	result = malloc((height + 1) * sizeof(char *));
	if (!result)
		handle_error("malloc failed", 1);
	result[height] = NULL;
	i = 0;
	while (i < height)
	{
		j = 0;
		result[i] = malloc((width + 1) * sizeof(char));
		if (!result[i])
			handle_error("malloc failed", 1);
		result[i][width] = '\0';
		while (j < width)
		{
			result[i][j] = map[i][j];
			j++;
		}
		i++;
	}
	return (result);
}

void	dfs(char **map, int x, int y)
{
	char	yx;

	yx = map[y][x];
	if (yx == '1' || yx == 'V')
		return ;
	map[y][x] = 'V';
	if (yx != 'E')
	{
		dfs(map, x + 1, y);
		dfs(map, x - 1, y);
		dfs(map, x, y + 1);
		dfs(map, x, y - 1);
	}
}

static void	init_counts(t_map_counts *counts)
{
	counts->exits = 0;
	counts->collectibles = 0;
	counts->start_positions = 0;
}

static int	update_counts(char c, t_map_counts *counts)
{
	if (c == 'C')
		counts->collectibles++;
	else if (c == 'E')
		counts->exits++;
	else if (c == 'P')
		counts->start_positions++;
	return (0);
}

int	check_counts(char **map, int height, int width)
{
	int				i;
	int				j;
	int				len;
	t_map_counts	counts;

	i = 0;
	init_counts(&counts);
	while (i < height)
	{
		len = ft_strlen(map[i]);
		if (len != width)
			return (0);
		j = 0;
		while (j < len)
		{
			if ((i == 0 || i == height - 1 || j == 0 || j == len - 1)
				&& map[i][j] != '1')
				return (0);
			update_counts(map[i][j], &counts);
			j++;
		}
		i++;
	}
	if (counts.collectibles < 1 || counts.start_positions != 1
		|| counts.exits != 1)
		return (0);
	return (1);
}

void	check_exit_reachable(char **map_cp, t_pos exit)
{
	if (map_cp[exit.y][exit.x] != 'V')
	{
		free_2d(map_cp);
		handle_error("Exit is unreachable", 1);
	}
}

void	check_collectibles_reachable(char **map, char **map_cp, int height,
		int width)
{
	int	y;
	int	x;

	y = 0;
	while (y < height)
	{
		x = 0;
		while (x < width)
		{
			if (map[y][x] == 'C' && map_cp[y][x] != 'V')
			{
				free_2d(map_cp);
				handle_error("At least one collectible is unreachable", 1);
			}
			x++;
		}
		y++;
	}
}

int	check_reach(char **map, int height, int width)
{
	char	**map_cp;
	t_pos	start_pos_loc;
	t_pos	exit;

	map_cp = cp_map(map, height, width);
	start_pos_loc = find_pos(map, height, width, 'P');
	exit = find_pos(map, height, width, 'E');
	dfs(map_cp, start_pos_loc.x, start_pos_loc.y);
	check_exit_reachable(map_cp, exit);
	check_collectibles_reachable(map, map_cp, height, width);
	free_2d(map_cp);
	return (1);
}

int	val_map_v2(char **map, int height)
{
	int	width;

	width = ft_strlen(map[0]);
	if (!check_counts(map, height, width))
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

char	**get_map(char *path)
{
	char	**map;
	int		fd;
	int		result;
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
	result = val_map_v2(map, map_height);
	if (!result)
	{
		free_2d(map);
		handle_error("Invalid map contents", 1);
	}
	ft_printf("Map of file `%s` is valid\n", path);
	close(fd);
	return (map);
}
