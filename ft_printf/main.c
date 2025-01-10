#include "ft_printf.h"

int main(void)
{
    // basic tests
    ft_printf("Basic tests:\n");
    ft_printf("Character: %c\n", 'A');
    ft_printf("String: %s\n", "Hello World");
    ft_printf("Pointer: %p\n", (void *)main);
    ft_printf("Integer: %d or %i\n", 42, -42);
    ft_printf("Unsigned: %u\n", 42);
    ft_printf("Hexadecimal: %x or %X\n", 255, 255);
    ft_printf("Percent sign: %%\n");
    ft_printf("Multiple: %d %s %c\n", 42, "test", '!');

    return (0);
}