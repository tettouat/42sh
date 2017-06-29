/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tettouat <tettouat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/21 15:41:54 by tettouat          #+#    #+#             */
/*   Updated: 2015/03/02 16:55:44 by tettouat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_42sh.h"

void		put_msg(char *msg, char *msg2)
{
	char	*tmp;

	ft_putstr(tmp = ft_strjoin(msg, msg2));
	free(tmp);
}

void		ft_setentry(char *field, char *str)
{
	int			pos;
	char		*tmp;

	pos = ft_findentry(field);
	tmp = ft_strdup(ft_strjoin(ft_strjoin(field, "="), str));
	if (pos != -1)
		g_env[pos] = ft_strdup(tmp);
	else
		g_env = ft_addentry(tmp);
	ft_ctrl_env();
	free(tmp);
}

int			ft_findentry(char *field)
{
	int		i;
	char	**spt;

	i = 0;
	spt = NULL;
	while (g_env[i] != '\0')
	{
		spt = ft_strsplit(g_env[i], '=');
		if (ft_strcmp(spt[0], field) == 0)
			return (i);
		i++;
	}
	return (-1);
}

char		**ft_addentry(char *str)
{
	char		**tmp;
	int			i;

	i = 0;
	tmp = (char **)malloc(sizeof(char *) * (ft_tablen(g_env) + 2));
	if (tmp != NULL)
	{
		while (g_env[i] != '\0')
		{
			tmp[i] = ft_strdup(g_env[i]);
			i++;
		}
		tmp[i] = ft_strdup(str);
		tmp[i + 1] = 0;
	}
	return (tmp);
}
