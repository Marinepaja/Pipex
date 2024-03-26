/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlaporte <mlaporte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/08 16:10:24 by mlaporte          #+#    #+#             */
/*   Updated: 2024/02/27 14:32:34 by mlaporte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_exit(t_pipex *p, int fd1, int fd2, int ext)
{
	if (fd1 > -1)
		close(fd1);
	if (fd2 > -1)
		close(fd2);
	if (p->path1)
		free(p->path1);
	if (p->path2)
		free(p->path2);
	exit(ext);
}

void	init(t_pipex *pip)
{
	pip->path1 = NULL;
	pip->path2 = NULL;
	pip->full_path = NULL;

}

void	first_pipe(char **argv, t_pipex *pip, char **env)
{
	// pid_t	pid;

	pip->pid1 = fork();
	if (pip->pid1 == -1)
		(perror("fork"), exit(EXIT_FAILURE));
	if (!pip->pid1) // process enfant
	{
		close(pip->tube[0]);
		get_infile(argv[1], pip);
		if (exec_cmd(argv[2], env, pip->path1) == -1)
			ft_exit(pip, -1, -1, 0); // Pk envoyer pip.tube[0] et pip.tube[1] ici en cas d 'erreur? si tu es arrivee la, ils ont deja ete close dans tes fonctions precedentes
	}
	if (pip->pid1) //process parent
		close(pip->tube[1]);
}

void	second_pipe(char **argv, t_pipex *pip, char **env)
{
	// pid_t	pid;

	pip->pid2 = fork();
	if (pip->pid2 == -1)
		(perror("fork"), exit(EXIT_FAILURE));
	if (!pip->pid2)
	{
		// close(pip->tube[1]); // pip.tube[1] a ete close par le process parent dans la fonction first_pipe, il n'existe donc pas dans ton deuxieme child.
		get_outfile(argv[4], pip);
		if (exec_cmd(argv[3], env, pip->path2) == -1)
			(ft_exit(pip, pip->tube[0], -1, 127)); // pip.tube[1] n existe pas dans le deuxieme child + si tu arrives la pip.tube[0] a ete close dans tous les cas, cela ne sert a rien de lenvoyer
	}
	if (pip->pid2)
		close(pip->tube[0]);
}

int	main(int argc, char **argv, char **env)
{
	t_pipex		pip;
	// pid_t		n;

	if (argc != 5)
		(write(2, "Input error : ./pipex infile cmd1 cmd2 outfile\n", 47),
			exit(EXIT_FAILURE));
	init(&pip);
	if (pipe(pip.tube) == -1)
		exit(EXIT_FAILURE);
	first_pipe(argv, &pip, env); // il faut envoyer un pointeur sur ta structure pip et non la copie de ta structure ( cf point 2 explication waitpid)
	second_pipe(argv, &pip, env); // IDEM
	waitpid(pip.pid1, NULL, WUNTRACED);
	waitpid(pip.pid2, NULL, WUNTRACED); 
	if (pip.path1)
		free(pip.path1);
	if (pip.path2)
		free(pip.path2);
	return (0); // on ne te demande pas dans pipex de gerer l exit status, de plus si tu le fais il faut savoir qu n peut recup d un enfant soit un exit status soit un signal don il faudrait le traiter. return (0) au niveau de pipex suffit, tu verras les exit status dans minishell.
}

/*
en plus des commentaires, il faudra dans les message d erreurs gerer ces test la :

infile = "         "
infile = "     /    "
infile = "         /"
infile = "/         "
infile = "/"
infile = "///////"
>> test a refaire pour l outfile

cmd = "/"
cmd = "///"
cmd = " /"
cmd = " / "
cmd = "/ "
cmd = "   "

*/