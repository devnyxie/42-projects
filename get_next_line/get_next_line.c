#include <unistd.h> //null
#include <stdlib.h> //malloc, calloc
#include <stddef.h>
#include <stdio.h>

#define FD_LIMIT 1024
#define CHUNK_SIZE 8

// already terminated
static char *buffer[FD_LIMIT] = {NULL};

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

void *ft_memmove(void *dest, const void *src, size_t n)
{
    unsigned char *d;
    const unsigned char *s;

    if (!dest && !src)
        return (NULL);

    d = (unsigned char *)dest;
    s = (const unsigned char *)src;

    if (d < s)
    {
        while (n--)
            *d++ = *s++;
    }
    else if (d > s)
    {
        d += n - 1;
        s += n - 1;
        while (n--)
            *d-- = *s--;
    }

    return (dest);
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

void output_buffer(char *buffer){
    int i = 0;
    int av_space = 0;
    while((buffer)[i])
        i++;
    while((buffer)[i] == 0){
        av_space++;
        i++;
    }
    printf("available space: %d\n", av_space);
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
    // output_buffer(buffer[fd]);
    if(av_space < CHUNK_SIZE){
        printf("buffer expansion triggered\n");
        // now we have [i] real values
        char *exp_fd_buffer = calloc((i + CHUNK_SIZE + 1), sizeof(char));
        if(!exp_fd_buffer)
            return -1;
        // null terminate
        exp_fd_buffer[i+CHUNK_SIZE+1] = '\0';
        // move existing buffer values into the expanded buffer
        int j = 0;
        while(j <= i){
            exp_fd_buffer[j] = buffer[fd][j];
            j++;
        }
        // free the prev buffer
        free(buffer[fd]);
        buffer[fd] = exp_fd_buffer;
    }
    return 0;
}

char *skip_data(char *ptr){
    printf("moving ptr to the end\n");
    while(*ptr)
        ptr++;
    return ptr;
}

char *get_next_line(int fd){
    printf("get_next_line started\n");
    if(fd < 0 || fd > FD_LIMIT){
        return NULL;
    }
    if(!buffer[fd]){
        buffer[fd] = calloc((CHUNK_SIZE + 1), sizeof(char));
        if(!buffer[fd])
            return NULL;
        printf("new buffer created\n");
        output_buffer(buffer[fd]);
    }
    while(1){
        // expand if needed
        expand_buffer(fd);
        // skip leftover data
        char *ptr = skip_data(buffer[fd]);
        int bytes_read = read(fd, ptr, CHUNK_SIZE);
        if(bytes_read < 0) {
            //read error
            printf("read error\n");
            return NULL;
        }
        printf("%i bytes read\n", bytes_read);

        output_buffer(buffer[fd]);

        // 1. check for new line in the buffer
        // 2. if there is, split for return and leftover. if no, continue the loop.
        printf("whole buffer: %s\n", buffer[fd]);


        char *new_line = ft_strchr(buffer[fd], '\n');
        if(new_line){
            printf("new line found\n");

            // split:
            // right before the next line -> return
            // right after -> leftover, memmove
            // buffer[fd] = 100, result 112
            // 112 - 100 = 12 (characters in, str including \n)
            // so:
            size_t buffer_size = ft_strlen(buffer[fd]);

            int return_len = new_line - buffer[fd]; //e.g 12
            char *return_str = malloc((return_len + 1) * sizeof(char));
            if (!return_str) {
                return NULL;
            }
            // Copy the string up to the newline
            ft_memcpy(return_str, buffer[fd], return_len);
            return_str[return_len] = '\0';

            // Move the remaining content of the buffer to the start
            size_t remaining_size = buffer_size - (return_len + 1);
            if (remaining_size > 0) {
                ft_memmove(buffer[fd], new_line + 1, remaining_size);
            }
            // Null-terminate the remaining buffer
            buffer[fd][remaining_size] = '\0';

            printf("Cleaned buffer: %s\n", buffer[fd]);
            return return_str;
        } else {
            printf("no new line was found\n");
        }
        // EOF
        if (bytes_read == 0) {
            if (ft_strlen(buffer[fd]) == 0) {
                free(buffer[fd]);
                buffer[fd] = NULL;
                return NULL; // Nothing left to return
            }

            printf("returning the final chunk\n");
            size_t buffer_size = ft_strlen(buffer[fd]);
            char *return_str = malloc((buffer_size + 1) * sizeof(char));
            if (!return_str) {
                printf("Error: Memory allocation failed for final chunk.\n");
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