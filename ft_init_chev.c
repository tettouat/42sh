/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_chev.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tettouat <tettouat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/16 14:46:15 by aelola            #+#    #+#             */
/*   Updated: 2014/06/17 15:51:13 by tettouat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_42sh.h"

void	ft_init_chev(int *i, char **cmd, char ***tabl, char *line)
{
	*i = 1;
	*cmd = " ";
	*tabl = ft_strsplit(line, '<');
	*tabl = ft_strsplit(*tabl[0], ' ');
	*tabl[0] = ft_strtrim(*tabl[0]);
}
