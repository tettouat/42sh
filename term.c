/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   term.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tettouat <tettouat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/02 18:02:19 by aelola            #+#    #+#             */
/*   Updated: 2014/06/26 16:01:42 by tettouat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_42sh.h"

t_lst			*ft_list(char *dir, t_lst *lst, char *search)
{
	DIR				*rep;
	struct dirent	*lecture;

	rep = opendir(dir);
	if (rep != NULL)
	{
		while ((lecture = readdir(rep)))
		{
			if (lecture->d_name[0] != '.')
			{
				if ((int)ft_strlen(search) == 0)
					lst = ft_add_lst(lst, lecture->d_name);
				else if (search != NULL &&
					ft_strncmp(search, lecture->d_name, ft_strlen(search)) == 0)
					lst = ft_add_lst(lst, lecture->d_name);
			}
		}
	}
	closedir(rep);
	rep = NULL;
	return (lst);
}

int				set_42sh_mode(int flag, t_termios *term, t_term *st)
{
	(void)st;
	if (tcgetattr(0, term) == -1)
		return (-1);
	if (tgetent(st->buff, st->name_term) == -1)
		return (-1);
	if (flag == 1)
		term->c_lflag &= ~(ICANON | ECHO);
	else if (flag == 0)
		term->c_lflag |= (ICANON | ECHO);
	term->c_cc[VMIN] = 1;
	term->c_cc[VTIME] = 0;
	tcsetattr(0, 0, term);
	return (1);
}

char			*ft_get_link(char *line)
{
	int		i;
	int		p;
	char	*res;

	p = 0;
	i = 0;
	res = malloc(sizeof(char) * ft_strlen(line));
	while (line[i] != ' ')
		i++;
	while (line[++i])
	{
		res[p] = line[i];
		p++;
	}
	if (ft_strchr(line, '/'))
		while (res[p] != '/')
		{
			res[p] = '\0';
			p--;
		}
	else
		p = 0;
	if (p == 0)
		return (".");
	return (res);
}

t_history		*ft_press(char buff[4], t_term *st, t_history *h)
{
	if (buff[0] == 27 && buff[1] == 91 && buff[2] == 65)
		h = ft_press_up(st, h);
	else if (buff[0] == 27 && buff[1] == 91 && buff[2] == 66)
		h = ft_press_down(st, h);
	else if (buff[0] == 127)
		ft_press_del(st);
	return (h);
}

char			*ft_termcap(t_history *history)
{
	char			buff[4];
	t_term			*st;
	t_lst			*lst;
	t_termios		termi;

	st = malloc(sizeof(t_term));
	lst = ft_creat_list();
	ft_start_term(st, &termi);
	ft_print_line(st);
	while (history->next)
		history = history->next;
	while (42)
	{
		read(0, buff, 4);
		if (buff[0] == 9)
			lst = ft_press_tab(st, lst);
		else if (buff[0] == 10)
			return (ft_press_enter(st, history, &termi));
		else if (buff[0] == 127 || buff[0] == 27)
			history = ft_press(buff, st, history);
		else
			ft_press_other(st, buff);
		ft_print_line(st);
	}
	ft_free_lst(lst);
}
