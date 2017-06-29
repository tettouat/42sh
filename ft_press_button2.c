/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_press_button2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebreda <ebreda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/11 19:32:04 by ebreda            #+#    #+#             */
/*   Updated: 2014/06/26 12:37:43 by ebreda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_42sh.h"

void			ft_press_other(t_term *st, char buff[])
{
	st->b = 0;
	if (ft_isprint(buff[0]))
	{
		buff[1] = '\0';
		st->line = ft_strjoin(st->line, &buff[0]);
		st->i++;
	}
}

int				ft_is_slash_space(int c)
{
	if (c == ' ' || c == '/')
		return (1);
	else
		return (0);
}
