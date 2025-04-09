/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tafanasi <tafanasi@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 03:53:27 by tafanasi          #+#    #+#             */
/*   Updated: 2025/04/09 07:47:41 by tafanasi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "libft/libft.h"
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <sys/wait.h>
# include <unistd.h>

void	error_exit(const char *msg, int exit_code);
char	*get_cmd_path(char *cmd, char **envp);
void	free_2d(char **str);
int		open_file(const char *path, int mode);
void	fork_processes(char **argv, char **envp, int pipefd[2], int *status);

#endif
