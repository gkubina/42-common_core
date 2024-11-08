/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkubina <gkubina@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 15:03:21 by gkubina           #+#    #+#             */
/*   Updated: 2023/10/20 15:38:05 by gkubina          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_checkset(char c, char const *set)
{
	size_t	i;

	i = 0;
	while (set[i] != '\0')
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	pre;
	size_t	suf;

	pre = 0;
	suf = ft_strlen(s1) - 1;
	while (ft_checkset(s1[pre], set) == 1)
		pre++;
	while (ft_checkset(s1[suf], set) == 1)
		suf--;
	return (ft_substr(s1, pre, suf - pre + 1));
}
