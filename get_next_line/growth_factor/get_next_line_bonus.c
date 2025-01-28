/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tafanasi <tafanasi@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 18:40:19 by tafanasi          #+#    #+#             */
/*   Updated: 2025/01/28 18:40:52 by tafanasi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

#define BUFFER_GROWTH_FACTOR 2

char	*handle_new_line(char *new_line, struct s_buffer *buf);
char	*handle_read_zero(struct s_buffer *buf);
int		adjust_buffer(struct s_buffer *buf, size_t needed_size);
struct	s_buffer *get_buffer(int fd, struct s_buffer **buffers);


char *get_next_line(int fd) {
	static struct s_buffer *buffers[1024] = {NULL};
	struct s_buffer *buf = get_buffer(fd, buffers);
	char *new_line;
	ssize_t bytes_read;

	if (!buf) {
		return NULL;
	}
	while (1) {
		if (adjust_buffer(buf, buf->end + BUFFER_SIZE + 1) < 0) {
			return NULL;
		}
		bytes_read = read(fd, buf->data + buf->end, BUFFER_SIZE);
		if (bytes_read < 0)
			return NULL;
		buf->end += bytes_read;
		buf->data[buf->end] = '\0';
		new_line = ft_strchr(buf->data + buf->start, '\n');
		if (new_line)
			return handle_new_line(new_line, buf);
		if (bytes_read == 0)
			return handle_read_zero(buf);
	}
}

struct s_buffer *get_buffer(int fd, struct s_buffer **buffers) {
	if (fd < 0 || fd >= 1024) {
		return NULL;
	}
	if (!buffers[fd]) {
		buffers[fd] = malloc(sizeof(struct s_buffer));
		if (!buffers[fd]) {
			return NULL;
		}
		buffers[fd]->data = NULL;
		buffers[fd]->capacity = 0;
		buffers[fd]->start = 0;
		buffers[fd]->end = 0;
	}
	return buffers[fd];
}

int adjust_buffer(struct s_buffer *buf, size_t needed_size) {
	size_t new_capacity;
		
	if (!buf->data || buf->capacity < needed_size) {
		if(buf->capacity == 0)
			new_capacity = BUFFER_SIZE * 4;
		else
			new_capacity = buf->capacity * BUFFER_GROWTH_FACTOR;
		char *new_data = malloc(new_capacity + 1);
		if (!new_data)
			return -1;
		if (buf->data) {
			ft_memcpy(new_data, buf->data + buf->start, buf->end - buf->start);
			free(buf->data);
		}
		buf->end -= buf->start;
		buf->start = 0;
		buf->data = new_data;
		buf->capacity = new_capacity;
	}
	return 0;
}

char	*handle_new_line(char *new_line, struct s_buffer *buf)
{
	size_t	result_len;
	char	*tmp;

	result_len = new_line - (buf->data + buf->start) + 1;
	tmp = malloc(result_len + 1);
	if (!tmp)
		return (clear_buffer(buf));
	ft_memcpy(tmp, buf->data + buf->start, result_len);
	tmp[result_len] = '\0';
	buf->start += result_len;
	return (tmp);
}

char	*handle_read_zero(struct s_buffer *buf)
{
	size_t	remain;
	char	*tmp;

	if (buf->start >= buf->end)
		return (clear_buffer(buf));
	remain = buf->end - buf->start;
	tmp = malloc(remain + 1);
	if (!tmp)
		return (clear_buffer(buf));
	ft_memcpy(tmp, buf->data + buf->start, remain);
	tmp[remain] = '\0';
	buf->start += remain;
	return (tmp);
}
