/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkubina <gkubina@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 10:53:17 by gkubina           #+#    #+#             */
/*   Updated: 2023/10/20 13:42:54 by gkubina          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*sub;
	size_t	len_sub;
	size_t	len_s;

	len_s = ft_strlen(s);
	if (len == 0 || start >= len_s)
		len_sub = 1;
	else if (len + start > len_s)
		len_sub = len_s - start + 1;
	else
		len_sub = len + 1;
	sub = malloc (len_sub);
	if (sub == NULL)
		return (NULL);
	if (start < len_s)
		ft_strlcpy(sub, (char *)(s + start), len_sub);
	else
		sub[0] = '\0';
	return (sub);
}
