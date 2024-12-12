/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tafanasi <tafanasi@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 16:29:33 by tafanasi          #+#    #+#             */
/*   Updated: 2024/12/12 17:59:37 by tafanasi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

// Create a duplicate of the given string using malloc
char *ft_strdup(const char *src)
{
    if (!src) return NULL; // Check if the input string is valid

    // Calculate string size
    unsigned int size = 0;
    while (src[size]) {
        size++;
    }

    // Allocate memory (+1 for null terminator)
    char *dup = (char *)malloc((size + 1) * sizeof(char));
    if (!dup) return NULL; // Check if allocation was successful

    // Copy string content
    char *temp_ptr = dup;
    while (*src) {
        *temp_ptr = *src;
        temp_ptr++;
        src++;
    }
    *temp_ptr = '\0';

    return dup;
}
/*
int main(void){
	char *s = "Hello";
	char *ptr = ft_strdup(s);
	printf("output: %s", ptr);
	free(ptr);
	return(0);
}
*/