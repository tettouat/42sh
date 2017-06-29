/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sh_command.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tettouat <tettouat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/14 15:13:03 by aelola            #+#    #+#             */
/*   Updated: 2014/05/26 16:13:03 by tettouat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_42sh.h"

char	*ft_sh_strjoin(char *s1, char *s2, char *bet)
{
	char	*tmp;

	tmp = ft_strnew(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (s1)
		tmp = ft_strcat(tmp, s1);
	if (bet)
		tmp = ft_strcat(tmp, bet);
	if (s2)
		tmp = ft_strcat(tmp, s2);
	return (tmp);
}

int		ft_sh_command(char *line, t_history *history)
{
	char	**tmp;

	line = ft_strtrim(line);
	tmp = ft_strsplit_ft(line, ft_isblank);
	if (is_builtin(tmp, line, history))
		;
	else if (ft_strcmp(tmp[0], "exit") == 0)
		builtin_exit(tmp);
	else if (ft_42sh(line) == -1)
		return (-1);
	return (0);
}
