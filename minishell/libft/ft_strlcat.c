/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: event <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 14:00:49 by event             #+#    #+#             */
/*   Updated: 2023/10/19 10:13:35 by gkubina          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	len_dst;
	size_t	i;
	size_t	len_tot;

	i = 0;
	len_dst = ft_strlen(dst);
	len_tot = 0;
	if (size == 0)
		return (ft_strlen(src));
	while (src[i] != '\0' && (len_dst + i) < size - 1)
	{
		dst[len_dst + i] = src[i];
		i++;
	}
	dst[len_dst + i] = '\0';
	if (size < len_dst)
		len_tot = size + ft_strlen(src);
	else
		len_tot = ft_strlen(src) + len_dst;
	return (len_tot);
}
