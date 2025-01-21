#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <unistd.h>

#define FD_LIMIT 1024
#define CHUNK_SIZE 8

char *buffer[FD_LIMIT] = {NULL};

char	*ft_strchr(const char *str, int c)
{
	while (*str != '\0')
	{
		if (*str == (char)c)
		{
			return ((char *)str);
		}
		str++;
	}
	if (c == '\0')
	{
		return ((char *)str);
	}
	return (NULL);
}

void ft_strncpy(char *dest, char *src, int n) {
    int i = 0;
    while (i < n) {
        dest[i] = src[i];
        i++;
    }
    dest[i] = '\0';
}

void ft_memmove(void *dest, const void *src, size_t n) {
    char *d = dest;
    const char *s = src;
    if (d < s) {
        while (n--) {
            *d++ = *s++;
        }
    } else {
        d += n;
        s += n;
        while (n--) {
            *--d = *--s;
        }
    }
}

char	*ft_strdup(const char *src)
{
	unsigned int	size;
	char			*dup;
	char			*temp_ptr;

	if (!src)
		return (NULL);
	size = 0;
	while (src[size])
	{
		size++;
	}
	dup = (char *)malloc((size + 1) * sizeof(char));
	if (!dup)
		return (NULL);
	temp_ptr = dup;
	while (*src)
	{
		*temp_ptr = *src;
		temp_ptr++;
		src++;
	}
	*temp_ptr = '\0';
	return (dup);
}

int ft_strlen(char *str) {
	int i = 0;
	while (str[i]) {
		i++;
	}
	return i;
}

void ft_strcpy(char *dest, char *src) {
	int i = 0;
	while (src[i]) {
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
}


char *get_next_line(int fd) {
    if (fd < 0 || fd >= FD_LIMIT) {
        fprintf(stderr, "Invalid file descriptor\n");
        return NULL;
    }

    while (1) {
        // Initialize the buffer for the given fd
        if (!buffer[fd]) {
            buffer[fd] = (char *)malloc((CHUNK_SIZE + 1) * sizeof(char));
            if (!buffer[fd]) {
                fprintf(stderr, "Memory allocation failed\n");
                return NULL;
            }
            buffer[fd][0] = '\0';
        }

        // Read from the file descriptor
        int offset = ft_strlen(buffer[fd]);
        int bytes_read = read(fd, buffer[fd] + offset, CHUNK_SIZE);
        if (bytes_read < 0) {
            perror("Read error");
            free(buffer[fd]);
            buffer[fd] = NULL;
            return NULL;
        }
        buffer[fd][offset + bytes_read] = '\0';

        // Check for a newline
        char *newline_pos = ft_strchr(buffer[fd], '\n');
        if (newline_pos) {
            // Allocate space for the line to return
            int line_length = newline_pos - buffer[fd] + 1; // Include the newline
            char *line = (char *)malloc((line_length + 1) * sizeof(char));
            if (!line) {
                fprintf(stderr, "Memory allocation failed\n");
                free(buffer[fd]);
                buffer[fd] = NULL;
                return NULL;
            }
            strncpy(line, buffer[fd], line_length);
            line[line_length] = '\0';

            // Shift the remaining buffer content
            ft_memmove(buffer[fd], newline_pos + 1, ft_strlen(newline_pos + 1) + 1);
            return line;
        }

        // If EOF is reached
        if (bytes_read == 0) {
            if (buffer[fd][0] != '\0') {
                // Return remaining content in the buffer
                char *line = ft_strdup(buffer[fd]);
                free(buffer[fd]);
                buffer[fd] = NULL;
                return line;
            }
            free(buffer[fd]);
            buffer[fd] = NULL;
            return NULL;
        }
    }
}
