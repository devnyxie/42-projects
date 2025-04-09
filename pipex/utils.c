/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tafanasi <tafanasi@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 04:01:27 by tafanasi          #+#    #+#             */
/*   Updated: 2025/04/09 07:50:39 by tafanasi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

// Exit with an error message and specified exit code
void	error_exit(const char *msg, int exit_code)
{
	perror(msg);
	exit(exit_code);
}

// Free a 2D array (array of strings)
void	free_2d(char **str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		free(str[i]);
		i++;
	}
	free(str);
}

// mode 0 = read (infile), mode 1 = write (outfile)
int	open_file(const char *path, int mode)
{
	int	fd;

	if (mode == 0)
		fd = open(path, O_RDONLY);
	else
		fd = open(path, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (fd < 0)
	{
		if (mode == 0)
			perror("Error opening infile");
		else
			perror("Error opening outfile");
	}
	return (fd);
}
