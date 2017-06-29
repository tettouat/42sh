/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnclr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tettouat <tettouat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/16 12:47:36 by aelola            #+#    #+#             */
/*   Updated: 2014/05/21 17:47:45 by tettouat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_42sh.h"

char	*ft_strnclr(char *str, int n)
{
	char	*tmp;
	int		len;

	len = n;
	while (str[len])
		len++;
	tmp = (char *)malloc(sizeof(tmp) * len);
	len = 0;
	while (str[n])
		tmp[len++] = str[n++];
	return (tmp);
}
