/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tafanasi <tafanasi@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 03:47:40 by tafanasi          #+#    #+#             */
/*   Updated: 2025/04/09 07:30:10 by tafanasi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int argc, char **argv, char **envp)
{
	int	pipefd[2];
	int	status;
	int	exit_code;

	if (argc != 5)
		error_exit("Usage: ./pipex infile \"cmd1 args\" \"cmd2 args\" outfile",
			1);
	if (pipe(pipefd) < 0)
		error_exit("pipe", 1);
	fork_processes(argv, envp, pipefd, &status);
	if (WIFEXITED(status))
		exit_code = WEXITSTATUS(status);
	else
		exit_code = 1;
	return (exit_code);
}
