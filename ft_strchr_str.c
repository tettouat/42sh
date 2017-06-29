/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr_str.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelola <aelola@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/22 02:22:43 by aelola            #+#    #+#             */
/*   Updated: 2014/05/22 02:22:43 by aelola           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_42sh.h"

int		ft_strchr_str(char *line, char *str)
{
	int		i;

	i = 0;
	while (line[i + 1])
	{
		if (line[i] == str[0] && line[i + 1] == str[1])
			return (1);
		i++;
	}
	return (-1);
}
