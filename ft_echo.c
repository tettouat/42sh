/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_echo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebreda <ebreda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/11 16:45:17 by ebreda            #+#    #+#             */
/*   Updated: 2014/06/11 16:45:17 by ebreda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_42sh.h"

void		ft_search_list(char *var, t_history *history)
{
	while (history)
	{
		if (history->vari != NULL && ft_strcmp(var, history->vari) == 0)
		{
			ft_putstr(history->value_var);
			break ;
		}
		history = history->next;
	}
}

int			ft_echo_var(char *line, int i, t_history *history)
{
	char	*var;
	int		c;

	c = 0;
	var = malloc(sizeof(char) * ft_strlen(line));
	while (line[i] != ' ' && line[i])
	{
		var[c] = line[i];
		i++;
		c++;
	}
	var[c] = '\0';
	ft_search_list(var, history);
	free(var);
	return (i);
}

void		ft_sh_echo(char *line, t_history *history)
{
	int		i;

	i = 0;
	while (line[i] != ' ')
		i++;
	while (line[i])
	{
		i++;
		if (line[i] == '$')
			i = ft_echo_var(line, i, history);
		else
		{
			if (line[i] != '\"')
				write(1, &line[i], 1);
		}
	}
	write(1, "\n", 1);
}
