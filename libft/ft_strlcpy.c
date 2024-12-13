/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tafanasi <tafanasi@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 20:57:10 by tafanasi          #+#    #+#             */
/*   Updated: 2024/12/13 20:15:22 by tafanasi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include "libft.h"

size_t ft_strlcpy(char *dest, const char *src, size_t size) {
    size_t i = 0;

    if (size == 0) {
        return ft_strlen(src);
    }

    while (src[i] != '\0' && i < size - 1) {
        dest[i] = src[i];
        i++;
    }

    dest[i] = '\0';

    while (src[i] != '\0') {
        i++;
    }

    return i;
}

