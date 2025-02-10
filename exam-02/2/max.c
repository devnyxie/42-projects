int		max(int* tab, unsigned int len)
{
	int count = 0;
	int result = 0;
	int i = 0;
	if (len > 0)
	{
		while (count < len)
		{
			if (tab[i] > result)
				result = tab[i];
			i++;
			count++;
		}
		return (result);
	}
	return (0);
}

/*#include <stdio.h>

int main()
{
	int mark[] = {1, 3, 2, 10, 9};
	printf("%d", max(mark, 5));
}*/
