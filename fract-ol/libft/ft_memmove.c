/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: event <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 14:00:49 by event             #+#    #+#             */
/*   Updated: 2023/10/18 11:53:42 by gkubina          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t			i;
	unsigned char	*d;
	unsigned char	*s;

	if ((!dest && !src) || n == 0 || dest == src)
		return (dest);
	if (dest < src)
		return (ft_memcpy(dest, src, n));
	i = n;
	d = (unsigned char *)dest;
	s = (unsigned char *)src;
	while (i > 0)
	{
		d[i - 1] = s[i - 1];
		i--;
	}
	return (dest);
}
