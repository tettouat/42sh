/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tettouat <tettouat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/16 12:49:10 by aelola            #+#    #+#             */
/*   Updated: 2014/05/21 15:42:24 by tettouat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_pipex.h"

void	*ft_realloc(void *ptr, size_t size)
{
	char	*bak;

	bak = (char *)malloc(sizeof(bak) * ft_strlen(ptr));
	ft_memcpy(bak, ptr, ft_strlen(ptr));
	ptr = (char *)malloc(sizeof(char *) * size);
	ft_memcpy(ptr, bak, ft_strlen(bak));
	return (ptr);
}
