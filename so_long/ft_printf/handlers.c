/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handlers.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tafanasi <tafanasi@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 04:02:25 by tafanasi          #+#    #+#             */
/*   Updated: 2025/01/15 14:45:39 by tafanasi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_handle_char(int *len, va_list args);
static void	ft_handle_string(int *len, va_list args);
static void	ft_handle_pointer(int *len, va_list args);
static void	ft_handle_number(char specifier, int *len, va_list args);

void	ft_handle_specifiers(char current_char, int *len, va_list args)
{
	if (current_char == 'c')
		ft_handle_char(len, args);
	else if (current_char == 's')
		ft_handle_string(len, args);
	else if (current_char == 'p')
		ft_handle_pointer(len, args);
	else if (ft_strchr("uxXdi", current_char))
		ft_handle_number(current_char, len, args);
	else if (current_char == '%')
		*len += write(1, "%", 1);
}

static void	ft_handle_char(int *len, va_list args)
{
	char	c;

	c = va_arg(args, int);
	*len += write(1, &c, 1);
}

static void	ft_handle_string(int *len, va_list args)
{
	char	*temp_s;

	temp_s = va_arg(args, char *);
	if (temp_s == NULL)
		*len += write(1, "(null)", 6);
	else
		*len += ft_putstr(temp_s);
}

static void	ft_handle_pointer(int *len, va_list args)
{
	unsigned long	ptr;

	ptr = va_arg(args, unsigned long);
	if (!ptr)
		*len += ft_putstr("(nil)");
	else
		*len += ft_putstr("0x") + ft_putnbr_base(ptr, 'p');
}

static void	ft_handle_number(char specifier, int *len, va_list args)
{
	if (specifier == 'd' || specifier == 'i')
		*len += ft_putnbr(va_arg(args, int));
	else if (ft_strchr("uxX", specifier))
		*len += ft_putnbr_base(va_arg(args, unsigned int), specifier);
}
