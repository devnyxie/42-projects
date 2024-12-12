
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tafanasi <tafanasi@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 05:41:03 by tafanasi          #+#    #+#             */
/*   Updated: 2024/12/11 06:17:15 by tafanasi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>

void *ft_calloc(size_t nmemb, size_t size)
{
	void *arr = (unsigned int *)malloc(nmemb * size);
	if(arr == NULL) {
		return NULL;
	}
	size_t i = 0;
	//a char in C is always one byte;
	//therefore, in order to fill the array, no matter the type
	//we have to cast it to unsigned char.
	unsigned char *ptr = (unsigned char *)arr;
	while (i < (nmemb * size)) {
		ptr[i] = 0;
		i++;
	}
	return (void *)arr;
}

// int main(void){
// 	int *arr = (int *)ft_calloc(5, sizeof(int));
// 	if(arr == NULL){
// 		printf("Error - not allocated");
// 		return(0);
// 	}
//     	for (int i = 0; i < 5; i++) {
//         	printf("%d\n", arr[i]);  // Safely access each element
//     	}

//     	free(arr);  // Free allocated memory
// 	return(0);
// }
