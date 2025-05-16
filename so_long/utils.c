/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tafanasi <tafanasi@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/26 23:12:00 by tafanasi          #+#    #+#             */
/*   Updated: 2025/05/16 14:34:46 by tafanasi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// MLX exit function
int	handle_exit(void *param)
{
	t_game	*game;

	game = (t_game *)param;
	free_game(game);
	exit(0);
	return (0);
}

void	free_2d(char **arr)
{
	int	i;

	i = 0;
	while (arr[i])
	{
		free(arr[i]);
		i++;
	}
	free(arr);
}

void	free_game(t_game *game)
{
	if (game->img_wall)
		mlx_destroy_image(game->mlx, game->img_wall);
	if (game->img_floor)
		mlx_destroy_image(game->mlx, game->img_floor);
	if (game->img_player)
		mlx_destroy_image(game->mlx, game->img_player);
	if (game->img_exit)
		mlx_destroy_image(game->mlx, game->img_exit);
	if (game->img_collect)
		mlx_destroy_image(game->mlx, game->img_collect);
	if (game->win)
		mlx_destroy_window(game->mlx, game->win);
	if (game->map)
		free_2d(game->map);
	if (game->mlx)
	{
		mlx_destroy_display(game->mlx);
		free(game->mlx);
	}
}

void	handle_error(const char *message, int exit_code)
{
	if (!errno)
		ft_printf("%s\n", message);
	else
		perror(message);
	exit(exit_code);
}

int	map_height(char **map)
{
	int	i;

	i = 0;
	while (map[i])
		i++;
	return (i);
}

int	count_lines_fd(char *filename)
{
	char	buf[64];
	int		fd;
	int		i;
	int		j;
	int		bytes_read;
	int		last_char_was_nl;

	i = 0;
	last_char_was_nl = 1;
	fd = open(filename, O_RDONLY);
	if (fd < 0)
		return (-1);
	while ((bytes_read = read(fd, buf, sizeof(buf))) > 0)
	{
		j = 0;
		while (j < bytes_read)
		{
			if (buf[j] == '\n')
			{
				i++;
				last_char_was_nl = 1;
			}
			else
				last_char_was_nl = 0;
			j++;
		}
	}
	if (!last_char_was_nl)
		i++;
	close(fd);
	return (i);
}

// @return (x,y)
t_pos	find_pos(char **map, int height, int width, char letter)
{
	t_pos p;
	p.y = 0;
	while (p.y < height)
	{
		p.x = 0;
		while (p.x < width)
		{
			if (map[p.y][p.x] == letter)
				return (p);
			p.x++;
		}
		p.y++;
	}
	return ((t_pos){-1, -1});
}