#include "get_next_line.h"

static char *buffer = NULL;

int reallocate_buffer(){
    size_t leftover_i = 0;
    if(buffer)
        leftover_i = ft_strlen(buffer);
    // init
    size_t size_needed = leftover_i + ((BUFFER_SIZE) * sizeof(char));
    char *tmp = malloc(size_needed + 1);
    if(!tmp)
        return -1;
    // null terminate
    tmp[leftover_i] = '\0';
    // move data
    if (buffer) {
        ft_memcpy(tmp, buffer, leftover_i);
        free(buffer);
    }
    // assign buffer
    buffer = tmp;
    // return
    return(0);
}

char *get_next_line(int fd){
    int null_term_i;
    int bytes_read;
    char *eol_ptr;

    if (fd < 0)
        return NULL;
    while(1){
        if (reallocate_buffer() < 0){
            printf("Allocation error!\n");
            return NULL;
        }
        null_term_i = ft_strlen(buffer);
        bytes_read = read(fd, buffer + null_term_i, BUFFER_SIZE);
        if (bytes_read < 0) {
            free(buffer);
            buffer = NULL;
            return NULL;
        }
        if (bytes_read >= 0)
            buffer[null_term_i + bytes_read] = '\0';
        eol_ptr = ft_strchr(buffer, '\n');
        if(eol_ptr){
            size_t return_len = eol_ptr - buffer + 1; //including the eol
            char *return_str = malloc((return_len + 1) * sizeof(char));
            //copy data up to new line
            ft_memcpy(return_str, buffer, return_len);
            return_str[return_len] = '\0';
            //move existing data to the start of the buffer
            size_t leftover_len = ft_strlen(buffer + return_len);
            ft_memmove(buffer, buffer + return_len, leftover_len);
            buffer[leftover_len] = '\0';
            return return_str;
        }
        if (bytes_read == 0) {
            if (!buffer || ft_strlen(buffer) == 0) {
                free(buffer);
                buffer = NULL;
                return NULL;
            }
            size_t len = ft_strlen(buffer);
            char *return_str = malloc((len + 1) * sizeof(char));
            if (!return_str) {
                return NULL;
            }
            ft_memcpy(return_str, buffer, len);
            return_str[len] = '\0';
            free(buffer);
            buffer = NULL;
            return return_str;
        }
    }
}