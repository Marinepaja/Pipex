/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlaporte <mlaporte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/08 16:10:24 by mlaporte          #+#    #+#             */
/*   Updated: 2024/03/24 14:27:48 by mlaporte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_exit(int fd1, int fd2)
{
	if (fd1 > -1)
		close(fd1);
	if (fd2 > -1)
		close(fd2);
	exit(0);
}

void	first_pipe(char **argv, t_pipex *pip, char **env)
{
	pip->pid1 = fork();
	if (pip->pid1 == -1)
		(perror("fork"), exit(EXIT_FAILURE));
	if (!pip->pid1)
	{
		close(pip->tube[0]);
		get_infile(argv[1], pip);
		if (exec_cmd(argv[2], env, NULL) == -1)
			ft_exit(-1, -1);
	}
	if (pip->pid1)
		close(pip->tube[1]);
}

void	second_pipe(char **argv, t_pipex *pip, char **env)
{
	pip->pid2 = fork();
	if (pip->pid2 == -1)
		(perror("fork"), exit(EXIT_FAILURE));
	if (!pip->pid2)
	{
		get_outfile(argv[4], pip);
		if (exec_cmd(argv[3], env, NULL) == -1)
			(ft_exit(pip->tube[0], -1));
	}
	if (pip->pid2)
		close(pip->tube[0]);
}

int	main(int argc, char **argv, char **env)
{
	t_pipex		pip;

	if (argc != 5)
		(write(2, "Input error : ./pipex infile cmd1 cmd2 outfile\n", 47),
			exit(EXIT_FAILURE));
	if (pipe(pip.tube) == -1)
		exit(EXIT_FAILURE);
	first_pipe(argv, &pip, env);
	second_pipe(argv, &pip, env);
	waitpid(pip.pid1, NULL, WUNTRACED);
	waitpid(pip.pid2, NULL, WUNTRACED);
	return (0);
}
