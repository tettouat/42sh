/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_path.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelola <aelola@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/22 00:28:20 by aelola            #+#    #+#             */
/*   Updated: 2014/05/22 00:28:21 by aelola           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_42sh.h"

char			*ft_strnew_path(char *str)
{
	int		i;
	char	*tmp;
	char	**path;

	i = 0;
	if (access(str, R_OK) != -1)
		return (str);
	path = ft_strsplit(ft_getentry("PATH"), ':');
	while (path[i] != NULL)
	{
		tmp = ft_sh_strjoin(path[i], str, "/");
		if (access(tmp, R_OK) != -1)
		{
			ft_strdel(path);
			return (tmp);
		}
		i++;
		ft_strdel(&tmp);
	}
	ft_strdel(path);
	return (NULL);
}
