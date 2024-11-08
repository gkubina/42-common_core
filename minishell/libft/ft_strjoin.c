/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daleliev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 14:04:48 by daleliev          #+#    #+#             */
/*   Updated: 2023/10/20 14:55:43 by daleliev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*final;
	int		i;
	int		j;

	final = malloc((ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof(char));
	if (final == NULL)
		return (NULL);
	i = 0;
	while (s1[i] != '\0')
	{
		final[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j] != '\0')
	{
		final[i] = s2[j];
		i++;
		j++;
	}
	final[i] = '\0';
	return (final);
}
