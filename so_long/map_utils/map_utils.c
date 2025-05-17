/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tafanasi <tafanasi@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/17 12:03:39 by tafanasi          #+#    #+#             */
/*   Updated: 2025/05/17 12:08:56 by tafanasi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

// Helper function to count newlines in a buffer
int	count_newlines(char *buf, int bytes_read, int *last_char_was_nl)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (i < bytes_read)
	{
		if (buf[i] == '\n')
		{
			count++;
			*last_char_was_nl = 1;
		}
		else
			*last_char_was_nl = 0;
		i++;
	}
	return (count);
}

// Main function to count lines in a file
int	count_lines_fd(char *filename)
{
	char	buf[64];
	int		fd;
	int		line_count;
	int		bytes_read;
	int		last_char_was_nl;

	line_count = 0;
	last_char_was_nl = 1;
	fd = open(filename, O_RDONLY);
	if (fd < 0)
		return (-1);
	while (1)
	{
		bytes_read = read(fd, buf, sizeof(buf));
		if (bytes_read <= 0)
			break ;
		line_count += count_newlines(buf, bytes_read, &last_char_was_nl);
	}
	if (!last_char_was_nl)
		line_count++;
	close(fd);
	return (line_count);
}

// @return (x,y)
t_pos	find_pos(char **map, int height, int width, char letter)
{
	t_pos	p;

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
