/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tafanasi <tafanasi@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/15 18:28:51 by tafanasi          #+#    #+#             */
/*   Updated: 2024/12/15 21:33:10 by tafanasi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <stdlib.h>

char	*ft_strncpy(char *dest, const char *src, unsigned int n)
{
	unsigned int	i;

	i = 0;
	while (i < n && src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	while (i < n)
	{
		dest[i] = '\0';
		i++;
	}
	return (dest);
}

int	count_words(const char *s, char delimeter)
{
	size_t	count;
	int		in_word;

	count = 0;
	in_word = 0;
	while (*s)
	{
		if (*s != delimeter && !in_word)
		{
			in_word = 1;
			count++;
		}
		else
		{
			in_word = 0;
		}
		s++;
	}
	return (count);
}

char	*allocate_word(const char *start, size_t length)
{
	char	*word;

	word = (char *)malloc((length + 1) * sizeof(char));
	if (!word)
		return (NULL);
	ft_strncpy(word, start, length);
	word[length] = '\0';
	return (word);
}

char	**ft_split(const char *s, char delimeter)
{
	size_t	word_count;
	char	**result;
	size_t	index;
			const char *start = s;
	size_t	length;

	if (!s)
		return (NULL);
	word_count = count_words(s, delimeter);
	result = (char **)malloc((word_count + 1) * sizeof(char));
	index = 0;
	while (*s)
	{
		if (*s != delimeter)
		{
			length = 0;
			while (*s && *s != delimeter)
			{
				s++;
				length++;
			}
			result[index] = allocate_word(start, length);
			if (!result)
			{
				// free ALL prev memory and return (NULL);
				while (index > 0)
				{
					free(result[--index]);
				}
				free(result);
				return (NULL);
			}
			index++;
		} else {
			s++;
		}
	}
	result[index] = NULL;
	return (result);
}

int	main(void)
{
	char	**result;
	int		i;

	result = ft_split("helloXworldXkiddosX", 'X');
	if (!result)
		printf("result is NULL");
	i = 0;
	while (result[i] != NULL)
	{
		printf("%s\n", result[i]);
		i++;
	}
	return (0);
}
