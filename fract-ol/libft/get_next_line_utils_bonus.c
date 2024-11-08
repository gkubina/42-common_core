/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkubina <gkubina@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 12:07:00 by gkubina           #+#    #+#             */
/*   Updated: 2023/11/14 12:07:02 by gkubina          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*ft_strchr(const char *s, int c)
{
	size_t	i;
	char	ch;

	ch = (char) c;
	i = 0;
	while (s && s[i] != '\0' && s[i] != ch)
		i++;
	if (s && ch == s[i])
		return ((char *) s + i);
	return (NULL);
}

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s && s[i])
	{
		i++;
	}
	return (i);
}

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	i;

	i = 0;
	if (size == 0)
		return (ft_strlen(src));
	while (src && i < size - 1 && src[i] != '\0')
	{
		dst[i] = src [i];
		i++;
	}
	dst[i] = '\0';
	return (ft_strlen(src));
}

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
	while (src && src[i] != '\0' && (len_dst + i) < size - 1)
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

char	*ft_strjoin_free(char *s1, char const *s2)
{
	size_t	len_s1;
	size_t	len_s2;
	char	*join;

	len_s1 = ft_strlen(s1);
	len_s2 = ft_strlen(s2);
	join = malloc(len_s1 + len_s2 + 1);
	if (join == NULL)
	{
		if (s1)
			free (s1);
		return (NULL);
	}
	ft_strlcpy(join, s1, len_s1 + 1);
	ft_strlcat(join, s2, len_s1 + len_s2 + 1);
	if (s1 != NULL)
		free (s1);
	return (join);
}
