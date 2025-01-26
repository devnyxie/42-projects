/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tafanasi <tafanasi@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/26 16:13:17 by tafanasi          #+#    #+#             */
/*   Updated: 2025/01/26 16:13:24 by tafanasi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

// BUFFER_SIZE = 8
# define INITIAL_BUFFER_SIZE (BUFFER_SIZE * 4)
# define BUFFER_GROWTH_FACTOR 2

static char *buffer = NULL;
static size_t buffer_capacity = 0; // max size
static size_t buffer_start = 0; // starting point
static size_t buffer_end = 0; // size filled

// new_capacity = buffer_capacity == 0 ? INITIAL_BUFFER_SIZE : buffer_capacity * BUFFER_GROWTH_FACTOR;

char *clear_buffer(void){
    free(buffer);
    buffer = NULL;
    buffer_capacity = 0;
    buffer_start = 0;
    buffer_end = 0;
    return NULL;
}

int reallocate_buffer(void){
    char *tmp;

    size_t new_capacity = 0;
    if (buffer_capacity == 0) {
        new_capacity = INITIAL_BUFFER_SIZE;
    } else {
        new_capacity = buffer_capacity * BUFFER_GROWTH_FACTOR;
    }

    tmp = malloc(new_capacity + 1);
    if(!tmp)
        return(-1);
    if(buffer){
        ft_memcpy(tmp, buffer + buffer_start, buffer_end - buffer_start);
        free(buffer);
    }
    buffer = tmp;
    // reset the offset of buffer_start if it exists
    buffer_end = buffer_end - buffer_start;
    buffer_start = 0;
    buffer_capacity = new_capacity;
    return(0);
}

int ensure_buffer_capacity(size_t needed_size){
    if(!buffer || buffer_capacity < needed_size){
        return(reallocate_buffer());
    } else {
        return (0);
    }
}

char *get_next_line(int fd){
    int bytes_read = 0;
    char *new_line;
    char *tmp;

    if(fd < 0){
        return NULL;
    }
    while(1){
        if(ensure_buffer_capacity(buffer_end + BUFFER_SIZE + 1) < 0){
            return NULL;
        }
        bytes_read = read(fd, buffer + buffer_end, BUFFER_SIZE);
        if(bytes_read < 0) {
            return(clear_buffer());
        }
        buffer_end = buffer_end + bytes_read;
        // null terminate
        buffer[buffer_end] = '\0';
        new_line = ft_strchr(buffer + buffer_start, '\n');
        if(new_line){
            // handle new line
            size_t result_len = new_line - (buffer + buffer_start) + 1;
            tmp = malloc(result_len + 1);
            if(!tmp)
                return(clear_buffer());
            ft_memcpy(tmp, buffer + buffer_start, result_len);
            tmp[result_len] = '\0';
            buffer_start += result_len;
            return(tmp);
        }
        if(bytes_read == 0){
            // eof, will execute after the last line is returned
            if(buffer_start >= buffer_end){
                return(clear_buffer());
            }
            // last line, after execution buffer_start will be equal to buffer_end
            size_t remain = buffer_end - buffer_start;
            tmp = malloc(remain + 1);
            if(!tmp)
                return(clear_buffer());
            ft_memcpy(tmp, buffer + buffer_start, remain);
            tmp[remain] = '\0';
            buffer_start += remain;
            return(tmp);
        }
    }
}