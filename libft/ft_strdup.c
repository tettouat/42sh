/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelola <aelola@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/04/13 17:36:45 by aelola            #+#    #+#             */
/*   Updated: 2014/04/13 17:36:46 by aelola           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	size_t	len;
	char	*scpy;

	len = ft_strlen(s1) + 1;
	if ((scpy = (char *)malloc(len)) == NULL)
		return (NULL);
	ft_memcpy(scpy, s1, len);
	return (scpy);
}
