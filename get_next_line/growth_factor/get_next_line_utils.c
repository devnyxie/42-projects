/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tafanasi <tafanasi@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/26 16:13:27 by tafanasi          #+#    #+#             */
/*   Updated: 2025/01/28 16:46:36 by tafanasi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char *clear_buffer(struct Buffer *buf)
{
    free(buf->data);
    buf->data = NULL;
    buf->capacity = 0;
    buf->start = 0;
    buf->end = 0;
    return NULL;
}

char *ft_strchr(const char *s, int c)
{
    while (*s != '\0')
    {
        if (*s == (char)c)
            return ((char *)s);
        s++;
    }
    return (NULL);
}

size_t ft_strlen(const char *s)
{
    size_t len;

    len = 0;
    if (!s)
        return (0);
    while (s[len])
        len++;
    return (len);
}

void    *ft_memcpy(void *dest, const void *src, size_t n)
{
    unsigned char       *d;
    const unsigned char *s;
    size_t             i;

    if (!dest && !src)
        return (NULL);
    d = (unsigned char *)dest;
    s = (const unsigned char *)src;
    i = 0;
    while (i < n)
    {
        d[i] = s[i];
        i++;
    }
    return (dest);
}