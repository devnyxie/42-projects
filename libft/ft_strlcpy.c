/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tafanasi <tafanasi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 20:57:10 by tafanasi          #+#    #+#             */
/*   Updated: 2024/12/07 23:26:55 by tafanasi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h> 

size_t strlcpy(char *dest, const char *src, size_t size)
{
	// find size of src in order not to overlap
	size_t src_len = 0;
	size_t i = 0;
	while(src[src_len] != '\0')
		src_len++;
	// if src_size is above 0, continue
	if(size > 0)
	{
		// copy until:
		// i becomes (size - 1)
		// and
		// src[i] is not null ptr
		while(size > i && src[i] != '\0'){
			dest[i] = src[i];
			i++;
		}
		dest[i] = '\0';
	}
	return(src_len);
}
