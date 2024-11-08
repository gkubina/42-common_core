/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkubina <gkubina@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 11:48:43 by daleliev          #+#    #+#             */
/*   Updated: 2024/05/22 12:32:45 by gkubina          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	ft_delete_suite(t_pipex *pipex, char **env, int i)
{
	env[i] = NULL;
	free (pipex->env);
	pipex->env = env;
}

void	ft_delete(t_pipex *pipex, int j)
{
	char	**env;
	int		size;
	int		i;
	int		k;

	size = 1;
	while (pipex->env[size] != NULL)
		size++;
	env = malloc(sizeof (char *) * (size));
	if (env == NULL)
		error_handler(MALLOC_ERROR, pipex, 1);
	i = -1;
	k = 0;
	while (++i < size)
	{
		if (i == j)
			free(pipex->env[i]);
		else
		{
			env[k] = pipex->env[i];
			k++;
		}
	}
	ft_delete_suite(pipex, env, k);
}

static void	recompile_path(t_pipex *pipex)
{
	destroy_path(pipex);
	pipex->path = ft_split_path(pipex);
}

void	ft_unset(t_pipex *pipex)
{
	int	i;
	int	j;
	int	size;

	i = 0;
	while (pipex->commands->args[++i] != NULL)
	{
		size = ft_strlen(pipex->commands->args[i]);
		j = 0;
		while (pipex->env[j] != NULL)
		{
			if (ft_strncmp(pipex->env[j], pipex->commands->args[i], size) == 0
				&& pipex->env[j][size] == '=')
			{
				ft_delete(pipex, j);
				if (ft_strncmp(pipex->commands->args[i], "PATH", 4) == 0)
					recompile_path(pipex);
				break ;
			}
			j++;
		}
	}
}
