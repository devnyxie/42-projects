#ifndef PIPEX_H
# define PIPEX_H

# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>
# include <stdio.h>
# include <string.h>
# include <sys/wait.h>
# include "libft/libft.h"

void	error_exit(const char *msg);
char	**split_cmd(char *cmd);
char	*get_cmd_path(char *cmd, char **envp);

#endif