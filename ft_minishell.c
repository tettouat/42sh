/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_minishell.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tettouat <tettouat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/14 15:12:29 by aelola            #+#    #+#             */
/*   Updated: 2014/06/17 15:45:09 by tettouat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_42sh.h"

void			catch_signal(int signal_catch)
{
	ft_putchar('\n');
	ft_promt();
	if (signal_catch == SIGINT || signal_catch == SIGQUIT)
	{
		signal(SIGINT, catch_signal);
		signal(SIGQUIT, catch_signal);
	}
}

static int		ft_sh(void)
{
	char			*line;
	t_history		*history;

	line = malloc(sizeof(char));
	if (!line)
		return (-1);
	ft_promt();
	signal(SIGINT, catch_signal);
	signal(SIGQUIT, catch_signal);
	history = ft_creat_history();
	while (42)
	{
		line = ft_termcap(history);
		if (line[0] == '.' && line[1] == '/')
			line = ft_script(line);
		if (ft_strchr(line, ';'))
			ft_point_virgule(line, NULL, history);
		else
			ft_exec_cmd(line, history);
		ft_promt();
	}
	return (0);
}

static void		ft_ctrl_path(void)
{
	char		**path;
	char		*valid;

	path = ft_strsplit(ft_getentry("PATH"), ':');
	valid = malloc(sizeof(char));
	valid = "";
	if (path != NULL)
	{
		while (access(*path, F_OK) == 0)
		{
			valid = ft_strjoin(valid, ft_strjoin(*path, ":"));
			path++;
		}
	}
	ft_setentry("PATH", valid);
}

short			ft_ctrl_env(void)
{
	if (ft_tablen(g_env) != 0)
	{
		if (ft_strlen(ft_getentry("PWD")) == 0
			|| access(ft_getentry("PWD"), F_OK) != 0)
			ft_setentry("PWD", "/");
		if (ft_strlen(ft_getentry("HOME")) == 0
			|| access(ft_getentry("HOME"), F_OK) != 0)
			ft_setentry("HOME", "/");
		if (ft_strlen(ft_getentry("OLDPWD")) == 0
			|| access(ft_getentry("OLDPWD"), F_OK) != 0)
			ft_setentry("OLDPWD", "/");
		return (1);
	}
	return (0);
}

int				main(void)
{
	extern char		**environ;

	g_env = ft_tabdup(environ);
	ft_ctrl_path();
	if (ft_strlen(ft_getentry("PATH")) == 0)
		ft_setentry("PATH", "/usr/local/bin:/usr/bin:/bin:/usr/sbin:/sbin");
	if (!ft_ctrl_env())
		return (ft_putendl("env error"));
	return (ft_sh());
}
