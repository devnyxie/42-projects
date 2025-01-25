#include <unistd.h>
#include <stdlib.h>
#include <stddef.h>
#include <stdio.h>
#include "get_next_line.h"

static char *buffer[BUFFER_SIZE] = {NULL};

void output_buffer(char *buffer){
    int i = 0;
    int av_space = 0;
    while((buffer)[i])
        i++;
    while((buffer)[i] == 0){
        av_space++;
        i++;
    }
}

int expand_buffer(int fd){
    int i = 0;
    int av_space = 0;
    while(buffer[fd][i])
        i++;
    while(buffer[fd][i] == 0){
        av_space++;
        i++;
    }
    if(av_space < CHUNK_SIZE){
        char *exp_fd_buffer = ft_calloc((i + CHUNK_SIZE + 1), sizeof(char));
        if(!exp_fd_buffer)
            return -1;
        exp_fd_buffer[i+CHUNK_SIZE+1] = '\0';
        int j = 0;
        while(j <= i){
            exp_fd_buffer[j] = buffer[fd][j];
            j++;
        }
        free(buffer[fd]);
        buffer[fd] = exp_fd_buffer;
    }
    return 0;
}

char *skip_data(char *ptr){
    while(*ptr)
        ptr++;
    return ptr;
}

char *get_next_line(int fd){
    if(fd < 0 || fd > BUFFER_SIZE){
        return NULL;
    }
    if(!buffer[fd]){
        buffer[fd] = ft_calloc((CHUNK_SIZE + 1), sizeof(char));
        if(!buffer[fd])
            return NULL;
        output_buffer(buffer[fd]);
    }
    while(1){
        expand_buffer(fd);
        char *ptr = skip_data(buffer[fd]);
        int bytes_read = read(fd, ptr, CHUNK_SIZE);
        if(bytes_read < 0) {
            return NULL;
        }
        output_buffer(buffer[fd]);
        
        char *new_line = ft_strchr(buffer[fd], '\n');
        if(new_line){
            size_t buffer_size = ft_strlen(buffer[fd]);
            int return_len = new_line - buffer[fd] + 1;
            printf("DEBUG: buffer_size=%zu, return_len=%d\n", buffer_size, return_len);
            printf("DEBUG: buffer before split: '%s'\n", buffer[fd]);

            char *return_str = malloc((return_len + 1) * sizeof(char));
            if (!return_str) {
                return NULL;
            }
            ft_memcpy(return_str, buffer[fd], return_len);
            return_str[return_len] = '\0';
            printf("DEBUG: return_str='%s'\n", return_str);

            // size_t remaining_size = buffer_size - (return_len + 1);
            size_t remaining_size;
            if (buffer_size <= (size_t)(return_len + 1)) {
                remaining_size = 0;
            } else {
                remaining_size = buffer_size - (return_len + 1);
            }
            printf("DEBUG: remaining_size=%zu\n", remaining_size);
            
            if (remaining_size > 0) {
                ft_memmove(buffer[fd], new_line + 1, remaining_size);
                printf("DEBUG: buffer after move: '%s'\n", buffer[fd]);
            }
            buffer[fd][remaining_size] = '\0';
            return return_str;
        }
        if (bytes_read == 0) {
            if (ft_strlen(buffer[fd]) == 0) {
                free(buffer[fd]);
                buffer[fd] = NULL;
                return NULL;
            }
            size_t buffer_size = ft_strlen(buffer[fd]);
            char *return_str = malloc((buffer_size + 1) * sizeof(char));
            if (!return_str) {
                return NULL;
            }
            ft_memcpy(return_str, buffer[fd], buffer_size);
            return_str[buffer_size] = '\0';
            free(buffer[fd]);
            buffer[fd] = NULL;
            return return_str;
        }
    }
}