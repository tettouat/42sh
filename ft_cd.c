/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelola <aelola@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/22 01:44:54 by aelola            #+#    #+#             */
/*   Updated: 2014/05/22 01:44:54 by aelola           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_42sh.h"
#include <errno.h>

static void		ft_cd_error(int i, char **cmd)
{
	if (ENOENT == i)
		ft_putstr_fd("cd: no such file or directory: ", 2);
	else if (ENOTDIR == i)
		ft_putstr_fd("cd: not a directory: ", 2);
	else if (EACCES == i)
		ft_putstr_fd("cd: permission denied: ", 2);
	else
		ft_putstr_fd("cd: error: ", 2);
	ft_putendl_fd(cmd[1], 2);
}

void			builtin_cd(char **cmd)
{
	char	*tmp;

	tmp = ft_strdup(ft_getentry("OLDPWD"));
	ft_setentry("OLDPWD", getcwd(NULL, 0));
	if (ft_tablen(cmd) == 1 && chdir(ft_getentry("HOME")) != -1)
		ft_setentry("PWD", getcwd(NULL, 0));
	else if (ft_strcmp(cmd[1], "-") == 0 && chdir(tmp) != -1)
		ft_setentry("PWD", getcwd(NULL, 0));
	else if (cmd[1][0] == '/' && chdir(cmd[1]) != -1)
		ft_setentry("PWD", getcwd(NULL, 0));
	else if (chdir(ft_strjoin("./", cmd[1])) != -1)
		ft_setentry("PWD", getcwd(NULL, 0));
	else
		ft_cd_error(errno, cmd);
}
