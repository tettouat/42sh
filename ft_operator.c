/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_operator.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tettouat <tettouat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/22 02:16:45 by aelola            #+#    #+#             */
/*   Updated: 2014/06/02 15:22:54 by tettouat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_42sh.h"

int			ft_or(t_operator *op, t_history *history, char *line)
{
	op->cmd = ft_strsplit_op(line, op->i, op->count);
	if (ft_op(op->cmd, history) != -1)
		return (1);
	op->i += 2;
	op->count = op->i;
	return (0);
}

int			ft_and(t_operator *op, t_history *history, char *line)
{
	op->cmd = ft_strsplit_op(line, op->i, op->count);
	if (ft_op(op->cmd, history) == -1)
		return (1);
	op->i += 2;
	op->count = op->i;
	return (0);
}

void		ft_init_op(t_operator *op, char *line)
{
	op->i = -1;
	op->count = 0;
	op->cmd = malloc(sizeof(char) * ft_strlen(line));
}

int			ft_operator(char *line, t_history *history)
{
	t_operator	op;
	static int	bol = 0;

	ft_init_op(&op, line);
	while (line[++op.i])
	{
		if ((line[op.i] == '&' && line[op.i + 1] == '&'))
		{
			if ((bol = ft_and(&op, history, line)) == 1)
				return (-1);
		}
		else if ((line[op.i] == '|' && line[op.i + 1] == '|'))
		{
			if ((bol = ft_or(&op, history, line)) == 1)
				return (-1);
		}
		else if (line[op.i + 1] == '\0')
		{
			op.cmd = ft_strsplit_op(line, op.i + 1, op.count);
			if (bol == 0)
				ft_op(op.cmd, history);
			bol = 0;
		}
	}
	return (0);
}
