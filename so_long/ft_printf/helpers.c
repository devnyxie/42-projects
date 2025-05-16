/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tafanasi <tafanasi@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 04:26:57 by tafanasi          #+#    #+#             */
/*   Updated: 2025/01/15 14:46:08 by tafanasi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putstr(char *s)
{
	int	i;

	i = 0;
	while (s[i])
		write(1, &s[i++], 1);
	return (i);
}

int	ft_putnbr_base(unsigned long value, int specifier)
{
	char	*base;
	int		base_len;
	int		len;

	if (specifier == 'u')
		base = "0123456789";
	else if (specifier == 'x' || specifier == 'p')
		base = "0123456789abcdef";
	else if (specifier == 'X')
		base = "0123456789ABCDEF";
	base_len = 0;
	len = 0;
	while (base[base_len])
		base_len++;
	if (value >= (unsigned long)base_len)
		len += ft_putnbr_base(value / base_len, specifier);
	write(1, &base[value % base_len], 1);
	return (len + 1);
}

int	ft_putnbr(int n)
{
	char	num;
	int		len;

	len = 0;
	if (n == -2147483648)
	{
		len += write(1, "-2147483648", 11);
	}
	else if (n < 0)
	{
		len += write(1, "-", 1);
		len += ft_putnbr(n * (-1));
	}
	else if (n > 9)
	{
		len += ft_putnbr(n / 10);
		len += ft_putnbr(n % 10);
	}
	else
	{
		num = n + '0';
		len += write(1, &num, 1);
	}
	return (len);
}

// char	*ft_strchr(const char *str, int c)
// {
// 	while (*str != '\0')
// 	{
// 		if (*str == (char)c)
// 		{
// 			return ((char *)str);
// 		}
// 		str++;
// 	}
// 	if (c == '\0')
// 	{
// 		return ((char *)str);
// 	}
// 	return (NULL);
// }
