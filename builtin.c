/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tettouat <tettouat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/21 17:12:58 by ebreda            #+#    #+#             */
/*   Updated: 2014/05/27 17:14:51 by tettouat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_42sh.h"

void	ft_builtin_exclamation(char *cmd, t_history *history)
{
	char	**tmp;
	char	**split;
	int		i;

	split = NULL;
	tmp = NULL;
	while (history->next != NULL)
	{
		i = 0;
		split = ft_strsplit(history->cmd, ';');
		while (split[i])
		{
			tmp = ft_strsplit(split[i], ' ');
			if (ft_strcmp(tmp[0], cmd + 1) == 0)
			{
				ft_putendl(history->cmd);
				ft_exec_cmd(history->cmd, history);
				return ;
			}
			i++;
		}
		history = history->next;
	}
}

void	builtin_unset(char *var, t_history *history)
{
	while (history->next != NULL)
	{
		if (ft_strcmp(history->vari, var) == 0)
		{
			history->vari = "";
			history->value_var = "";
			break ;
		}
		history = history->next;
	}
}

void	builtin_history(t_history *history)
{
	while (history->next != NULL)
		history = history->next;
	while (history)
	{
		ft_putendl(history->cmd);
		history = history->prev;
	}
}

int		ft_builtin_2(char **cmd, t_history *history)
{
	if (cmd[0] && cmd[0][0] == '!')
		ft_builtin_exclamation(cmd[0], history);
	else
		return (0);
	return (1);
}

int		is_builtin(char **cmd, char *line, t_history *history)
{
	if (ft_strcmp(cmd[0], "exit") == 0)
		builtin_exit(cmd);
	else if (ft_strcmp(cmd[0], "echo") == 0)
		ft_sh_echo(line, history);
	else if (ft_strcmp(cmd[0], "env") == 0)
		ft_puttabl(g_env);
	else if (ft_strcmp(cmd[0], "setenv") == 0)
		ft_setenv(line);
	else if (ft_strcmp(cmd[0], "unsetenv") == 0)
		ft_sh_unsetenv(line);
	else if (ft_strcmp(cmd[0], "cd") == 0)
		builtin_cd(cmd);
	else if (ft_strcmp(cmd[0], "history") == 0)
		builtin_history(history);
	else if (ft_strcmp(cmd[0], "read") == 0)
	{
		history = ft_read(history, cmd);
		history = history->next;
	}
	else if (ft_strcmp(cmd[0], "unset") == 0)
		builtin_unset(cmd[1], history);
	else
		return (ft_builtin_2(cmd, history));
	return (1);
}
