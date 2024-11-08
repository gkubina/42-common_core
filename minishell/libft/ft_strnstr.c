/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strnstr.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daleliev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 15:54:18 by daleliev          #+#    #+#             */
/*   Updated: 2023/10/17 17:35:52 by daleliev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;
	size_t	save;

	if (little[0] == '\0')
		return ((char *)big);
	i = 0;
	while (big[i] != '\0' && i < len)
	{
		j = 0;
		save = i;
		if (little[j] == big[i])
		{
			while (little[j] == big[i] && i < len && big[i] != '\0')
			{
				j++;
				i++;
			}
			if (little[j] == '\0')
				return ((char *)big + save);
		}
		i = save;
		i++;
	}
	return (NULL);
}
