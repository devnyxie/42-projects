/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check_reach.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tafanasi <tafanasi@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/17 11:27:59 by tafanasi          #+#    #+#             */
/*   Updated: 2025/05/18 12:01:37 by tafanasi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static char	**cp_map(char **map, int height, int width)
{
	char	**result;
	int		i;
	int		j;

	result = malloc((height + 1) * sizeof(char *));
	if (!result)
		handle_error("Malloc failed", 1);
	result[height] = NULL;
	i = 0;
	while (i < height)
	{
		j = 0;
		result[i] = malloc((width + 1) * sizeof(char));
		if (!result[i])
			handle_error("Malloc failed", 1);
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

static void	dfs(char **map, int x, int y)
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

static void	check_exit_reachable(char **map_cp, char **map, t_pos exit)
{
	if (map_cp[exit.y][exit.x] != 'V')
	{
		free_2d(map_cp);
		free_2d(map);
		handle_error("Exit is unreachable", 1);
	}
}

static void	check_collectibles_reachable(char **map, char **map_cp, int height,
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
				free_2d(map);
				free_2d(map_cp);
				handle_error("Unreachable collectible(s)", 1);
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
	check_exit_reachable(map_cp, map, exit);
	check_collectibles_reachable(map, map_cp, height, width);
	free_2d(map_cp);
	return (1);
}
