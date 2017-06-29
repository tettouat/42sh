/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit_ft.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebreda <ebreda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/28 10:08:53 by ebreda            #+#    #+#             */
/*   Updated: 2014/04/27 18:59:37 by ebreda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char		**ft_modtabl(char **tabl, char *mot, int len)
{
	char		**tmp;
	int			i;
	int			k;

	tmp = (char **)malloc((len + 1) * sizeof(char *));
	if (tmp)
	{
		ft_bzero(tmp, (len + 1));
		i = 0;
		k = 0;
		while (tabl && (i < len))
		{
			if (tabl[i])
			{
				tmp[k] = tabl[i];
				tabl[i] = NULL;
				k++;
			}
			i++;
		}
		tmp[k] = mot;
		tmp[k + 1] = NULL;
	}
	return (tmp);
}

char			**ft_strsplit_ft(char const *s, int (*f)(int))
{
	int		i;
	int		loop;
	char	*tmp_mot;
	char	**tmp_tabl;

	tmp_tabl = ft_modtabl(NULL, NULL, 0);
	tmp_mot = NULL;
	loop = 0;
	while (s && *s && tmp_tabl)
	{
		loop++;
		i = 0;
		while (f(*s) && *s != '\0')
			s++;
		while (!f(s[i]) && s[i] != '\0')
			i++;
		if (i != 0)
		{
			tmp_mot = ft_strsub(s, 0, i);
			tmp_tabl = ft_modtabl(tmp_tabl, tmp_mot, loop);
		}
		s += i;
	}
	return (tmp_tabl);
}
