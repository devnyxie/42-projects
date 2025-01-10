/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tafanasi <tafanasi@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 04:02:48 by tafanasi          #+#    #+#             */
/*   Updated: 2025/01/10 04:47:20 by tafanasi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
#define FT_PRINTF_H

#include <stdarg.h>
#include <stdlib.h>
#include <unistd.h>
// #include "libft.h"

int ft_printf(const char *str, ...);
void ft_handle_specifiers(char current_char, int *len, va_list args);
int ft_putstr(char *s);
int ft_putnbr(int n);
int ft_putnbr_base(unsigned long value, int specifier);
char *ft_strchr(const char *str, int c);

#endif