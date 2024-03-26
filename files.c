/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   files.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlaporte <mlaporte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 12:46:24 by mlaporte          #+#    #+#             */
/*   Updated: 2024/03/24 14:05:42 by mlaporte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	get_infile(char *av, t_pipex *pip)
{
	int		fd;
	char	*str;

	str = NULL;
	fd = open(av, O_RDONLY);
	if (fd == -1)
	{
		str = ft_strjoin(str, "bash: ");
		str = ft_strjoin(str, av);
		if (errno == EACCES)
			str = ft_strjoin(str, ": Permission denied\n");
		else
			str = ft_strjoin(str, ": No such file or directory\n");
		ft_putstr_fd(str, 2);
		free(str);
		ft_exit(pip->tube[1], pip->tube[0]);
	}
	if (dup2(fd, 0) == -1)
		(perror("dup2"), ft_exit(pip->tube[1], fd));
	close(fd);
	if (dup2(pip->tube[1], 1) == -1)
		(perror("dup2"), ft_exit(pip->tube[1], -1));
	close(pip->tube[1]);
}

void	get_outfile(char *av, t_pipex *pip)
{
	int		fd;
	char	*str;

	str = NULL;
	fd = open(av, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (fd == -1)
	{
		str = ft_strjoin(str, "bash: ");
		str = ft_strjoin(str, av);
		if (errno == EACCES)
			str = ft_strjoin(str, ": Permission denied\n");
		else
			str = ft_strjoin(str, ": Is a directory\n");
		ft_putstr_fd(str, 2);
		free(str);
		ft_exit(pip->tube[0], fd);
	}
	if (dup2(pip->tube[0], 0) == -1)
		(perror("dup2"), ft_exit(pip->tube[0], -1));
	close(pip->tube[0]);
	if (dup2(fd, 1) == -1)
		(perror("dup2"), ft_exit(fd, -1));
	close(fd);
}
