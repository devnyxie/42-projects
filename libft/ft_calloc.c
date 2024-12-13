
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
#include <stdint.h>

void *ft_calloc(size_t nmemb, size_t size)
{
	if (nmemb != 0 && size > SIZE_MAX / nmemb) {
        return NULL;  // Memory allocation would overflow
    }
    void *arr = malloc(nmemb * size);
    if (arr == NULL) {
        return NULL;
    }

    unsigned char *ptr = (unsigned char *)arr;
    for (size_t i = 0; i < (nmemb * size); i++) {
        ptr[i] = 0;
    }

    return arr;
}

int main(void){
	int *arr = (int *)ft_calloc(5, sizeof(int));
	if(arr == NULL){
		printf("Error - not allocated");
		return(0);
	}
    	for (int i = 0; i < 5; i++) {
        	printf("%d\n", arr[i]);  // Safely access each element
    	}

    	free(arr);  // Free allocated memory
	return(0);
}
