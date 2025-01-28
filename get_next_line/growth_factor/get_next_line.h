/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tafanasi <tafanasi@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/26 16:13:35 by tafanasi          #+#    #+#             */
/*   Updated: 2025/01/28 16:46:42 by tafanasi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
#   define GET_NEXT_LINE_H

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 8
#endif

// malloc, size_t etc
#include <stdlib.h>
// read etc
#include <unistd.h>
// printf
#include <stdio.h>

struct Buffer {
    char *data;
    size_t capacity;
    size_t start;
    size_t end;
};

char *get_next_line(int fd);
char *ft_strchr(const char *s, int c);
size_t ft_strlen(const char *s);
void *ft_memcpy(void *dest, const void *src, size_t n);
char *clear_buffer(struct Buffer *buf);

#endif