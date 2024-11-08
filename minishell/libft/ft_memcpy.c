/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memcpy.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daleliev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 10:23:50 by daleliev          #+#    #+#             */
/*   Updated: 2023/10/19 10:33:34 by daleliev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	const char	*pnt_src;
	char		*pnt_dest;
	size_t		i;

	if (!dest && !src)
		return (dest);
	pnt_dest = (char *)dest;
	pnt_src = (const char *)src;
	i = 0;
	while (i < n)
	{
		pnt_dest[i] = pnt_src[i];
		i++;
	}
	return ((void *) pnt_dest);
}
