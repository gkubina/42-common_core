/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: event <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 14:00:49 by event             #+#    #+#             */
/*   Updated: 2023/10/18 12:23:06 by gkubina          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

size_t	ft_strlen_u(const unsigned char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
	{
		i++;
	}
	return (i);
}

size_t	ft_strlcpy_u(unsigned char *dst, const unsigned char *src, size_t size)
{
	size_t	i;

	i = 0;
	if (size == 0)
		return (ft_strlen_u(src));
	while (i < size - 1 && src[i] != '\0')
	{
		dst[i] = src [i];
		i++;
	}
	dst[i] = '\0';
	return (ft_strlen_u(src));
}
