/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkubina <gkubina@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 15:18:02 by gkubina           #+#    #+#             */
/*   Updated: 2023/10/19 15:24:40 by gkubina          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	size_t	len;
	size_t	i;
	char	*dup;

	len = ft_strlen(s);
	dup = (char *) malloc(sizeof (char) * (len + 1));
	i = 0;
	if (dup == NULL)
		return (NULL);
	while (i <= len)
	{
		dup[i] = s[i];
		i++;
	}
	return (dup);
}
