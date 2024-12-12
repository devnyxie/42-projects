/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tafanasi <tafanasi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/08 03:37:21 by tafanasi          #+#    #+#             */
/*   Updated: 2024/12/08 03:44:41 by tafanasi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

int ft_memcmp(const void *s1, const void *s2, size_t n)
{
	const unsigned char *s1_ptr = (const unsigned char *)s1;
	const unsigned char *s2_ptr = (const unsigned char *)s2;
	size_t i = 0;	

	while(i < n){
		if(s1_ptr[i] != s2_ptr[i]){
			return s1_ptr[i] - s2_ptr[i];
		}
		i++;
	}

	return(0);
}
