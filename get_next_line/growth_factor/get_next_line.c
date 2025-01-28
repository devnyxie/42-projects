/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tafanasi <tafanasi@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 16:45:32 by tafanasi          #+#    #+#             */
/*   Updated: 2025/01/28 16:50:01 by tafanasi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

# define INITIAL_BUFFER_SIZE (BUFFER_SIZE * 4)
# define BUFFER_GROWTH_FACTOR 2

int ensure_buffer_capacity(size_t needed_size, struct Buffer *buf);
int reallocate_buffer(struct Buffer *buf);
char *handle_new_line(char *new_line, struct Buffer *buf);
char *handle_read_zero(struct Buffer *buf);

char *get_next_line(int fd){
    static struct Buffer buf = {NULL, 0, 0, 0};
    int bytes_read = 0;
    char *new_line;
    if(fd < 0){
        return NULL;
    }
    while(1){
        if(ensure_buffer_capacity(buf.end + BUFFER_SIZE + 1, &buf) < 0)
            return NULL;
        bytes_read = read(fd, buf.data + buf.end, BUFFER_SIZE);
        if(bytes_read < 0)
            return(clear_buffer(&buf));
        buf.end = buf.end + bytes_read;
        buf.data[buf.end] = '\0';
        new_line = ft_strchr(buf.data + buf.start, '\n');
        if(new_line)
            return(handle_new_line(new_line, &buf));
        if(bytes_read == 0)
            return(handle_read_zero(&buf));
    }
}

int ensure_buffer_capacity(size_t needed_size, struct Buffer *buf){
    if(!buf->data || buf->capacity < needed_size){
        return(reallocate_buffer(buf));
    } else {
        return (0);
    }
}

int reallocate_buffer(struct Buffer *buf){
    char *tmp;

    size_t new_capacity = 0;
    if (buf->capacity == 0) {
        new_capacity = INITIAL_BUFFER_SIZE;
    } else {
        new_capacity = buf->capacity * BUFFER_GROWTH_FACTOR;
    }

    tmp = malloc(new_capacity + 1);
    if(!tmp)
        return(-1);
    if(buf->data){
        ft_memcpy(tmp, buf->data + buf->start, buf->end - buf->start);
        free(buf->data);
    }
    buf->data = tmp;
    buf->end = buf->end - buf->start;
    buf->start = 0;
    buf->capacity = new_capacity;
    return(0);
}

char *handle_new_line(char *new_line, struct Buffer *buf){
    size_t result_len = new_line - (buf->data + buf->start) + 1;
    char *tmp = malloc(result_len + 1);
    if(!tmp)
        return(clear_buffer(buf));
    ft_memcpy(tmp, buf->data + buf->start, result_len);
    tmp[result_len] = '\0';
    buf->start += result_len;
    return(tmp);
}

char *handle_read_zero(struct Buffer *buf){
    if(buf->start >= buf->end)
        return(clear_buffer(buf));
    size_t remain = buf->end - buf->start;
    char *tmp = malloc(remain + 1);
    if(!tmp)
        return(clear_buffer(buf));
    ft_memcpy(tmp, buf->data + buf->start, remain);
    tmp[remain] = '\0';
    buf->start += remain;
    return(tmp);
}