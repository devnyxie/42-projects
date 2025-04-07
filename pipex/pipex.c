#include <unistd.h>
#include <fcntl.h> //dupfd
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <sys/wait.h>
#include "pipex.h"

void	error_exit(const char *msg)
{
	perror(msg);
	exit(EXIT_FAILURE);
}

char	**split_cmd(char *cmd)
{
	char **args = malloc(sizeof(char *) * 4);
	args[0] = strtok(cmd, " ");
	args[1] = strtok(NULL, " ");
	args[2] = strtok(NULL, " ");
	args[3] = NULL;
	return args;
}

void free_args(char **args)
{
	int i = 0;
	while (args[i])
	{
		free(args[i]);
		i++;
	}
	free(args);
}


char	*get_cmd_path(char *cmd, char **envp)
{
	char	**paths;
	char	*path_env = NULL;
	char	*full_path;
	int		i;

	// find PATH= in envp
	for (int j = 0; envp[j]; j++)
	{
		if (ft_strncmp(envp[j], "PATH=", 5) == 0)
		{
			path_env = envp[j] + 5;
			break;
		}
	}
	if (!path_env)
		return (NULL); // PATH not found

	paths = ft_split(path_env, ':');
	if (!paths)
		return (NULL);

	// try each path + cmd
	i = 0;
	while (paths[i])
	{
		full_path = ft_strjoin(paths[i], "/");
		if (!full_path)
			break;
		char *tmp = ft_strjoin(full_path, cmd);
		free(full_path);
		if (!tmp)
			break;
		if (access(tmp, X_OK) == 0)
		{
			// found valid path
			while (paths[i])
				free(paths[i++]);
			free(paths);
			return (tmp);
		}
		free(tmp);
		i++;
	}
	// free and return NULL if not found
	while (paths[i])
		free(paths[i++]);
	free(paths);
	return (NULL);
}


int	main(int argc, char **argv, char **envp)
{
	int		infile, outfile, pipefd[2];
	pid_t	pid;

	if (argc != 5)
		error_exit("Usage: ./pipex infile \"cmd1 args\" \"cmd2 args\" outfile");

	infile = open(argv[1], O_RDONLY);
	if (infile < 0)
		error_exit("infile");

	outfile = open(argv[4], O_CREAT | O_WRONLY | O_TRUNC, 0644);
	if (outfile < 0)
		error_exit("outfile");

	if (pipe(pipefd) < 0)
		error_exit("pipe");

	pid = fork();
	if (pid < 0)
		error_exit("fork");

	if (pid == 0)
	{
		// Child: runs cmd1, writes to pipe
		dup2(infile, STDIN_FILENO);
		dup2(pipefd[1], STDOUT_FILENO);
		close(pipefd[0]); // close unused read
		char **args = split_cmd(argv[2]);
		char *resolved = get_cmd_path(args[0], envp);
		if (!resolved)
			perror("Command not found");
		else
			execve(resolved, args, envp);
		free(resolved); // Free resolved path
		free_args(args); // Free args before exiting
		error_exit("execve (cmd1)");
	}
	else
	{
		// Parent: runs cmd2, reads from pipe
		wait(NULL);
		dup2(pipefd[0], STDIN_FILENO);
		dup2(outfile, STDOUT_FILENO);
		close(pipefd[1]); // close unused write
		char **args = split_cmd(argv[3]);
		char *resolved = get_cmd_path(args[0], envp);
		if (!resolved)
			perror("Command not found");
		else
			execve(resolved, args, envp);
		free(resolved); // Free resolved path if execve fails
		free_args(args); // Free args before exiting
		error_exit("execve (cmd2)");
	}
}