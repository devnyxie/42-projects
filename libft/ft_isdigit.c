/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tafanasi <tafanasi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 12:48:29 by tafanasi          #+#    #+#             */
/*   Updated: 2024/12/03 13:10:46 by tafanasi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int ft_isdigit(int c){
	if(c >= '0' && c <= '9'){
		return 1;
	}
	return 0;
}
