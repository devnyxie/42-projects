/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tafanasi <tafanasi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 23:32:45 by tafanasi          #+#    #+#             */
/*   Updated: 2024/12/13 21:20:10 by tafanasi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <stdio.h>

void	*ft_memchr(const void *s, int c, size_t n)
{
	const unsigned char	*s_ptr = (const unsigned char *)s;

	while (n > 0)
	{
		if (*s_ptr == (unsigned char)c)
			return ((void *)s_ptr);
		n--;
		s_ptr++;
	}
	return (NULL);
}

/*
int	main(void){
	char *s = "hello";
	char c = 'o';
	size_t n = 5;
	char *ptr = ft_memchr(s, c, n);
	printf("%s", ptr);
	return(0);
}
*/
