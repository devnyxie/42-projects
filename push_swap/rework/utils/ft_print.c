#include "../includes/push_swap.h"

void ft_print(const char *str)
{
    if (str)
    {
        while (*str)
        {
            write(1, str, 1);
            str++;
        }
    }
}