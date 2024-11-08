/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy_structs.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkubina <gkubina@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 09:49:15 by daleliev          #+#    #+#             */
/*   Updated: 2024/05/06 14:28:00 by gkubina          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	destroy_token(t_pipex *pipex)
{
	int	i;

	i = -1;
	if (pipex && pipex->token)
	{
		while (pipex->token->word && ++i < pipex->token->size)
		{
			if (pipex->token->word[i])
				free(pipex->token->word[i]);
		}
		if (pipex->token->word)
			free(pipex->token->word);
		if (pipex->token->type)
			free(pipex->token->type);
		free(pipex->token);
		pipex->token = NULL;
	}
	return (0);
}

int	destroy_tokenlist(t_pipex *pipex)
{
	t_tokenlist	*temp;

	temp = NULL;
	if (pipex && pipex->tokenlist)
	{
		while (pipex->tokenlist)
		{
			temp = pipex->tokenlist;
			if (pipex->tokenlist->word)
				free(pipex->tokenlist->word);
			pipex->tokenlist = temp->next;
			free(temp);
		}
	}
	pipex->tokenlist = NULL;
	return (0);
}

int	destroy_env(t_pipex *pipex)
{
	int	i;

	i = -1;
	while (pipex && pipex->env && pipex->env[++i])
		free(pipex->env[i]);
	if (pipex->env)
		free (pipex->env);
	pipex->env = NULL;
	return (0);
}

int	destroy_path(t_pipex *pipex)
{
	int	i;

	i = -1;
	while (pipex && pipex->path && pipex->path[++i])
		free(pipex->path[i]);
	if (pipex->path)
		free (pipex->path);
	pipex->path = NULL;
	return (0);
}
/*
int	destroy_path(t_pipex *pipex)
{
	t_tokenlist	*temp;

	temp = NULL;
	if (pipex && pipex->tokenlist)
	{
		while (pipex->tokenlist)
		{
			temp = pipex->tokenlist;
			if (pipex->tokenlist->word)
				free(pipex->tokenlist->word);
			pipex->tokenlist = temp->next;
			free(temp);
		}
	}
	pipex->tokenlist = NULL;
	return (0);
}
*/
