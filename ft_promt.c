/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_promt.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tettouat <tettouat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/14 15:12:47 by aelola            #+#    #+#             */
/*   Updated: 2014/06/02 20:16:46 by ebreda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_42sh.h"

static void		ft_promt_loc(char *s1, char *s2)
{
	int		i;

	i = 0;
	write(1, "~/", 2);
	while (*s1 == s2[i])
	{
		i++;
		s1++;
	}
	if (*s1)
	{
		s1++;
		write(1, s1, ft_strlen(s1));
		write(1, "/ ", 2);
	}
}

static void		ft_promt_pwd(char *s1, char *s2)
{
	char	*tmp;

	tmp = s1;
	while (ft_strcmp(s1, s2) != '/')
	{
		s1++;
		if (ft_strcmp(s1, s2) == 0)
		{
			write(1, "~/ ", 3);
			return ;
		}
		if (*s1 == '\0')
		{
			tmp++;
			write(1, "@/", 2);
			write(1, tmp, ft_strlen(tmp));
			if (*tmp)
				write(1, "/", 2);
			write(1, " ", 1);
			return ;
		}
	}
	ft_promt_loc(s1, s2);
}

void			ft_promt(void)
{
	write(1, "\033[36m", 5);
	write(1, ft_getentry("USER"), ft_strlen(ft_getentry("USER")));
	write(1, " ", 1);
	write(1, "\033[33m", 5);
	ft_promt_pwd(ft_getentry("PWD"), ft_getentry("HOME"));
	write(1, "\033[0m", 5);
}
