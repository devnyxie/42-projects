#include <unistd.h>

int main (int argc, char **a)
{
	if (argc == 2)
	{
		int i = 0;

		while (a[1][i])
			i++;
		i--;
		while (a[1][i] > 32)
			i--;
		i++;
		while (a[1][i])
		{
			write(1, &a[1][i], 1);
			i++;
		}
	}
	write (1, "\n", 1);
}
