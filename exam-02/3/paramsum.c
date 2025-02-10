#include <unistd.h>
#include <stdio.h>

void	ft_putnbr(int n)
{
	if (n > 9)
		ft_putnbr(n/10);
	n = (n % 10) + '0';
	write(1, &n, 1);
}

int main(int argc, char **argv)
{
	int	numbers = 0;
	(void) argv;
	numbers = argc -1;
	if (argc == 1)
		write(1, "0\n", 2);
	else
	{
		ft_putnbr(numbers);
		write(1, "\n", 1);
	}
}