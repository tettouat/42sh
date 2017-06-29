/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_press_button.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tettouat <tettouat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/11 19:20:12 by ebreda            #+#    #+#             */
/*   Updated: 2014/06/17 15:43:37 by tettouat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_42sh.h"

t_lst			*ft_press_tab(t_term *st, t_lst *lst)
{
	if (ft_strchr(st->line, ' ') != NULL)
	{
		st->tmp = ft_strdup(st->line);
		if (st->b == 0)
		{
			st->path = ft_strsplit_ft(st->line, ft_is_slash_space);
			st->search = st->path[ft_tablen(st->path) - 1];
			st->link = ft_get_link(st->line);
			lst = ft_list(st->link, lst, st->search);
		}
		ft_print_all_find(lst, st->search, st->b);
		st->b = 1;
		lst = lst->next;
		st->retrn = ft_write_line(st->tmp, lst, st->fd);
		st->line = ft_strdup(st->retrn);
		st->i = (int)ft_strlen(st->line);
	}
	return (lst);
}

t_history		*ft_press_up(t_term *st, t_history *history)
{
	st->retrn = history->cmd;
	st->line = st->retrn;
	ft_putchar('\n');
	ft_putstr_fd(tgetstr("up", NULL), st->fd);
	ft_promt();
	ft_putstr(st->retrn);
	ft_putstr_fd(tgetstr("ce", NULL), st->fd);
	if (history->prev != NULL)
		history = history->prev;
	return (history);
}

t_history		*ft_press_down(t_term *st, t_history *history)
{
	st->retrn = history->cmd;
	st->line = st->retrn;
	ft_putchar('\n');
	ft_putstr_fd(tgetstr("up", NULL), st->fd);
	ft_promt();
	ft_putstr(st->retrn);
	ft_putstr_fd(tgetstr("ce", NULL), st->fd);
	if (history->next != NULL)
		history = history->next;
	return (history);
}

char			*ft_press_enter(t_term *st, t_history *hist, t_termios *te)
{
	if (!ft_strcmp(st->retrn, "toto"))
		st->retrn = ft_strdup(st->line);
	hist = ft_add_history(hist, st->retrn);
	set_42sh_mode(0, te, st);
	write(1, "\n", 1);
	return (st->retrn);
}

void			ft_press_del(t_term *st)
{
	ft_putstr_fd(tgetstr("ce", NULL), st->fd);
	st->i--;
	st->line[st->i] = '\0';
}
