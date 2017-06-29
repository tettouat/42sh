/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tettouat <tettouat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/12 13:17:17 by aelola            #+#    #+#             */
/*   Updated: 2014/06/23 17:57:16 by tettouat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_42sh.h"

int		split_builtin_exit(char **name, int i)
{
	while (name[1][++i])
	{
		if (ft_isdigit((int)name[1][i]) == 0)
		{
			ft_putstr("exit: Expression syntax.\n");
			return (1);
		}
	}
	return (0);
}

void	builtin_exit(char **name)
{
	int	nbr;
	int	i;
	int	fd;

	fd = open("/dev/tty", O_RDWR);
	if (name[1])
	{
		if (!name[2])
		{
			i = -1;
			if (split_builtin_exit(name, i) == 1)
				return ;
			nbr = ft_atoi(name[1]);
			if (nbr > 255)
				nbr = 0;
			ft_putendl("\033[31mexiting minishell2...\033[0m");
			ft_putstr_fd(tgetstr("ve", NULL), fd);
			exit(nbr);
		}
		ft_putstr("exit: Expression syntax.\n");
		return ;
	}
	ft_putendl("\033[31mexiting 42sh...\033[0m");
	ft_putstr_fd(tgetstr("ve", NULL), fd);
	exit(0);
}
