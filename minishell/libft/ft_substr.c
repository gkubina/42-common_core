/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daleliev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 13:08:22 by daleliev          #+#    #+#             */
/*   Updated: 2023/10/20 14:02:28 by daleliev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*final;

	i = ft_strlen(s);
	if (start < i)
		i = start;
	else
		start = i;
	while (s[i] && len)
	{
		len--;
		i++;
	}
	i++;
	final = malloc(i - start);
	if (!final)
		return (NULL);
	i--;
	final[i - start] = '\0';
	while (i > start)
	{
		i--;
		final[i - start] = s[i];
	}
	return (final);
}
