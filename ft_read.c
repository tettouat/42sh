/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tettouat <tettouat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/01 15:49:14 by ebreda            #+#    #+#             */
/*   Updated: 2014/06/23 19:19:59 by tettouat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_42sh.h"

t_history		*ft_add_var(t_history *history, char *vari, char *value)
{
	t_history	*newx;

	while (history->next != NULL)
		history = history->next;
	if (ft_strlen(history->cmd) == 0 && ft_strlen(history->vari) == 0)
		newx = history;
	else
	{
		newx = (t_history *)malloc(sizeof(t_history));
		newx->prev = history;
		newx->next = NULL;
		history->next = newx;
	}
	newx->vari = ft_strdup(vari);
	newx->value_var = ft_strdup(value);
	return (newx);
}

t_history		*ft_read(t_history *var, char **cmd)
{
	char		*buff;

	buff = (char *)malloc(sizeof(char) * 4096);
	if (ft_tablen(cmd) != 2 || cmd[1][0] != '$')
		TG_BASTARD
	read(0, buff, 4096);
	buff[ft_strlen(buff) - 1] = '\0';
	var = ft_add_var(var, cmd[1], buff);
	free(buff);
	return (var);
}
