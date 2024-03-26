/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlaporte <mlaporte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/08 16:09:28 by mlaporte          #+#    #+#             */
/*   Updated: 2024/02/27 14:31:40 by mlaporte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H
# include "libft/libft.h"
# include <sys/types.h>
# include <sys/stat.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>
# include <sys/wait.h>
# include <errno.h>

typedef struct s_pipex
{
	int		tube[2];
	pid_t	pid1;
	pid_t	pid2;
	char	*path1;
	char	*path2;
	char	*full_path;
}	t_pipex;

void	first_pipe(char **argv, t_pipex *pip, char **env);
void	second_pipe(char **argv, t_pipex *pip, char **env);
void	init(t_pipex *pip);
void	get_infile(char *av, t_pipex *pip);
void	get_outfile(char *av, t_pipex *pip);
char	*ft_getenv(char **env);
char	*get_path(char *cmd, char **env);
int		exec_cmd(char *cmd, char **env, char *path);
void	ft_exit(t_pipex *p, int fd1, int fd2, int ext);

#endif