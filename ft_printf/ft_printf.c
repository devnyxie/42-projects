
#include <stdarg.h>
#include <stdint.h>
#include <stdlib.h>
#include <unistd.h>

int	ft_putstr(char *s)
{
	int	i;

	i = 0;
	while (s[i])
		write(1, &s[i++], 1);
	return (i);
}

// int	ft_putnbr_base(unsigned long value, char *base)
// {
// 	int	base_len;
// 	int	len;

// 	base_len = 0;
// 	len = 0;
// 	while (base[base_len])
// 		base_len++;
// 	if (base_len < 2)
// 		return (0);
// 	if (value >= (unsigned long)base_len)
// 		len += ft_putnbr_base(value / base_len, base);
// 	write(1, &base[value % base_len], 1);
// 	return (len + 1);
// }

// base 1 = 0123456789
// base 2 = 0123456789abcdef
// int	ft_putnbr_base(unsigned long value, char *base)
// {
// 	int	base_len;
// 	int	len;

// 	base_len = 0;
// 	len = 0;
// 	while (base[base_len])
// 		base_len++;
// 	if (value >= (unsigned long)base_len)
// 		len += ft_putnbr_base(value / base_len, base);
// 	write(1, &base[value % base_len], 1);
// 	return (len + 1);
// }

int	ft_putnbr_base(unsigned long value, int base_type)
{
	char	*base;
	int		base_len;
	int		len;

	if (base_type == 1)
	{
		base = "0123456789";
	}
	else if (base_type == 2)
	{
		base = "0123456789abcdef";
	}
	else if (base_type == 3)
	{
		base = "0123456789ABCDEF";
	}
	base_len = 0;
	len = 0;
	while (base[base_len])
		base_len++;
	if (value >= (unsigned long)base_len)
		len += ft_putnbr_base(value / base_len, base_type);
	write(1, &base[value % base_len], 1);
	return (len + 1);
}

int	ft_printf(const char *str, ...)
{
	va_list	args;
	char	c;
	int		len;

	va_start(args, str);
	len = 0;
	while (*str)
	{
		if (*str == '%')
		{
			str++;
			if(*str == '\0')
				break;
			if (*str == 'c')
			{
				c = va_arg(args, int);
				len += write(1, &c, 1);
			}
			else if (*str == 's')
			{
				char *s = va_arg(args, char *);
				if (s == NULL) // If the string is NULL, print "(null)"
					len += write(1, "(null)", 6);
				else
					len += ft_putstr(s);
			}
			else if (*str == 'p')
			{
				len += ft_putstr("0x");
				len += ft_putnbr_base(va_arg(args, unsigned long), 2);
			}
			else if (*str == 'd' || *str == 'i')
				len += ft_putnbr_base(va_arg(args, int), 1);
			else if (*str == 'u')
				len += ft_putnbr_base(va_arg(args, unsigned int), 1);
			else if (*str == 'x')
				len += ft_putnbr_base(va_arg(args, unsigned int), 2);
			else if (*str == 'X')
				len += ft_putnbr_base(va_arg(args, unsigned int), 3);
			else if (*str == '%')
				len += write(1, "%", 1);
		}
		else
			len += write(1, str, 1);
		str++;
	}
	va_end(args);
	return (len);
}

// int	ft_printf(const char *str, ...)
// {
// 	va_list	args;
// 	char	c;
// 	int		len;

// 	va_start(args, str);
// 	len = 0;
// 	while (*str)
// 	{
// 		if (*str == '%')
// 		{
// 			str++;
// 			if (*str == 'c')
// 			{
// 				c = va_arg(args, int);
// 				len += write(1, &c, 1);
// 			}
// 			else if (*str == 's')
// 				len += ft_putstr(va_arg(args, char *));
// 			else if (*str == 'p')
// 			{
// 				len += ft_putstr("0x");
// 				len += ft_putnbr_base(va_arg(args, unsigned long),
// 						"0123456789abcdef");
// 			}
// 			else if (*str == 'd' || *str == 'i')
// 				len += ft_putnbr_base(va_arg(args, int), "0123456789");
// 			else if (*str == 'u')
// 				len += ft_putnbr_base(va_arg(args, unsigned int), "0123456789");
// 			else if (*str == 'x')
// 				len += ft_putnbr_base(va_arg(args, unsigned int),
// 						"0123456789abcdef");
// 			else if (*str == 'X')
// 				len += ft_putnbr_base(va_arg(args, unsigned int),
// 						"0123456789ABCDEF");
// 			else if (*str == '%')
// 				len += write(1, "%", 1);
// 		}
// 		else
// 			len += write(1, str, 1);
// 		str++;
// 	}
// 	va_end(args);
// 	return (len);
// }
