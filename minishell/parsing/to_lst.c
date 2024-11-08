/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   to_lst.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkubina <gkubina@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 14:37:53 by daleliev          #+#    #+#             */
/*   Updated: 2024/05/22 12:23:09 by gkubina          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

static char	*ft_while_path(char *argv, char **path, t_pipex *pipex, int j)
{
	char	*test1;
	char	*test2;

	while (path && path[++j] != NULL)
	{
		test1 = ft_strjoin(path[j], "/");
		if (test1 == NULL)
			error_handler(MALLOC_ERROR, pipex, 1);
		test2 = ft_strjoin(test1, argv);
		if (test2 == NULL)
		{
			free(test1);
			error_handler(MALLOC_ERROR, pipex, 1);
		}
		if (access(test2, X_OK) == 0)
		{
			free(test1);
			return (test2);
		}
		free(test1);
		free(test2);
	}
	return (NULL);
}

static char	*ft_f_d_a(char *argv, char **path, t_pipex *p, int j)
{
	char	*test2;

	if (access(argv, X_OK) == 0)
	{
		test2 = ft_strdup(argv);
		if (test2 == NULL)
			error_handler(MALLOC_ERROR, p, 1);
		p->commands->args[0] = argv;
		return (test2);
	}
	else
	{
		p->commands->args[0] = argv;
		return (ft_while_path(argv, path, p, j));
	}
}

static int	ft_c_a(t_token *tokens, int i)
{
	int	count;

	count = 0;
	while (++i < tokens->size && tokens->type[i] != 5)
	{
		if (tokens->type[i] == 3 || tokens->type[i] == 4)
			count++;
	}
	return (count);
}

//ajout de cmd et des args
static void	ft_manage_node(t_pipex *pipex, t_token *tokens, int i, char **path)
{
	int	j;

	j = 0;
	if (tokens->type[i] == 3)
		pipex->commands->cmd = ft_f_d_a(tokens->word[i], path, pipex, -1);
	else
	{
		while (pipex->commands->args[j] != NULL)
			j++;
		pipex->commands->args[j] = tokens->word[i];
	}
}

void	ft_manage_tokens(t_token *tokens, t_pipex *pipex, int i)
{
	t_commands	*temp;
	int			j;

	i = -1;
	j = 0;
	pipex->commands = ft_calloc(1, sizeof(t_commands));
	pipex->commands->args = ft_calloc((ft_c_a(tokens, i) + 1), sizeof(char *));
	while (++i < tokens->size)
	{
		pipex->commands->position = j;
		if (tokens->type[i] == 5)
		{
			temp = pipex->commands;
			pipex->commands->next = ft_calloc(1, sizeof(t_commands));
			pipex->commands = pipex->commands->next;
			pipex->commands->next = NULL;
			pipex->commands->prev = temp;
			pipex->commands->args = ft_calloc((ft_c_a(tokens, i) + 1), 8UL);
			j++;
		}
		else if (tokens->type[i] == 3 || tokens->type[i] == 4)
			ft_manage_node(pipex, tokens, i, pipex->path);
		else if (tokens->type[i] >= 9 && tokens->type[i] <= 12)
			ft_open_files(pipex->commands, tokens, i, pipex);
	}
}
