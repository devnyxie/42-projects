/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tafanasi <tafanasi@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 17:08:19 by tafanasi          #+#    #+#             */
/*   Updated: 2024/12/16 17:17:06 by tafanasi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_numlen(int n, int base)
{
	int	count;

	count = 0;
	if (n <= 0)
		++count;
	while (n && ++count)
		n /= base;
	return (count);
}

static int	get_num_length(int n)
{
	int	length;

	length = 0;
	if (n <= 0)
	{
		length++;
		n = -n;
	}
	while (n != 0)
	{
		n /= 10;
		length++;
	}
	return (length);
}

char	*ft_itoa(int n)
{
	int		len;
	char	*str;
	long	num;

	num = n;
	len = get_num_length(n);
	str = (char *)ft_calloc(sizeof(char), (len + 1));
	if (!str)
		return (NULL);
	str[len] = '\0';
	if (num < 0)
	{
		str[0] = '-';
	}
	if (num < 0)
	{
		num = -num;
	}
	while (--len >= 0 && str[len] != '-')
	{
		str[len] = (num % 10) + '0';
		num /= 10;
	}
	return (str);
}

// int main(void)
// {
//     int test_values[] = {0, 123, -123, 2147483647, -2147483648};
//     char *result;

//     for (int i = 0; i < 5; i++)
//     {
//         result = ft_itoa(test_values[i]);
//         if (result)
//         {
//             printf("ft_itoa(%d) = %s\n", test_values[i], result);
//             free(result);
//         }
//         else
//         {
//             printf("ft_itoa(%d) failed to allocate memory.\n",
//             test_values[i]);
//         }
//     }
//     return (0);
// }