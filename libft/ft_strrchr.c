/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tafanasi <tafanasi@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 15:51:40 by tafanasi          #+#    #+#             */
/*   Updated: 2024/12/13 23:00:24 by tafanasi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

char	*ft_strrchr(const char *str, int c)
{
	char	*result;

	result = NULL;
	while (*str != '\0')
	{
		if (*str == (char)c)
		{
			result = (char *)str;
		}
		str++;
	}
	if (c == '\0')
	{
		return ((char *)str);
	}
	return (result);
}
/*
int	main(void){
	char *str = "Testingsussy";
	char *ptr = ft_strrchr(str, 's');
	printf("%s", ptr);
	return(0);
}
*/
