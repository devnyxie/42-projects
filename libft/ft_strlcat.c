/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tafanasi <tafanasi@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/08 01:08:15 by tafanasi          #+#    #+#             */
/*   Updated: 2024/12/13 21:32:22 by tafanasi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <stdio.h>

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	dest_len;
	size_t	src_len;
	size_t	copy_len;

	dest_len = 0;
	src_len = 0;
	while (dest[dest_len] && dest_len < size)
		dest_len++;
	while (src[src_len])
		src_len++;
	if (size <= dest_len)
		return (size + src_len);
	copy_len = size - dest_len - 1;
	while (*src && copy_len--)
		dest[dest_len++] = *src++;
	if (dest_len < size)
		dest[dest_len] = '\0';
	return (dest_len + src_len);
}

/*
int	main(void)
{
	char	dest[100] = "hello";
	char	*src;
	size_t	result;

	src = "XXXXXXXXXXX";
	result = strlcat(dest, src, 15);
	printf("%s\n", dest);
	printf("%ld\n", result);
	return(0);
}
*/
