/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_cmd_path.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tafanasi <tafanasi@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 03:47:54 by tafanasi          #+#    #+#             */
/*   Updated: 2025/04/09 05:48:46 by tafanasi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static void	find_env_path(char **envp, char **path_env)
{
	int	j;

	j = 0;
	*path_env = NULL;
	// while (envp && envp[j])
	while (envp[j])
	{
		if (ft_strncmp(envp[j], "PATH=", 5) == 0)
		{
			*path_env = envp[j] + 5;
			break ;
		}
		j++;
	}
}

static char	*search_cmd_path(char **paths, char *cmd)
{
	char	*full_path;
	char	*tmp;
	int		i;

	i = 0;
	// if (!paths || !cmd || !*cmd)
	// 	return (NULL);
	while (paths[i])
	{
		full_path = ft_strjoin(paths[i], "/");
		if (!full_path)
			break ;
		tmp = ft_strjoin(full_path, cmd);
		free(full_path);
		if (!tmp)
			break ;
		if (access(tmp, X_OK) == 0)
		{
			free_2d(paths);
			return (tmp);
		}
		free(tmp);
		i++;
	}
	return (NULL);
}

char	*get_cmd_path(char *cmd, char **envp)
{
	char	**paths;
	char	*path_env;
	char	*result;

	// if (!cmd || !*cmd)
	// 	return (NULL);
	// if (cmd[0] == '/' || (cmd[0] == '.' && cmd[1] == '/'))
	// {
	// 	if (access(cmd, X_OK) == 0)
	// 		return (ft_strdup(cmd));
	// 	return (NULL);
	// }
	find_env_path(envp, &path_env);
	if (!path_env)
		return (NULL);
	paths = ft_split(path_env, ':');
	if (!paths)
		return (NULL);
	result = search_cmd_path(paths, cmd);
	if (!result)
		free_2d(paths);
	return (result);
}
