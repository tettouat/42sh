/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_history.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelola <aelola@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/03 12:18:32 by aelola            #+#    #+#             */
/*   Updated: 2014/06/03 12:18:32 by aelola           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_42sh.h"

char		*ft_history(t_history *history, int b)
{
	if (history->prev != NULL && b == 1)
		history = history->prev;
	else if (history->next != NULL && b == 2)
		history = history->next;
	ft_putstr(history->cmd);
	return (history->cmd);
}

t_history	*ft_creat_history(void)
{
	t_history	*new;

	new = malloc(sizeof(t_history));
	new->next = NULL;
	new->prev = NULL;
	new->cmd = "";
	return (new);
}

t_history	*ft_add_history(t_history *history, char *cmd)
{
	t_history	*new;

	while (history->next != NULL)
		history = history->next;
	if (ft_strlen(history->cmd) == 0 && ft_strlen(history->vari) == 0)
		new = history;
	else
	{
		new = malloc(sizeof(t_history));
		new->prev = history;
		new->next = NULL;
		history->next = new;
	}
	new->cmd = ft_strdup(cmd);
	return (new);
}
