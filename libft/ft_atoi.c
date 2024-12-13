/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tafanasi <tafanasi@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 20:00:29 by tafanasi          #+#    #+#             */
/*   Updated: 2024/12/13 22:34:03 by tafanasi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <limits.h>
#include <stdio.h>
#include <stdlib.h>

const char	*skip_spaces(const char *str)
{
	while (*str == ' ' || *str == '\t' || *str == '\n' || *str == '\v'
		|| *str == '\f' || *str == '\r')
		str++;
	return (str);
}

// we have to return the modified pointer
const char	*manage_pos(const char *str, int *pos)
{
	if (*str == '-')
	{
		*pos = -1;
		str++;
	}
	else if (*str == '+')
	{
		*pos = 1;
		str++;
	}
	return (str);
}

int	ft_atoi(const char *str)
{
	int	last_digit;
	int	digit;
	int	pos;

	digit = 0;
	pos = 1;
	str = skip_spaces(str);
	str = manage_pos(str, &pos);
	while (*str >= '0' && *str <= '9')
	{
		last_digit = *str - '0';
		if (digit > (INT_MAX - last_digit) / 10)
		{
			if (pos == 1)
				return (INT_MAX);
			else
				return (INT_MIN);
		}
		digit = (digit * 10) + last_digit;
		str++;
	}
	return (pos * digit);
}
