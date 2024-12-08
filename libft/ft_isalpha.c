/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tafanasi <tafanasi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 12:41:11 by tafanasi          #+#    #+#             */
/*   Updated: 2024/12/03 13:04:12 by tafanasi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int ft_isalpha(char c)
{
	if((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z')){
		return 1;
	} 
	return 0;
}