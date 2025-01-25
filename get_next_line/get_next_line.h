#ifndef GET_NEXT_LINE_H
#   define GET_NEXT_LINE_H

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 8
#endif

#ifndef FD_SIZE
#   define FD_SIZE 1024
#endif

// malloc, size_t etc
#include <stdlib.h>
// read etc
#include <unistd.h>
// printf
#include <stdio.h>


char *get_next_line(int fd);
char *ft_strchr(const char *s, int c);
size_t ft_strlen(const char *s);
void *ft_memmove(void *dest, const void *src, size_t n);
void *ft_memcpy(void *dest, const void *src, size_t n);

#endif