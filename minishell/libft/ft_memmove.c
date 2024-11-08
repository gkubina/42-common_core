/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memmove.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daleliev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/21 15:54:43 by daleliev          #+#    #+#             */
/*   Updated: 2023/10/21 15:55:40 by daleliev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t	i;
	char	*d;
	char	*s;

	i = -1;
	s = (char *)src;
	d = (char *)dest;
	if (!dest && !src)
		return (NULL);
	if (src < dest)
	{
		while (n)
		{
			d[n - 1] = s[n - 1];
			n--;
		}
	}
	else if (src > dest)
	{
		while (++i < n)
			d[i] = s[i];
	}
	return (dest);
}
