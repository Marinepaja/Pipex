/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlaporte <mlaporte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 12:48:05 by mlaporte          #+#    #+#             */
/*   Updated: 2024/03/24 13:05:05 by mlaporte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*ft_getenv(char **env)
{
	int		i;

	i = 0;
	if (!env)
		return (NULL);
	while (env[i])
	{
		if (!ft_strncmp(env[i], "PATH=", 5))
			return (env[i] + 5);
		i++;
	}
	return (NULL);
}

char	*get_full_path(char *path_tab, char *cmd)
{
	char	*path;

	path = ft_strjoin(path_tab, "/");
	if (!path)
		return (NULL);
	path = ft_strjoin(path, cmd);
	if (path)
		return (path);
	return (NULL);
}

char	*get_path(char *cmd, char **env)
{
	char	**path_tab;
	char	**cmd_tab;
	int		i;
	char	*full_path;

	i = 0;
	path_tab = ft_split(ft_getenv(env), ':');
	cmd_tab = ft_split(cmd, ' ');
	if (!path_tab || !cmd_tab)
		return (NULL);
	while (path_tab[i])
	{
		full_path = get_full_path(path_tab[i], cmd_tab[0]);
		if (access(full_path, F_OK | X_OK) == 0)
		{
			free(path_tab);
			free_tab(cmd_tab);
			return (full_path);
		}
		i++;
		free(full_path);
	}
	free(path_tab);
	free_tab(cmd_tab);
	return (NULL);
}

int	print_msg(int i, char *str, char *cmd, char **tab)
{
	if (i == -1)
	{
		str = ft_strjoin(str, cmd);
		str = ft_strjoin(str, ": command not found\n");
	}
	else if (i == 1)
	{
		str = ft_strjoin(str, "bash: ");
		str = ft_strjoin(str, cmd);
		str = ft_strjoin(str, ": Is a directory\n");
	}
	else if (i == 2)
	{
		str = ft_strjoin(str, "bash: ");
		str = ft_strjoin(str, cmd);
		str = ft_strjoin(str, ": No such file or directory\n");
	}
	ft_putstr_fd(str, 2);
	free(str);
	free_tab(tab);
	return (-1);
}

int	exec_cmd(char *cmd, char **env, char *path)
{
	char	**tab;

	tab = ft_split(cmd, ' ');
	if (!tab)
		return (-1);
	if (!*cmd)
		return (print_msg(-1, NULL, cmd, tab));
	else if (access(cmd, F_OK | X_OK) == 0)
		execve(cmd, tab, env);
	if (access(cmd, F_OK | X_OK) == 0)
		return (print_msg(1, NULL, cmd, tab));
	if (ft_strchr(cmd, '/'))
		return (print_msg(2, NULL, cmd, tab));
	path = get_path(cmd, env);
	if (!path)
		return (print_msg(-1, NULL, cmd, tab));
	execve(path, tab, env);
	perror("execve() failed");
	free_tab(tab);
	return (-1);
}
