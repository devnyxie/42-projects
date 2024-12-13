/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tafanasi <tafanasi@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 16:57:20 by tafanasi          #+#    #+#             */
/*   Updated: 2024/12/13 21:16:36 by tafanasi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char		*d;
	const unsigned char	*s = (const unsigned char *)src;

	d = (unsigned char *)dest;
	if (d < s || d >= s + n)
	{
		for (size_t i = 0; i < n; i++)
		{
			d[i] = s[i];
		}
	}
	else
	{
		for (size_t i = n; i > 0; i--)
		{
			d[i - 1] = s[i - 1];
		}
	}
	return (dest);
}

/*
int	main(void){
	char test1[] = "hello";
	char test2[] = "xxxxx";
	char *test3 = memmove(test1, test2, 5);
	printf("%s\n", test3);
	return(0);
}
*/
