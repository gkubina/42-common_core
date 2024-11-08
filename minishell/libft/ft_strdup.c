/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strdup.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daleliev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 12:28:36 by daleliev          #+#    #+#             */
/*   Updated: 2023/10/20 12:49:47 by daleliev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*final;
	int		i;

	final = malloc(((ft_strlen(s)) + 1) * sizeof(char));
	if (final == NULL)
		return (NULL);
	i = 0;
	while (s[i] != '\0')
	{
		final[i] = s[i];
		i++;
	}
	final[i] = '\0';
	return (final);
}
