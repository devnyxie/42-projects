/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tafanasi <tafanasi@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 16:06:09 by tafanasi          #+#    #+#             */
/*   Updated: 2024/12/13 20:09:08 by tafanasi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int ft_strncmp(const char *s1, const char *s2, size_t n) {
    while (n > 0) {
        if (*s1 != *s2) {
            return (unsigned char)*s1 - (unsigned char)*s2;
        }
        
        if (*s1 == '\0') {
            return 0;
        }

        s1++;
        s2++;
        n--;
    }
    
    return 0;
}
/*
int main(void){
	char *str1 = "hello1";
	char *str2 = "h2llo2";
	int res = ft_strncmp(str1, str2, 2);
	printf("\n%d\n", res);
	return(0);
}
*/
