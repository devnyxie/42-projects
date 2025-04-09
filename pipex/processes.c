/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   processes.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tafanasi <tafanasi@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 07:29:09 by tafanasi          #+#    #+#             */
/*   Updated: 2025/04/09 07:35:36 by tafanasi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static void	execute_command(char *cmd_str, char **envp)
{
	char	**args;
	char	*resolved;

	args = ft_split(cmd_str, ' ');
	if (!args || !args[0])
	{
		if (args)
			free_2d(args);
		error_exit("Invalid command format", 1);
	}
	resolved = get_cmd_path(args[0], envp);
	if (!resolved)
	{
		free_2d(args);
		error_exit("Command not found", 127);
	}
	execve(resolved, args, envp);
	free(resolved);
	free_2d(args);
	error_exit("execve failed", 126);
}

// Child: runs cmd1, writes to pipe
static void	child_process(char **argv, char **envp, int pipefd[2])
{
	int	infile;

	infile = open_file(argv[1], 0);
	if (infile < 0)
		error_exit("infile", 1);
	dup2(infile, STDIN_FILENO);
	dup2(pipefd[1], STDOUT_FILENO);
	close(infile);
	close(pipefd[0]);
	close(pipefd[1]);
	execute_command(argv[2], envp);
}

// Parent: runs cmd2, reads from pipe
static void	parent_process(char **argv, char **envp, int pipefd[2])
{
	int	outfile;

	outfile = open_file(argv[4], 1);
	if (outfile < 0)
		error_exit("outfile", 1);
	dup2(pipefd[0], STDIN_FILENO);
	dup2(outfile, STDOUT_FILENO);
	close(outfile);
	close(pipefd[0]);
	close(pipefd[1]);
	execute_command(argv[3], envp);
}

void	fork_processes(char **argv, char **envp, int pipefd[2], int *status)
{
	pid_t	pid1;
	pid_t	pid2;

	pid1 = fork();
	if (pid1 < 0)
		error_exit("fork", 1);
	if (pid1 == 0)
		child_process(argv, envp, pipefd);
	pid2 = fork();
	if (pid2 < 0)
		error_exit("fork", 1);
	if (pid2 == 0)
		parent_process(argv, envp, pipefd);
	close(pipefd[0]);
	close(pipefd[1]);
	waitpid(pid1, NULL, 0);
	waitpid(pid2, status, 0);
}
