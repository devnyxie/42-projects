/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tafanasi <tafanasi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 13:28:07 by tafanasi          #+#    #+#             */
/*   Updated: 2024/12/03 13:30:39 by tafanasi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int ft_strlen(char *str){
	int i = 0;
	while(str[i])
		i++;
	return i;
}

// int main(void){
// 	int i = ft_strlen("teststring");
// 	printf("%d", i);
// 	return(1);
// }
