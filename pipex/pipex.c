/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tafanasi <tafanasi@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 03:47:40 by tafanasi          #+#    #+#             */
/*   Updated: 2025/04/09 06:18:57 by tafanasi         ###   ########.fr       */
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
void	parent_process(char **argv, char **envp, int outfile, int pipefd[2])
{
	char	**args;
	char	*resolved;

	dup2(pipefd[0], STDIN_FILENO);
	dup2(outfile, STDOUT_FILENO);
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

// Initialize pipe, open input and output files
void init_pipe(char **argv, int *infile, int *outfile, int pipefd[2])
{
	// Try to open the input file, but don't exit if it fails
	*infile = open(argv[1], O_RDONLY);
	
	// Handle output file - create or truncate
	*outfile = open(argv[4], O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (*outfile == -1)
		error_exit("outfile", 1);
	
	// Create pipe
	if (pipe(pipefd) == -1)
		error_exit("pipe", 1);
}

int	main(int argc, char **argv, char **envp)
{
	int		infile;
	int		outfile;
	int		pipefd[2];
	pid_t	pid1;
	int		status;
	int		exit_code;

	if (argc != 5)
		error_exit("Usage: ./pipex infile \"cmd1 args\" \"cmd2 args\" outfile", 1);
	
	init_pipe(argv, &infile, &outfile, pipefd);
	
	pid1 = fork();
	if (pid1 < 0)
		error_exit("fork", 1);
	
	if (pid1 == 0)
	{
		if (infile < 0)
			error_exit("infile", 1);
		child_process(argv, envp, infile, pipefd);
	}
	else
	{
		pid_t pid2 = fork();
		if (pid2 < 0)
			error_exit("fork", 1);
		
		if (pid2 == 0)
		{
			parent_process(argv, envp, outfile, pipefd);
		}
		else
		{
			// Close file descriptors in parent
			close(pipefd[0]);
			close(pipefd[1]);
			if (infile >= 0)
				close(infile);
			close(outfile);
			
			// Wait for child processes and track exit status
			waitpid(pid2, &status, 0);
			waitpid(pid1, NULL, 0);
			
			if (WIFEXITED(status))
				exit_code = WEXITSTATUS(status);
			else
				exit_code = 1;
			
			exit(exit_code);
		}
	}
	return (0);
}
