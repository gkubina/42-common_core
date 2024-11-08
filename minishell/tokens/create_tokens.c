/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_tokens.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkubina <gkubina@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 09:49:15 by daleliev          #+#    #+#             */
/*   Updated: 2024/05/24 15:49:22 by gkubina          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

static int	is_startstring(char c)
{
	if (c == 34 || c == 39)
		return (4);
	if (c == '<' || c == '>')
		return (3);
	if (c == '|')
		return (2);
	else if (!ft_isspace(c))
		return (1);
	return (0);
}

static int	endstring(char *str, int start)
{
	int	i;

	i = start;
	if (is_startstring(str[start]) == 2)
		return (start);
	while (str[++i])
	{
		if (is_startstring(str[start]) == 3 && str[i] != str[start])
			return (i - 1);
		else if (is_startstring(str[start]) == 4 && str[i] == str[start])
		{
			if (str[i + 1] && (is_startstring(str[i + 1]) == 1
					|| is_startstring(str[i + 1]) == 4))
				return (endstring(str, i + 1));
			else
				return (i);
		}
		else if (is_startstring(str[start]) == 1 && is_startstring(str[i]) == 4)
			i = endstring(str, i);
		else if (is_startstring(str[start]) == 1
			&& (is_startstring(str[i]) != 1))
			return (i - 1);
	}
	return (i - 1);
}

static void	add_token(char *word, t_pipex *pipex)
{
	t_tokenlist	*new;
	t_tokenlist	**tokenlist;

	if (!ft_strncmp("''", word, 2) && !ft_strncmp("\"\"", word, 2)
		&& ft_strlen(word) == 2)
	{
		free(word);
		return ;
	}
	new = (t_tokenlist *) malloc(sizeof(t_tokenlist));
	if (new == NULL)
	{
		free(word);
		error_handler(MALLOC_ERROR, pipex, 1);
	}
	new->word = word;
	if (is_startstring(word[0]) == 2 || is_startstring(word[0]) == 3)
		new->type = SEPARATOR;
	else
		new->type = WORD;
	new->next = NULL;
	tokenlist = &(pipex->tokenlist);
	while (!(tokenlist == NULL) && *tokenlist != NULL)
		tokenlist = &((*tokenlist)->next);
	*tokenlist = new;
}

static char	*substr(char *line, int start, int end)
{
	char	*str;
	int		i;

	i = 0;
	str = (char *) malloc (sizeof(char) * ((end - start) + 2));
	if (str == NULL)
		return (NULL);
	while (start <= end)
	{
		str[i] = line[start];
		start++;
		i++;
	}
	str[i] = '\0';
	return (str);
}

int	create_tokenlist(char *line, t_pipex *pipex)
{
	int				i;
	int				end;
	char			*word;

	i = -1;
	while (line[++i])
	{
		if (is_startstring(line[i]) != 0)
		{
			end = endstring(line, i);
			word = substr(line, i, end);
			if (word == NULL)
			{
				free(line);
				error_handler(MALLOC_ERROR, pipex, 1);
			}
			add_token(word, pipex);
			i = end;
		}
	}
	free(line);
	get_tokens(pipex);
	precise_tokens(pipex);
	remove_quotes(pipex);
	return (0);
}
