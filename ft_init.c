/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tettouat <tettouat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/12 13:13:27 by aelola            #+#    #+#             */
/*   Updated: 2014/06/14 17:08:12 by tettouat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_42sh.h"

void			init_st(t_term *st)
{
	st->fd = open("/dev/tty", O_RDWR);
	st->line = malloc(sizeof(char) * 10);
	st->retrn = "toto";
	st->b = 0;
	st->i = 0;
	st->link = "toto";
	st->search = NULL;
	st->i_path = 0;
	st->tmp_line = malloc(sizeof(char) * 10);
}

void			ft_start_term(t_term *st, t_termios *term)
{
	init_st(st);
	if ((st->name_term = getenv("TERM")) == NULL)
		st->name_term = "xterm-256color";
	set_42sh_mode(1, term, st);
}
