/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_quotes.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkubina <gkubina@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 10:40:31 by gkubina           #+#    #+#             */
/*   Updated: 2024/05/06 14:32:00 by gkubina          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

static size_t	ft_count_words(char *s)
{
	size_t	i;
	size_t	words;

	i = 0;
	words = 0;
	if (s[0] == '\0')
		return (words);
	if (s[0] != ' ')
		words++;
	while (s[++i] != '\0')
	{
		if (s[i] != ' ' && s[i - 1] == ' ')
			words++;
	}
	return (words);
}

// if nb_words = 1 -> no quotes

static char	*quote_words(char *s, size_t nb_words)
{
	char	*quoted;
	char	*string;
	char	*output;

	string = s;
	output = (char *)
		malloc (sizeof(char) * (ft_strlen (s) + (nb_words * 2) + 1));
	if (output == NULL)
		return (NULL);
	quoted = output;
	while (*string != '\0')
	{
		while (*string == ' ')
			*quoted++ = *string++;
		if (nb_words != 1)
			*quoted++ = '\'';
		while (*string != ' ' && *string != '\0' )
			*quoted++ = *string++;
		if (nb_words != 1)
			*quoted++ = '\'';
	}
	*quoted++ = '\0';
	return (output);
}

char	*ft_add_quotes(char *s)
{
	size_t	nb_words;
	char	*quoted;

	if (s == NULL)
	{
		quoted = (char *) malloc (3 * sizeof(char));
		if (quoted == NULL)
		{
			free(s);
			return (NULL);
		}
		quoted[0] = '\'';
		quoted[1] = '\'';
		quoted[2] = '\0';
		return (quoted);
	}
	nb_words = ft_count_words(s);
	quoted = quote_words(s, nb_words);
	free(s);
	return (quoted);
}
