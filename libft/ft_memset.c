/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tafanasi <tafanasi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 13:34:16 by tafanasi          #+#    #+#             */
/*   Updated: 2024/12/03 13:50:24 by tafanasi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

// s = block to fill
// c = the value to set
void *ft_memset(void *s, int c, size_t size) {
	unsigned char *ptr = (unsigned char *)s; 
	while(size--){
		*ptr = (unsigned char)c;
		ptr++;
	}
	return s;
}
