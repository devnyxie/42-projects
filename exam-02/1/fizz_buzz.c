#include <unistd.h>

void ft_putnbr(int number)
{
    if (number > 9)
        ft_putnbr(number / 10);
    number = number % 10 + '0';
    write (1, &number, 1);
}

int main()
{
    int number;

    number = 1;
    while (number <= 100)
    {
        if (number % 3 == 0)
            write(1, "fizz", 4);
        else if (number % 5 == 0)
            write(1, "buzz", 4);
        else if ((number % 5 == 0) && (number % 3 == 0))
            write(1, "fizzbuzz", 8);
        else
            ft_putnbr(number);
        write(1, "\n", 1);
        number++;
    }
    return (0);
}