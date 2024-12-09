/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tafanasi <tafanasi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 13:56:53 by tafanasi          #+#    #+#             */
/*   Updated: 2024/12/03 13:58:51 by tafanasi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void ft_bzero(void *s, size_t size){
	unsigned char *ptr = s;
	while(size--){
		*ptr = '\0';
		ptr++;
	}
}
