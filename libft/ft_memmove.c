/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tafanasi <tafanasi@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 16:57:20 by tafanasi          #+#    #+#             */
/*   Updated: 2024/12/13 23:02:37 by tafanasi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char		*d;
	const unsigned char	*s = (const unsigned char *)src;
	size_t				i;

	d = (unsigned char *)dest;
	i = 0;
	if (d < s || d >= s + n)
	{
		while (i < n)
		{
			d[i] = s[i];
			i++;
		}
	}
	else
	{
		while (i > n)
		{
			d[i - 1] = s[i - 1];
			i--;
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
