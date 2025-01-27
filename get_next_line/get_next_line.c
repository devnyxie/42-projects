/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tafanasi <tafanasi@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/26 21:03:04 by tafanasi          #+#    #+#             */
/*   Updated: 2025/01/27 01:05:05 by tafanasi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 50
#endif
#define MAX_FD 1024

// check if the bytes read are valid; free memory on error
static int	is_valid_read_bytes(ssize_t read_bytes, char *read_chunk,
		char *storage)
{
	if (read_bytes < 0)
	{
		free(read_chunk);
		free(storage);
		return (0);
	}
	return (1);
}

// check if the storage is valid and non-empty
static int	is_valid_storage(char **storage)
{
	if (!*storage || **storage == '\0')
	{
		free(*storage);
		*storage = NULL;
		return (0);
	}
	return (1);
}

// read from fd and store data in storage
static char	*read_file_and_store_storage(int fd, char **storage)
{
	char	*read_chunk;
	char	*joined_data;
	ssize_t	read_bytes;

	if (!storage[fd])
		storage[fd] = ft_strdup("");
	read_chunk = (char *)malloc(BUFFER_SIZE + 1);
	if (!read_chunk)
		return (NULL);
	while (find_eol(storage[fd]) == -1)
	{
		read_bytes = read(fd, read_chunk, BUFFER_SIZE);
		if (!is_valid_read_bytes(read_bytes, read_chunk, storage[fd]))
			return (NULL);
		if (read_bytes == 0)
			break ;
		read_chunk[read_bytes] = '\0';
		joined_data = ft_strjoin(storage[fd], read_chunk);
		free(storage[fd]);
		if (!joined_data)
			return (NULL);
		storage[fd] = joined_data;
	}
	free(read_chunk);
	return (storage[fd]);
}

// extract the next line from storage
static char	*extract_line(char **storage)
{
	char	*line;
	char	*new_storage;
	int		newline_index;

	if (!is_valid_storage(storage))
		return (NULL);
	newline_index = find_eol(*storage);
	if (newline_index >= 0)
	{
		line = ft_strdup(*storage);
		new_storage = ft_strdup(&(*storage)[newline_index + 1]);
		if (!line || !new_storage)
		{
			free(*storage);
			return (NULL);
		}
		line[newline_index + 1] = '\0';
		free(*storage);
		*storage = new_storage;
		return (line);
	}
	line = ft_strdup(*storage);
	free(*storage);
	*storage = NULL;
	return (line);
}

char	*get_next_line(int fd)
{
	static char	*storage[MAX_FD];

	if (fd < 0 || BUFFER_SIZE <= 0 || fd >= MAX_FD)
		return (NULL);
	if (!read_file_and_store_storage(fd, storage))
		return (NULL);
	return (extract_line(&storage[fd]));
}
