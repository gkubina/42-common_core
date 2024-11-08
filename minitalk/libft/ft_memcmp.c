/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkubina <gkubina@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 11:24:58 by gkubina           #+#    #+#             */
/*   Updated: 2023/10/19 13:20:59 by gkubina          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t	i;
	char	*c1;
	char	*c2;

	c1 = (char *) s1;
	c2 = (char *) s2;
	i = 0;
	if (n == 0)
		return (0);
	while (i < n - 1)
	{
		if (c1[i] - c2[i] != 0)
			return ((unsigned char) c1[i] - (unsigned char) c2[i]);
		i++;
	}
	return ((unsigned char) c1[i] - (unsigned char) c2[i]);
}
