/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebreda <ebreda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/22 10:05:32 by ebreda            #+#    #+#             */
/*   Updated: 2013/12/29 21:48:30 by ebreda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t		ft_putstr(char const *s)
{
	int		nbr;

	if (s)
	{
		nbr = ft_strlen(s);
		write(1, s, nbr);
		return (nbr);
	}
	else
		return (ft_putstr("(null)"));
}
