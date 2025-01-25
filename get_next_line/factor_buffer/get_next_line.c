#include "get_next_line.h"

# define INITIAL_BUFFER_SIZE (BUFFER_SIZE * 4)
# define BUFFER_GROWTH_FACTOR 2

static char *buffer = NULL;
static size_t buffer_capacity = 0;
static size_t buffer_start = 0;
static size_t buffer_end = 0;

static void cleanup_buffer(void)
{
    free(buffer);
    buffer = NULL;
    buffer_capacity = 0;
    buffer_start = 0;
    buffer_end = 0;
}


static int reallocate_buffer(void)
{
    size_t new_capacity;
    char *tmp;

    new_capacity = buffer_capacity == 0 ? INITIAL_BUFFER_SIZE : buffer_capacity * BUFFER_GROWTH_FACTOR;
    // Add +1 for null terminator
    tmp = malloc(new_capacity + 1);
    if (!tmp)
        return (-1);
    if (buffer)
    {
        ft_memcpy(tmp, buffer + buffer_start, buffer_end - buffer_start);
        free(buffer);
    }
    buffer = tmp;
    buffer_end -= buffer_start;
    buffer_start = 0;
    buffer_capacity = new_capacity;
    return (0);
}


static int ensure_buffer_capacity(size_t needed_size)
{
    if (!buffer || buffer_capacity < needed_size)
        return (reallocate_buffer());
    return (0);
}

char *get_next_line(int fd)
{
    char *eol_ptr;
    int bytes_read;

    if (fd < 0)
        return (NULL);
    while (1)
    {
        // Ensure we have space for BUFFER_SIZE + null terminator
        if (ensure_buffer_capacity(buffer_end + BUFFER_SIZE + 1) < 0)
            return (NULL);
        bytes_read = read(fd, buffer + buffer_end, BUFFER_SIZE);
        if (bytes_read < 0)
        {
            cleanup_buffer();
            return (NULL);
        }
        buffer_end += bytes_read;
        buffer[buffer_end] = '\0';
        eol_ptr = ft_strchr(buffer + buffer_start, '\n');
        if (eol_ptr)
        {
            size_t line_len = eol_ptr - (buffer + buffer_start) + 1;
            // Add +1 for null terminator
            char *return_str = malloc(line_len + 1);
            if (!return_str)
                return (NULL);
            ft_memcpy(return_str, buffer + buffer_start, line_len);
            return_str[line_len] = '\0';
            buffer_start += line_len;
            return (return_str);
        }
        if (bytes_read == 0)
        {
            if (buffer_start >= buffer_end)
            {
                cleanup_buffer();
                return (NULL);
            }
            size_t remaining = buffer_end - buffer_start;
            char *return_str = malloc(remaining + 1);
            if (!return_str)
                return (NULL);
            ft_memcpy(return_str, buffer + buffer_start, remaining);
            return_str[remaining] = '\0';
            cleanup_buffer();
            return (return_str);
        }
    }
}