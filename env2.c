/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env2.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tettouat <tettouat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/21 15:43:58 by tettouat          #+#    #+#             */
/*   Updated: 2014/05/21 17:47:42 by tettouat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_42sh.h"

char		*ft_getentry(char *field)
{
	int		size;
	int		i;

	size = ft_strlen(field);
	i = 0;
	while (g_env[i])
	{
		if (ft_strcmp(g_env[i], field) == '=')
			return (ft_strdup(g_env[i] + (size + 1)));
		i++;
	}
	return (NULL);
}

char		*get_full_path(char *newx)
{
	int		i;
	char	**path;

	if (newx[0] == '/')
		return (newx);
	i = -1;
	while (g_env[++i])
	{
		if (ft_strncmp(g_env[i], "PWD=", 4) == 0)
		{
			path = ft_strsplit(g_env[i], '=');
			return (ft_strjoin(path[1], ft_strjoin("/", newx)));
		}
	}
	return (NULL);
}

void		pwd_previous(void)
{
	chdir(ft_getentry("OLDPWD="));
	ft_setentry("OLDPWD=", ft_getentry("PWD="));
	ft_setentry("PWD=", getcwd(NULL, 0));
}

char		**ft_realloc_free(char **s, char *elem)
{
	int		n;
	char	**cpy;

	n = 0;
	while (s[n])
		n++;
	cpy = (char **)ft_memalloc(sizeof(char *) * (n + 2));
	cpy[n] = ft_strdup(elem);
	cpy[n + 1] = 0;
	while (--n >= 0)
		cpy[n] = s[n];
	free(s);
	return (cpy);
}
