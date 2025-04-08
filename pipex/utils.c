/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tafanasi <tafanasi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 03:47:28 by tafanasi          #+#    #+#             */
/*   Updated: 2025/04/08 03:47:30 by tafanasi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	error_exit(const char *msg)
{
	perror(msg);
	exit(EXIT_FAILURE);
}

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

void	init_pipe(char **argv, int *infile, int *outfile, int pipefd[2])
{
	*infile = open(argv[1], O_RDONLY);
	if (*infile < 0)
		error_exit("infile");
	*outfile = open(argv[4], O_CREAT | O_WRONLY | O_TRUNC, 0644);
	if (*outfile < 0)
		error_exit("outfile");
	if (pipe(pipefd) < 0)
		error_exit("pipe");
}
