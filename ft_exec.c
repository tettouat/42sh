/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exec.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tettouat <tettouat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/16 12:27:51 by aelola            #+#    #+#             */
/*   Updated: 2014/06/23 18:25:39 by tettouat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_42sh.h"

int			ft_check_double(char *line, char c)
{
	int		i;

	i = 0;
	while (line[i])
	{
		if (line[i] == c && line[i + 1] == c)
			return (0);
		i++;
	}
	return (1);
}

void		split_42sh(char *str, char **tmp, char **spt)
{
	pid_t	pid;

	if ((pid = fork()) == -1)
	{
		ft_putstr_fd("fork Error", 2);
		builtin_exit(tmp);
	}
	else if (pid > 0)
		wait(NULL);
	else
	{
		if (execve(str, spt, g_env) == -1)
			exit(0);
	}
}

int			ft_42sh(char *line)
{
	char	*str;
	char	**spt;
	char	**tmp;

	tmp = ft_strsplit_ft(line, ft_isblank);
	spt = ft_strsplit(line, ' ');
	str = ft_strnew_path(spt[0]);
	if (str)
		split_42sh(str, tmp, spt);
	else
	{
		if (spt[0][0] < 32 || spt[0][0] > 126)
			spt[0] = " ";
		ft_putstr(spt[0]);
		ft_putstr(" : comand not found\n");
		return (-1);
	}
	return (0);
}

int			ft_point_virgule(char *line, char **tabl, t_history *history)
{
	int		i;

	tabl = ft_strsplit(line, ';');
	i = 0;
	while (tabl[i])
	{
		tabl[i] = ft_strtrim(tabl[i]);
		if (ft_strchr(tabl[i], '>') || ft_strchr(tabl[i], '<'))
			ft_redirect(tabl[i], history);
		else if (ft_strchr(tabl[i], '|'))
			ft_pipex(tabl[i]);
		else if (ft_sh_command(tabl[i], history))
			return (0);
		i++;
	}
	return (1);
}

int			ft_exec_cmd(char *line, t_history *history)
{
	if (ft_strchr_str(line, "&&") == 1 || ft_strchr_str(line, "||") == 1)
		ft_operator(line, history);
	else if (ft_strchr(line, '>') || ft_strchr(line, '<'))
		ft_redirect(line, history);
	else if (ft_strchr(line, '|'))
		ft_pipex(line);
	else if (ft_sh_command(line, history))
		return (0);
	return (1);
}
