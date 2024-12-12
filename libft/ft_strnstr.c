/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tafanasi <tafanasi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/08 03:49:57 by tafanasi          #+#    #+#             */
/*   Updated: 2024/12/08 04:04:25 by tafanasi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdio.h>

char *ft_strnstr(const char *big, const char *little, size_t len) {
    int little_len = 0;
    while (little[little_len]) {
        little_len++;
    }
    if (little_len == 0) {
        return (char *)big;
    }
    size_t i = 0;
    while (big[i] && i < len) {
        int occurrences = 0;
        while (big[i + occurrences] == little[occurrences] && occurrences < little_len) {
            occurrences++;
        }
        if (occurrences == little_len) {
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
