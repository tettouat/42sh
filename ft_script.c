/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_script.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelola <aelola@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/26 15:27:49 by aelola            #+#    #+#             */
/*   Updated: 2014/05/26 15:27:50 by aelola           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_42sh.h"

static char		*ft_exec(char *str)
{
	int		i;
	int		fd;
	int		ret;
	char	buff[4096];

	i = 0;
	if ((fd = open(str, O_RDONLY)) == -1)
		write(1, "open error\n", 11);
	ret = read(fd, buff, 4096);
	buff[ret] = '\0';
	str = ft_strdup(buff);
	while (str[i])
	{
		if (str[i] == '\n')
		{
			str[i] = ';';
		}
		i++;
	}
	return (str);
}

static int		ft_file(char *res)
{
	struct stat		s_buf;

	stat(res, &s_buf);
	if (s_buf.st_mode == 33188)
		return (1);
	return (-1);
}

static int		ft_longe(char *line)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (line[i])
	{
		if ((line[i] == '.' && line[i + 1] == '/')
			|| (line[i] == '.' && line[i + 1] == '.' && line[i + 2] == '/'))
			j++;
		if (line[i] == ' ')
			break ;
		i++;
	}
	return (i - j);
}

static int		ft_moov(char *line, int i)
{
	if (line[i] == '.')
	{
		i++;
		ft_moov(line, i);
	}
	if (line[i] == '/')
	{
		i++;
		ft_moov(line, i);
	}
	return (i);
}

char			*ft_script(char *line)
{
	char	*res;
	int		i;
	int		j;

	res = malloc(sizeof(char) * ft_longe(line));
	j = 0;
	i = ft_moov(line, 0);
	while (line[i])
	{
		if (line[i] != '.' || line[i] != '/')
		{
			res[j] = line[i];
			j++;
		}
		i++;
		if (line[i] == ' ')
		{
			res[j] = '\0';
			break ;
		}
	}
	res[j] = '\0';
	if (ft_file(res) == 1)
		res = ft_exec(res);
	return (res);
}
