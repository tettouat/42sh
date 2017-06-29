/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_completion.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tettouat <tettouat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/28 14:19:46 by aelola            #+#    #+#             */
/*   Updated: 2014/06/06 18:08:35 by tettouat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_42sh.h"

char		**ft_comple(char *dir)
{
	DIR				*rep;
	struct dirent	*lecture;
	char			**tabll;
	int				i;

	tabll = malloc (sizeof(char *) * 1000000);
	i = 0;
	rep = opendir(dir);
	if (rep != NULL)
	{
		while ((lecture = readdir(rep)))
		{
			if ((lecture->d_name)[0] != '.')
			{
				tabll[i] = ft_strdup(lecture->d_name);
				i++;
			}
		}
	}
	closedir(rep);
	rep = NULL;
	return (tabll);
}
