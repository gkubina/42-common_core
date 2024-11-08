/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memcmp.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daleliev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 09:28:12 by daleliev          #+#    #+#             */
/*   Updated: 2023/10/20 09:42:06 by daleliev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*pnt_s1;
	unsigned char	*pnt_s2;
	size_t			i;

	pnt_s1 = (unsigned char *) s1;
	pnt_s2 = (unsigned char *) s2;
	i = 0;
	while (i < n && pnt_s1[i] == pnt_s2[i])
		i++;
	if (i < n)
		return (pnt_s1[i] - pnt_s2[i]);
	else
		return (0);
}
