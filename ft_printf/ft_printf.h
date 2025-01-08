#ifndef FT_PRINTF_H
#define FT_PRINTF_H

#include <stdarg.h>
#include <stdlib.h>
#include <unistd.h>

char *ft_itoa(int n);
char *ft_itoa_base(unsigned long value, char *base);
void ft_putstr_fd(char *s, int fd);
void ft_printf(char *str, ...);

#endif