/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_operator2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tettouat <tettouat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/12 13:19:34 by aelola            #+#    #+#             */
/*   Updated: 2014/06/17 15:41:24 by tettouat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_42sh.h"

char		*ft_strsplit_op(char *line, int j, int i)
{
	char	*res;
	int		p;

	p = 0;
	res = malloc(sizeof(char) * j - i);
	while (i < j)
	{
		res[p] = line[i];
		i++;
		p++;
	}
	res[p] = '\0';
	return (res);
}

int			ft_doucle_pipe(char *cmd)
{
	int		i;

	i = 0;
	while (cmd[i + 1])
	{
		if (cmd[i] == '|' && cmd[i + 1] == '|')
			return (1);
		i++;
	}
	return (-1);
}

int			ft_many_op(char *line)
{
	int		i;
	int		res;

	i = 0;
	res = 0;
	while (line[i + 2])
	{
		if ((line[i] == '&' && line[i + 1] == '&')
			|| (line[i] == '|' && line[i + 1] == '|'))
			res++;
		i++;
	}
	res += 2;
	return (res);
}

int			ft_long(char *line, int i)
{
	while (line[i])
	{
		if ((line[i] == '&' && line[i + 1] == '&')
			|| (line[i] == '|' && line[i + 1] == '|') || line[i + 1] == '\0')
			return (i + 1);
		i++;
	}
	return (i);
}

int			ft_op(char *cmd, t_history *history)
{
	if (ft_strchr(cmd, '>') || ft_strchr(cmd, '<'))
	{
		if (ft_redirect(cmd, history) == -1)
			return (-1);
	}
	else if (ft_strchr(cmd, '|') && ft_doucle_pipe(cmd) == -1)
	{
		if (ft_pipex(cmd) == -1)
			return (-1);
	}
	else
	{
		if (ft_sh_command(cmd, history) == -1)
			return (-1);
	}
	return (1);
}
