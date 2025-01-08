
#include <unistd.h>
#include <stdarg.h>
#include <stdlib.h>
#include "libft.h"

char *ft_itoa_base(unsigned long value, char *base) {
    char *str;
    unsigned long tmp;
    int base_len;
    int len;

    base_len = 0;
    while (base[base_len])
        base_len++;
    if (base_len < 2)
        return (NULL);
    tmp = value;
    len = 1;
    while (tmp /= base_len)
        len++;
    if (!(str = (char *)malloc(sizeof(char) * (len + 1))))
        return (NULL);
    str[len] = '\0';
    while (len--) {
        str[len] = base[value % base_len];
        value /= base_len;
    }
    return (str);
}

void ft_printf(char *str, ...){
    va_list args;
    va_start(args, str);

    // ft_putstr_fd(NULL, 1); FAILS

    while(*str){
        // print args
        if(*str == '%'){
            str++;
        if (*str == 'c') {
            char c = va_arg(args, int);
            write(1, &c, 1);
        } else if (*str == 's') {
            char *s = va_arg(args, char *);
            ft_putstr_fd(s, 1);
        } else if (*str == 'p') {
            ft_putstr_fd("0x", 1);
            ft_putstr_fd(ft_itoa_base(va_arg(args, unsigned long), "0123456789abcdef"), 1);
        } else if (*str == 'd' || *str == 'i') {
            ft_putstr_fd(ft_itoa(va_arg(args, int)), 1);
        } else if (*str == 'u') {
            ft_putstr_fd(ft_itoa(va_arg(args, unsigned int)), 1);
        } else if (*str == 'x') {
            ft_putstr_fd(ft_itoa_base(va_arg(args, unsigned int), "0123456789abcdef"), 1);
        } else if (*str == 'X') {
            ft_putstr_fd(ft_itoa_base(va_arg(args, unsigned int), "0123456789ABCDEF"), 1);
        } else if (*str == '%') {
            write(1, "%", 1);
        }
        } else {
            // print all other characters
            write(1, str, 1);
        }
        str++;
    }
    va_end(args);
    return;
}

int main() {
    // Test cases for ft_printf
    ft_printf("Hello, World!\n");
    ft_printf("Integer: %d\n", -42);
    ft_printf("String: %s\n", "Test string");
    ft_printf("Character: %c\n", 'A');
    ft_printf("Hexadecimal: %x\nHexadecimal: %x\n", 255, 112);
    ft_printf("Pointer: %p\n", (void*)main);

    return 0;
}