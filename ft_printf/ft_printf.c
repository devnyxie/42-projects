#include <stdarg.h>
#include <stdint.h>
#include <stdlib.h>
#include <unistd.h>
#include "libft.h"

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


static void ft_handle_specifiers(char current_char, char *c, char *temp_s, int *len, va_list args)
{
	unsigned long	ptr;
	
	if (current_char == 'c')
	{
		*c = va_arg(args, int);
		*len += write(1, c, 1);
	}
	else if (current_char == 's')
	{
		temp_s = va_arg(args, char *);
		if (temp_s == NULL)
			*len += write(1, "(null)", 6);
		else
			*len += ft_putstr(temp_s);
	}
	else if (current_char == 'p')
	{
		ptr = va_arg(args, unsigned long);
		if(!ptr)
			*len += ft_putstr("(nil)");
		else
			*len += ft_putstr("0x") + ft_putnbr_base(ptr, current_char);
	}
	else if (ft_strchr("uxX", current_char))
		*len += ft_putnbr_base(va_arg(args, unsigned int), current_char);
	else if (current_char == 'd' || current_char == 'i')
		*len += ft_putnbr(va_arg(args, int));
	else if (current_char == '%')
		*len += write(1, "%", 1);
}

int	ft_printf(const char *str, ...)
{
	va_list		args;
	char		c;
	char		*temp_s;
	int			len;

	va_start(args, str);
	temp_s = NULL;
	len = 0;
	while (*str)
	{
		if (*str == '%')
		{
			str++;
			if (*str == '\0')
				break ;
			ft_handle_specifiers(*str, &c, temp_s, &len, args);
		}
		else
			len += write(1, str, 1);
		str++;
	}
	va_end(args);
	return (len);
}
