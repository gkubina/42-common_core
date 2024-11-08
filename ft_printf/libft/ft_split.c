/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkubina <gkubina@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 10:40:31 by gkubina           #+#    #+#             */
/*   Updated: 2023/10/24 13:52:05 by gkubina          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_count_words(char const *s, char c)
{
	size_t	i;
	size_t	words;

	i = 0;
	words = 0;
	if (s[0] == '\0')
		return (words);
	if (s[0] != c)
		words++;
	while (s[++i] != '\0')
	{
		if (s[i] != c && s[i - 1] == c)
			words++;
	}
	return (words);
}

static char	*nextword(char const *s, char c)
{
	size_t	len;
	char	*word;

	len = 0;
	while (s[len] != '\0' && s[len] != c)
		len++;
	word = (char *) malloc (sizeof(char) * (len + 1));
	if (word == NULL)
		return (NULL);
	ft_strlcpy(word, s, len + 1);
	return (word);
}

static	char	**malloc_undo(char **s)
{
	size_t	i;

	i = 0;
	while (s[i])
	{
		free (s[i]);
		i++;
	}
	free (s);
	return (NULL);
}

static char	**alloc_words(const char *s, char c, size_t nb_words)
{
	char	**split;
	size_t	i;
	size_t	word;

	word = 0;
	i = 0;
	split = (char **) malloc (sizeof(char *) * (nb_words + 1));
	if (split == NULL)
		return (NULL);
	while (s[i] != '\0' && word < nb_words)
	{
		if (s[i] == c)
			i++;
		else
		{
			split[word] = nextword(s + i, c);
			if (split[word] == NULL)
				return (malloc_undo(split));
			i = i + ft_strlen(split[word]);
			word++;
		}
	}
	split[word] = NULL;
	return (split);
}

char	**ft_split(char const *s, char c)
{
	size_t	nb_words;

	nb_words = ft_count_words(s, c);
	return (alloc_words(s, c, nb_words));
}
