/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlaporte <mlaporte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 12:48:05 by mlaporte          #+#    #+#             */
/*   Updated: 2024/02/27 15:36:10 by mlaporte         ###   ########.fr       */
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

char	*get_path(char *cmd, char **env)
{
	char	**path_tab;
	char	**cmd_tab;
	int		i;
	char	*path;
	char	*full_path;

	i = 0;

	path_tab = ft_split(ft_getenv(env), ':'); 
	if (!path_tab)
		return (NULL);
	cmd_tab = ft_split(cmd, ' '); 
	if (!cmd_tab)
		return (NULL);
	
	while (path_tab[i]) // ok mais avant il faudra verifier qu on t a pas directement envoyer le chemin + la cmd dans l argument par ex : /usr/bin/ls au lieu de ls -> utiliser access pour faire ca
	{
		path = ft_strjoin(path_tab[i], "/"); // retour strjoin si malloc ko non protege 
		full_path = ft_strjoin(path, cmd_tab[0]); // retour strjoin si malloc ko non protege
		if (access(full_path, F_OK | X_OK) == 0)
		{
			free(path_tab); // attention : ici tu free le char **, mais un split te retourne un char** avec a l interieur des char * qui eux aussi doivent etre free 
			free_tab(cmd_tab); // idem
			return (full_path);
		}
		free(full_path);
		i++;
	}
	free(path_tab); // idem que pour les free du dessus
	free_tab(cmd_tab); // idem
	return (NULL);
}

int	check_cmd(char *cmd)
{
	//size_t		i;

	//i = 0;
	if (!cmd)
		return (-1);
	/*while (cmd[i] && cmd[i] == '/')
		i++;
	//dprintf (2, "%ld, %s\n", i, cmd);
	if (i == ft_strlen(cmd))
		return (1);
	else if (cmd[ft_strlen(cmd) - 1] == '/')
		return (1);
	else*/ if (ft_strchr(cmd, '/'))
		return (2);

	/*while (cmd[i] && ((cmd[i] >= 9 && cmd[i] <= 13) || cmd[i] == ' '))
		i++;
	if (i == ft_strlen(cmd))*/
		return (0);
	
	//return (i);
}

int	print_msg(int i, char *str, char *cmd, char **tab)
{
	//dprintf (2, "%d, %s\n", i, cmd);
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
	char	*str;
	//int		i;

	tab = ft_split(cmd, ' ');
	if (!tab)
		return (-1);
	str = NULL;
	if (access(cmd, F_OK | X_OK) == 0)
		execve(cmd, tab, env);
	if (access(cmd, F_OK | X_OK) == 0)
		return (print_msg(1, str, cmd, tab));
	//i = check_cmd(cmd);		
	if (ft_strchr(cmd, '/'))
		return (print_msg(2, str, cmd, tab));
	/*if (i)
		return (print_msg(i, str, cmd, tab));*/
	path = get_path(cmd, env);
	
	if (!path)
		return (print_msg(-1, str, cmd, tab));
	/*if (i)
		return (print_msg(i, str, cmd, tab));*/
	execve(path, tab, env);
	perror("execve() failed");
	free_tab(tab);
	return (-1);
}
