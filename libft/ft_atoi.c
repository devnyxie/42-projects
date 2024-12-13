/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tafanasi <tafanasi@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 20:00:29 by tafanasi          #+#    #+#             */
/*   Updated: 2024/12/13 21:25:02 by tafanasi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <limits.h>
#include <stdio.h>
#include <stdlib.h>

int	ft_atoi(const char *str)
{
	int	last_digit;

	int digit = 0; // res
	int pos = 1;   // sign
	while (*str == ' ' || *str == '\t' || *str == '\n' || *str == '\r'
		|| *str == '\v' || *str == '\f')
	{
		str++;
	}
	if (*str == '-')
	{
		pos = -1;
		str++;
	}
	else if (*str == '+')
	{
		pos = 1;
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		last_digit = *str - '0';
		// check for overflow if we add last_diti-
		if (digit > (INT_MAX - last_digit) / 10)
		{
			if (pos == 1)
			{
				return (INT_MAX);
			}
			else
			{
				return (INT_MIN);
			}
		}
		digit = (digit * 10) + last_digit;
		str++;
	}
	return (pos * digit);
}

// int main(void){
//     int res1 = atoi("-20");
//     int res2 = atoi("202020");
//     int res3 = atoi("2147483648");
//     int res4 = atoi("--2147483648");
//     int res5 = atoi("2147483647");
//     int res6 = atoi("2147483648");
//     int res7 = atoi("   42");
//     int res8 = atoi("abc123");
//     int res9 = atoi("12abc34");
//     int res10 = atoi("   ");

//     printf("atoi --- 1: %d, 2: %d, 3: %d, 4: %d, 5: %d, 6: %d, 7: %d, 8: %d,
	9: %d, 10: %d\n",
//            res1, res2, res3, res4, res5, res6, res7, res8, res9, res10);

//     int res11 = ft_atoi("-20");
//     int res12 = ft_atoi("202020");
//     int res13 = ft_atoi("2147483648");
//     int res14 = ft_atoi("--2147483648");
//     int res15 = ft_atoi("2147483647");
//     int res16 = ft_atoi("2147483648");
//     int res17 = ft_atoi("   42");
//     int res18 = ft_atoi("abc123");
//     int res19 = ft_atoi("12abc34");
//     int res20 = ft_atoi("   ");

//     printf("ft_atoi --- 11: %d, 12: %d, 13: %d, 14: %d, 15: %d, 16: %d, 17:
	%d, 18: %d, 19: %d, 20: %d\n",
//            res11, res12, res13, res14, res15, res16, res17, res18, res19,
	res20);

// 	return(0);
// }
