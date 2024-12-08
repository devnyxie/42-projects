/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tafanasi <tafanasi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/08 01:08:15 by tafanasi          #+#    #+#             */
/*   Updated: 2024/12/08 03:27:47 by tafanasi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
1. move to the end of the dest by creating a new ptr
2. 
*/

#include <stdio.h>
#include <stddef.h>

size_t strlcat(char *dest, const char *src, size_t size)
{
    char *dest_ptr = dest;
    const char *src_ptr = src;
    size_t dest_len = 0;
    size_t src_len = 0;

    // Find the length of the existing dest string
    while (*dest_ptr && dest_len < size) {
        dest_ptr++;
        dest_len++;
    }

    // Calculate the length of src
    while (src[src_len]) {
        src_len++;
    }

    // If size is less than or equal to dest_len, return size + src_len
    if (size <= dest_len) {
        return size + src_len;
    }

    // Append src to dest
    size_t copy_len = size - dest_len - 1; // Space left for actual copying and null-terminator
    while (*src_ptr && copy_len > 0) {
        *dest_ptr = *src_ptr;
        dest_ptr++;
        src_ptr++;
        copy_len--;
    }

    // Null-terminate the string
    if (dest_len < size) {
        *dest_ptr = '\0';
    }

    // Return the total length of the string it tried to create
    return dest_len + src_len;
}

/*
int main(void)
{
	char	dest[100] = "hello";
	char	*src = "XXXXXXXXXXX";

	size_t result = strlcat(dest, src, 15);
	
	printf("%s\n", dest);
	printf("%ld\n", result);	

	return(0);
}
*/


