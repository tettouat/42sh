/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pipex.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tettouat <tettouat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/06 20:54:07 by aelola            #+#    #+#             */
/*   Updated: 2014/06/23 17:45:19 by tettouat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_42sh.h"

int			ft_father(char *cmd, int *fds)
{
	pid_t		pid2;

	close(fds[0]);
	dup2(fds[1], 1);
	close(fds[1]);
	pid2 = fork();
	if (pid2 > 0)
		wait (NULL);
	if (pid2 == 0)
		ft_42sh(cmd);
	exit(0);
}

int			ft_child(char *cmd, int *fds)
{
	pid_t		pid2;

	close(fds[1]);
	dup2(fds[0], 0);
	close(fds[0]);
	pid2 = fork();
	if (pid2 > 0)
		wait (NULL);
	if (pid2 == 0)
	{
		ft_42sh(cmd);
		exit(0);
	}
	return (1);
}

int			ft_pipex(char *line)
{
	int			fds[2];
	pid_t		pid;
	int			fd_one;
	int			fd_zero;
	char		**str;

	fd_one = dup(1);
	fd_zero = dup(0);
	str = ft_strsplit(line, '|');
	pipe(fds);
	pid = fork();
	if (pid == 0)
	{
		if (ft_father(str[0], fds) == -1)
			return (-1);
	}
	else
	{
		wait(&pid);
		if (ft_child(str[1], fds) == -1)
			return (-1);
	}
	dup2(fd_one, 1);
	dup2(fd_zero, 0);
	return (1);
}
