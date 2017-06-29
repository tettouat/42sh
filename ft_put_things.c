/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_things.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tettouat <tettouat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/11 19:34:00 by ebreda            #+#    #+#             */
/*   Updated: 2015/03/02 16:56:25 by tettouat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_42sh.h"

static char		*ft_strcut(char *str, char c)
{
	int		i;

	i = ft_strlen(str);
	if (str == NULL)
		return (str);
	while (str[i] != c)
		i--;
	str[i + 1] = '\0';
	return (str);
}

char			*ft_write_line(char *line, t_lst *lst, int fd)
{
	char	*res;

	write(1, "\n", 1);
	res = malloc(sizeof(char) * ft_strlen(line) + ft_strlen(lst->str));
	if (ft_strchr(line, '/') != NULL)
		line = ft_strcut(line, '/');
	else
		line = ft_strcut(line, ' ');
	res = ft_strjoin(line, lst->str);
	ft_putstr_fd(tgetstr("up", NULL), fd);
	ft_putstr_fd(tgetstr("ce", NULL), fd);
	return (res);
}

void			ft_print_all_find(t_lst *lst, char *str, int b)
{
	t_lst	*tmp;
	int		size;
	int		i;

	i = 0;
	tmp = lst;
	size = ft_strlen(str);
	lst = lst->next;
	if (b == 0)
	{
		while (tmp != lst)
		{
			if (ft_strncmp(str, lst->str, size) == 0 || ft_strlen(str) == 0)
			{
				ft_putchar('\n');
				ft_putstr(lst->str);
				i++;
			}
			lst = lst->next;
		}
	}
}

void			ft_print_line(t_term *st)
{
	ft_putchar('\n');
	ft_putstr_fd(tgetstr("up", NULL), st->fd);
	ft_promt(g_env);
	ft_putstr(st->line);
}
