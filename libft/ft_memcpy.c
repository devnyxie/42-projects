/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tafanasi <tafanasi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 17:06:06 by tafanasi          #+#    #+#             */
/*   Updated: 2024/12/05 17:50:38 by tafanasi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void *memcpy(void *dest, const void *src, size_t n)
{
	size_t i = 0;
	unsigned char *src_ptr = (const unsigned char *)src;
	unsigned char *dest_ptr = (unsigned char *)dest;
	while(i < n){
		dest_ptr[i] = src_ptr[i];
		i++;
	}
	return dest;
}
