#include <unistd.h>

void    ft_putstr(char *str)
{
    int i;

    i = 0;
    while (str[i])
        write(1, &str[i++], 1);
}


void	ft_putstr(char *str)
{
	
}


/*int main()
{
    char    *hello;

    hello = "hello";
    ft_putstr(hello);
}*/