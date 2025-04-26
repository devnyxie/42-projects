/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tafanasi <tafanasi@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/26 23:12:00 by tafanasi          #+#    #+#             */
/*   Updated: 2025/04/26 23:37:46 by tafanasi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// MLX exit function
int	handle_exit(void *param)
{
	(void)param;
	exit(0);
	return (0);
}

void	free_2d(char **arr)
{
	int	i;

	i = 0;
	while (arr[i])
	{
		free(arr[i]);
		i++;
	}
	free(arr);
}
void	handle_error(const char *message, int exit_code)
{
	if (!errno)
		printf("%s\n", message);
	else
		perror(message);
	exit(exit_code);
}

int count_lines(char *filename)
{
    char buf[64];
    int fd;
    int i;
    int j;
    int bytes_read;
    int last_char_was_nl;

    i = 0;
    last_char_was_nl = 1;
    fd = open(filename, O_RDONLY);
    if (fd < 0)
        return (-1);
    while ((bytes_read = read(fd, buf, sizeof(buf))) > 0)
    {
        j = 0;
        while (j < bytes_read)
        {
            if (buf[j] == '\n')
            {
                i++;
                last_char_was_nl = 1;
            }
            else
                last_char_was_nl = 0;
            j++;
        }
    }
    if (!last_char_was_nl)
        i++;
    close(fd);
    printf("Lines: %d\n", i);
    return (i);
}