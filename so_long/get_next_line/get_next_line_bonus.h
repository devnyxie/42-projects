/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tafanasi <tafanasi@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/26 16:13:35 by tafanasi          #+#    #+#             */
/*   Updated: 2025/04/25 23:31:20 by tafanasi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 8
# endif

// malloc, size_t etc
# include <stdlib.h>
// read etc
# include <unistd.h>
// printf
# include <stdio.h>
// libft
# include "libft.h"

struct		s_buffer
{
	char	*data;
	size_t	capacity;
	size_t	start;
	size_t	end;
};

char		*get_next_line(int fd);
// char		*ft_strchr(const char *s, int c);
// size_t		ft_strlen(const char *s);
// void		*ft_memcpy(void *dest, const void *src, size_t n);
char		*clear_buffer(struct s_buffer *buf);

#endif
