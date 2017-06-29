/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_redirect.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tettouat <tettouat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/14 17:57:09 by aelola            #+#    #+#             */
/*   Updated: 2014/06/17 15:52:00 by tettouat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_42sh.h"

static int	ft_chevron_gauche2(char *cmd, int fds, t_history *history)
{
	int				fd_zero;

	fd_zero = dup(0);
	cmd = ft_strtrim(cmd);
	dup2(fds, 0);
	if (ft_strchr(cmd, '|'))
	{
		if (ft_pipex(cmd) == -1)
			return (-1);
	}
	else
	{
		if (ft_sh_command(cmd, history) == -1)
			return (-1);
	}
	dup2(fd_zero, 0);
	return (1);
}

static int	ft_chevron_gauche(char *line, t_history *history)
{
	char			*cmd;
	int				fds;
	int				i;
	char			**tabl;

	ft_init_chev(&i, &cmd, &tabl, line);
	fds = open(tabl[0], O_RDONLY);
	if (access(tabl[0], F_OK) != -1)
	{
		while (tabl[i])
		{
			cmd = ft_strjoin(cmd, tabl[i]);
			cmd = ft_strjoin(cmd, " ");
			i++;
		}
		if (ft_chevron_gauche2(cmd, fds, history) == -1)
			return (-1);
	}
	else
	{
		write(1, "access error\n", 13);
		return (-1);
	}
	close(fds);
	return (1);
}

static int	ft_chevron_droit2(char **tabl, int fds, t_history *history)
{
	if (access(tabl[1], F_OK) != -1)
	{
		dup2(fds, 1);
		if (ft_strchr(tabl[0], '|'))
		{
			if (ft_pipex(tabl[0]) == -1)
				return (-1);
		}
		else
		{
			if (ft_sh_command(tabl[0], history) == -1)
				return (-1);
		}
	}
	else
	{
		write(1, "access error\n", 13);
		return (-1);
	}
	return (1);
}

static int	ft_chevron_droit(char *line, t_history *history)
{
	int				fd_one;
	int				fds;
	char			**tabl;

	fd_one = dup(1);
	if (ft_check_double(line, '>') == 1)
	{
		tabl = ft_strsplit(line, '>');
		tabl[1] = ft_strtrim(tabl[1]);
		fds = open(tabl[1], O_WRONLY | O_CREAT | O_TRUNC, S_IWUSR | S_IRUSR);
	}
	else
	{
		tabl = ft_strsplit(line, '>');
		tabl[1] = ft_strtrim(tabl[1]);
		fds = open(tabl[1], O_WRONLY | O_CREAT | O_APPEND, S_IWUSR | S_IRUSR);
	}
	if (ft_chevron_droit2(tabl, fds, history) == -1)
	{
		dup2(fd_one, 1);
		return (-1);
	}
	dup2(fd_one, 1);
	close(fds);
	return (1);
}

int			ft_redirect(char *line, t_history *history)
{
	if (ft_strchr(line, '>'))
	{
		if (ft_chevron_droit(line, history) == -1)
			return (-1);
	}
	else
	{
		if (ft_chevron_gauche(line, history) == -1)
			return (-1);
	}
	return (1);
}
