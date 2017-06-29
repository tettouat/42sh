/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_setenv.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tettouat <tettouat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/14 15:12:56 by aelola            #+#    #+#             */
/*   Updated: 2014/05/21 20:04:59 by ebreda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_42sh.h"

void		ft_sh_unsetenv(char *line)
{
	char	**tmp;
	int		result;

	result = 0;
	tmp = ft_strsplit(line, ' ');
	if (tmp)
	{
		result = ft_unsetenv(tmp[1]);
		if (result == -1)
			ft_putstr_fd("ERROR", 2);
	}
}

void		ft_setenv(char *line)
{
	int			size;
	char		**cmd;

	cmd = ft_strsplit_ft(line, ft_isblank);
	size = ft_tablen(cmd);
	if (size == 1)
		ft_puttabl(g_env);
	else if (size == 2)
		ft_setentry(cmd[1], "");
	else if (size == 3)
		ft_setentry(cmd[1], cmd[2]);
	else
		ft_putendl("setenv: Too many arguments.");
}

int			ft_unsetenv(char *name)
{
	int		i;

	i = 0;
	if (name)
	{
		while (ft_strcmp(g_env[i], name) != '=')
		{
			i++;
			if (g_env[i] == NULL)
				return (0);
		}
		while (g_env[i + 1])
		{
			g_env[i] = g_env[i + 1];
			i++;
		}
		g_env[i] = NULL;
		ft_ctrl_env();
		return (1);
	}
	else
		return (-1);
}
