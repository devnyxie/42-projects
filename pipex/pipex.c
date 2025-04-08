/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tafanasi <tafanasi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 03:47:40 by tafanasi          #+#    #+#             */
/*   Updated: 2025/04/08 03:47:41 by tafanasi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

// Child: runs cmd1, writes to pipe
void	child_process(char **argv, char **envp, int infile, int pipefd[2])
{
	char	**args;
	char	*resolved;

	dup2(infile, STDIN_FILENO);
	dup2(pipefd[1], STDOUT_FILENO);
	close(pipefd[0]);
	args = ft_split(argv[2], ' ');
	resolved = get_cmd_path(args[0], envp);
	if (!resolved)
		perror("Command not found");
	else
		execve(resolved, args, envp);
	free(resolved);
	free_2d(args);
	error_exit("execve (cmd1)");
}

// Parent: runs cmd2, reads from pipe
void	parent_process(char **argv, char **envp, int outfile, int pipefd[2])
{
	char	**args;
	char	*resolved;

	wait(NULL);
	dup2(pipefd[0], STDIN_FILENO);
	dup2(outfile, STDOUT_FILENO);
	close(pipefd[1]);
	args = ft_split(argv[3], ' ');
	resolved = get_cmd_path(args[0], envp);
	if (!resolved)
		perror("Command not found");
	else
		execve(resolved, args, envp);
	free(resolved);
	free_2d(args);
	error_exit("execve (cmd2)");
}

int	main(int argc, char **argv, char **envp)
{
	int		infile;
	int		outfile;
	int		pipefd[2];
	pid_t	pid;

	if (argc != 5)
		error_exit("Usage: ./pipex infile \"cmd1 args\" \"cmd2 args\" outfile");
	init_pipe(argv, &infile, &outfile, pipefd);
	pid = fork();
	if (pid < 0)
		error_exit("fork");
	if (pid == 0)
		child_process(argv, envp, infile, pipefd);
	else
		parent_process(argv, envp, outfile, pipefd);
}
