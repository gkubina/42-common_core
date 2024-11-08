/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_tokens.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkubina <gkubina@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 09:49:15 by daleliev          #+#    #+#             */
/*   Updated: 2024/04/23 11:48:44 by gkubina          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

static int	length_tokenlist(t_tokenlist **list)
{
	t_tokenlist	*temp;
	int			length;

	length = 1;
	temp = *list;
	while (temp && temp->next != NULL)
	{
		length++;
		temp = temp->next;
	}
	return (length);
}

int	get_tokens(t_pipex *pipex)
{
	t_tokenlist	*temp;
	t_tokenlist	**list;
	t_token		*new;
	int			i;

	i = -1;
	list = &(pipex->tokenlist);
	new = (t_token *) malloc (sizeof(t_token));
	if (new == NULL)
		error_handler(MALLOC_ERROR, pipex, 1);
	new->size = length_tokenlist(list);
	new->type = (int *) malloc (new->size * sizeof(int));
	new->word = (char **) malloc (new->size * sizeof(char *));
	if (new->type == NULL || new->word == NULL)
		error_handler(MALLOC_ERROR, pipex, 1);
	while (++i < new->size)
	{
		new->word[i] = (*list)->word;
		new->type[i] = (*list)->type;
		temp = *list;
		(*list) = (*list)->next;
		free(temp);
	}
	pipex->token = new;
	return (0);
}

static int	precise_redirections(t_token *tokens)
{
	int	i;

	i = -1;
	while (++i < tokens->size)
	{
		if (tokens->type[i] == REDIR_FILE && tokens->word[i - 1][0] == '>')
		{
			tokens->type[i] = OUT_REDIR_OV;
			if (tokens->word[i - 1][1] == '>')
				tokens->type[i] = OUT_REDIR_AP;
		}
		else if (tokens->type[i] == REDIR_FILE && tokens->word[i - 1][0] == '<')
		{
			tokens->type[i] = IN_REDIR;
			if (tokens->word[i - 1][1] == '<')
				tokens->type[i] = IN_REDIR_HD;
		}
	}
	return (0);
}

static int	fine_precise_tokens(t_token *tokens)
{
	int	i;
	int	command;

	command = 1;
	i = -1;
	while (++i < tokens->size)
	{
		if (tokens->type[i] == WORD && command)
		{
			tokens->type[i] = COMMAND;
			command = 0;
		}
		else if (tokens->type[i] == WORD && !command)
			tokens->type[i] = ARGUMENT;
		else if (tokens->type[i] == PIPE)
			command = 1;
	}
	return (precise_redirections(tokens));
}

int	precise_tokens(t_pipex *pipex)
{
	int		i;
	t_token	*tokens;

	i = -1;
	tokens = pipex->token;
	while (++i < tokens->size)
	{
		if (tokens->type[i] == SEPARATOR && tokens->word[i][0] == '|')
			tokens->type[i] = PIPE;
		else if (tokens->type[i] == SEPARATOR && tokens->word[i][0] != '|')
			tokens->type[i] = REDIRECTION;
		else if (i > 0 && tokens->type[i] == WORD
			&& tokens->type[i - 1] == REDIRECTION)
			tokens->type[i] = REDIR_FILE;
	}
	return (fine_precise_tokens(tokens));
}
