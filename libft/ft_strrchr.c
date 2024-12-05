/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tafanasi <tafanasi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 15:51:40 by tafanasi          #+#    #+#             */
/*   Updated: 2024/12/05 16:02:49 by tafanasi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

char *ft_strrchr(const char *s, int c){
	const char *ptr = s;
	while(*ptr){
		ptr++;
	}
	//now ptr will point to '\0', so we have to
	//check backwards until the start (s pointer) 
	while(ptr >= s){
		if(*ptr == c){
			return (char *)ptr;
		}
		ptr--;
	}
	return NULL;
}
/*
int main(void){
	char *str = "Testingsussy";
	char *ptr = ft_strrchr(str, 's');
	printf("%s", ptr);
	return(0);
}
*/
