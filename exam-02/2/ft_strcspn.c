#include <stdio.h>

size_t	ft_strcspn(const char *s, const char *reject)
{
	int	i;
	int j;

	i = 0;
	while (s[i])
	{
		j = 0;
		while (reject[j])
		{
			if (reject[j] == s[i])
				return (i);
			j++;
		}
		i++;
	}
	i = 0;
	while (s[i])
		i++;
	return (i);
}

/*int main(int argc, char **argv)
{
	printf("%zd\n", ft_strcspn(argv[1], argv[2]));
}*/
