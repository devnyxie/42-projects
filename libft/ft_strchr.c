/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tafanasi <tafanasi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 15:29:10 by tafanasi          #+#    #+#             */
/*   Updated: 2024/12/05 15:52:22 by tafanasi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

char *ft_strchr(const char *s, int c){
	const char *ptr = s;
	while(*ptr){
		if(*ptr == c){
			return (char *)ptr;
		}
		ptr++;
	}
	return NULL;
}
/*
int main(void){
	char *str = "Testing";
	char *ptr = strchr(str, 's');
	printf("%s", ptr);
	return(0);
}
*/
