/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check_counts.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tafanasi <tafanasi@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/17 11:21:12 by tafanasi          #+#    #+#             */
/*   Updated: 2025/05/17 14:13:18 by tafanasi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static int	check_chars(char **map, int height, int width)
{
	int		i;
	int		j;
	char	tile;

	i = 0;
	while (i < height)
	{
		j = 0;
		while (j < width)
		{
			tile = map[i][j];
			if (tile != '1' && tile != '0' && tile != 'C' && tile != 'E'
				&& tile != 'P')
				return (0);
			j++;
		}
		i++;
	}
	return (1);
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

static int	check_tiles(char **map, int height, int width, t_map_counts *counts)
{
	int	i;
	int	j;
	int	len;

	i = 0;
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
			update_counts(map[i][j], counts);
			j++;
		}
		i++;
	}
	return (1);
}

int	check_counts(char **map, int height, int width, t_game *game)
{
	int				result;
	t_map_counts	counts;

	init_counts(&counts);
	result = check_chars(map, height, width);
	if (!result)
		return (0);
	result = check_tiles(map, height, width, &counts);
	if (!result)
		return (0);
	if (counts.collectibles < 1 || counts.start_positions != 1
		|| counts.exits != 1)
		return (0);
	game->map_counts = counts;
	return (1);
}
