/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelola <aelola@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/04/13 17:38:49 by aelola            #+#    #+#             */
/*   Updated: 2014/04/13 17:38:49 by aelola           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	int		i;
	char	*str;

	i = 0;
	if (s == NULL || f == NULL)
		return (NULL);
	str = (char *)malloc(ft_strlen(s) * sizeof(char));
	if (str)
	{
		while (s[i] != '\0')
		{
			str[i] = (*f)(s[i]);
			i++;
		}
	}
	return (str);
}
