/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy_commands.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daleliev <daleliev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 10:40:09 by daleliev          #+#    #+#             */
/*   Updated: 2024/05/27 12:39:34 by daleliev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"
// check error here (double free in some conditions?)
static void	free_nodes(t_pipex *pipex)
{
	if (pipex->commands && pipex->commands->cmd)
		free(pipex->commands->cmd);
	if (pipex->commands->args)
		free(pipex->commands->args);
	if (pipex->commands->is_hd)
	{
		unlink(pipex->commands->input);
		free(pipex->commands->input);
	}
}

void	destroy_commands(t_pipex *pipex)
{
	if (pipex->commands)
	{
		while (pipex->commands->prev != NULL)
			pipex->commands = pipex->commands->prev;
		while (pipex->commands->next != NULL)
		{
			free_nodes(pipex);
			pipex->commands = pipex->commands->next;
			if (pipex->commands->prev)
				free(pipex->commands->prev);
		}
		free_nodes(pipex);
		free(pipex->commands);
	}
}

void	destroy_three_structs(t_pipex *pipex)
{
	if (pipex->token)
	{
		destroy_token(pipex);
		pipex->token = NULL;
	}
	if (pipex->tokenlist)
	{
		destroy_tokenlist(pipex);
		pipex->tokenlist = NULL;
	}
	if (pipex->commands)
	{
		destroy_commands(pipex);
		pipex->commands = NULL;
	}
}
