/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tafanasi <tafanasi@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/26 16:13:35 by tafanasi          #+#    #+#             */
/*   Updated: 2025/05/13 15:21:47 by tafanasi         ###   ########.fr       */
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
char		*clear_buffer(struct s_buffer *buf);

#endif
