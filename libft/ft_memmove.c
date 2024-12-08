/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tafanasi <tafanasi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 16:57:20 by tafanasi          #+#    #+#             */
/*   Updated: 2024/12/07 21:37:13 by tafanasi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>

void *memmove(void *dest, const void *src, size_t n)
{	
	//allocate an array of N size
	unsigned char *temp_arr = malloc(n);
	if (!temp_arr)
    	return NULL;
	//create pointers both for dest and src
	const unsigned char *src_ptr = (const unsigned char *)src;
	unsigned char *dest_ptr = (unsigned char *)dest;
	//i to count moved 8 bits
	int i = 0;
	size_t temp_n = n;
	while(temp_n > 0){
		temp_arr[i] = src_ptr[i];
		temp_n--;
		i++;
	}
	//cp to dest
	i = 0;
	while(n > 0){
		dest_ptr[i] = temp_arr[i];
		n--;
	}
	//FREE THE GOD DAMN MEMORY
	free(temp_arr);
	//return the abomination
	return dest;
}
/*
int main(void){
	char test1[] = "hello";
	char test2[] = "xxxxx";
	char *test3 = memmove(test1, test2, 5);
	printf("%s\n", test3);
	return(0);
}
*/
