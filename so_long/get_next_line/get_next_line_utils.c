/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tafanasi <tafanasi@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/26 16:13:27 by tafanasi          #+#    #+#             */
/*   Updated: 2025/04/25 23:32:12 by tafanasi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*clear_buffer(struct s_buffer *buf)
{
	free(buf->data);
	buf->data = NULL;
	buf->capacity = 0;
	buf->start = 0;
	buf->end = 0;
	return (NULL);
}