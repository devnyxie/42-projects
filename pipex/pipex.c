/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tafanasi <tafanasi@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 03:47:40 by tafanasi          #+#    #+#             */
/*   Updated: 2025/04/09 06:43:02 by tafanasi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

// Child: runs cmd1, writes to pipe
void	child_process(char **argv, char **envp, int pipefd[2])
{
	char	**args;
	char	*resolved;
	int		infile;

	infile = open_file(argv[1], 0);
	if (infile < 0)
		error_exit("infile", 1);
	
	dup2(infile, STDIN_FILENO);
	dup2(pipefd[1], STDOUT_FILENO);
	close(infile);
	close(pipefd[0]);
	close(pipefd[1]);
	
	args = ft_split(argv[2], ' ');
	if (!args || !args[0])
	{
		if (args)
			free_2d(args);
		error_exit("Invalid command format (cmd1)", 1);
	}
	resolved = get_cmd_path(args[0], envp);
	if (!resolved)
	{
		free_2d(args);
		error_exit("Command not found (cmd1)", 127);
	}
	execve(resolved, args, envp);
	free(resolved);
	free_2d(args);
	error_exit("execve (cmd1)", 126);
}

// Parent: runs cmd2, reads from pipe
void	parent_process(char **argv, char **envp, int pipefd[2])
{
	char	**args;
	char	*resolved;
	int		outfile;

	outfile = open_file(argv[4], 1);
	if (outfile < 0)
		error_exit("outfile", 1);
		
	dup2(pipefd[0], STDIN_FILENO);
	dup2(outfile, STDOUT_FILENO);
	close(outfile);
	close(pipefd[0]);
	close(pipefd[1]);
	
	args = ft_split(argv[3], ' ');
	if (!args || !args[0])
	{
		if (args)
			free_2d(args);
		error_exit("Invalid command format (cmd2)", 1);
	}
	resolved = get_cmd_path(args[0], envp);
	if (!resolved)
	{
		free_2d(args);
		error_exit("Command not found (cmd2)", 127);
	}
	execve(resolved, args, envp);
	free(resolved);
	free_2d(args);
	error_exit("execve (cmd2)", 126);
}

// Set up pipe
void	init_pipe(int pipefd[2])
{
	if (pipe(pipefd) < 0)
		error_exit("pipe", 1);
}


// int	main(int argc, char **argv, char **envp)
// {
// 	int		pipefd[2];
// 	pid_t	pid;
// 	int		status;
// 	int		exit_code = 0;

// 	if (argc != 5)
// 		error_exit("Usage: ./pipex infile \"cmd1 args\" \"cmd2 args\" outfile", 1);
// 	init_pipe(pipefd);
// 	pid = fork();
// 	if (pid < 0)
// 		error_exit("fork", 1);
// 	if (pid == 0)
// 		child_process(argv, envp, pipefd);
// 	else
// 		parent_process(argv, envp, pipefd);
// 	if (WIFEXITED(status))
// 		exit_code = WEXITSTATUS(status);
// 	else
// 		exit_code = 1;
	
// 	return (exit_code);
// }

int	main(int argc, char **argv, char **envp)
{
	int		pipefd[2];
	pid_t	pid1;
	pid_t	pid2;
	int		status;
	int		exit_code = 0;

	if (argc != 5)
		error_exit("Usage: ./pipex infile \"cmd1 args\" \"cmd2 args\" outfile", 1);
	
	init_pipe(pipefd);
	
	// First child process (cmd1)
	pid1 = fork();
	if (pid1 < 0)
		error_exit("fork", 1);
	if (pid1 == 0)
		child_process(argv, envp, pipefd);
	
	// Second child process (cmd2)
	pid2 = fork();
	if (pid2 < 0)
		error_exit("fork", 1);
	if (pid2 == 0)
		parent_process(argv, envp, pipefd);
	
	// Parent process: cleanup and wait
	close(pipefd[0]);
	close(pipefd[1]);
	
	// Wait for child processes and track exit status
	waitpid(pid1, NULL, 0);
	waitpid(pid2, &status, 0);
	
	if (WIFEXITED(status))
		exit_code = WEXITSTATUS(status);
	else
		exit_code = 1;
	
	return (exit_code);
}
