/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tafanasi <tafanasi@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/08 03:49:57 by tafanasi          #+#    #+#             */
/*   Updated: 2024/12/13 20:24:20 by tafanasi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdio.h>

char *ft_strnstr(const char *big, const char *little, size_t len) {
    if (*little == '\0') {
        return (char *)big;
    }

    size_t i = 0;
    size_t little_len = 0;
    while (little[little_len]) {
        little_len++;
    }

    while (big[i] && i + little_len <= len) {
        size_t j = 0;
        while (big[i + j] == little[j] && j < little_len) {
            j++;
        }
        if (j == little_len) {
            return (char *)(big + i);
        }
        i++;
    }

    return NULL;
}


// int main() {
//     const char *haystack = "Hello, wor ld!";
//     const char *needle = "world";
    
//     char *result = strnstr(haystack, needle, 12);

//     if (result) {
//         printf("Found: %s\n", result);
//     } else {
//         printf("Not found\n");
//     }

//     return 0;
// }
