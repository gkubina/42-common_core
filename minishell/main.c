/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkubina <gkubina@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/05 10:38:29 by daleliev          #+#    #+#             */
/*   Updated: 2024/05/24 16:15:51 by gkubina          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

volatile int	g_last_sig;

static char	**ft_cpy_env(char **env)
{
	char	**cpy;
	int		i;

	i = 0;
	while (env[i] != NULL)
		i++;
	cpy = (char **) malloc((i + 1) * sizeof(char *));
	if (cpy == NULL)
		exit(ENOMEM);
	cpy[i] = NULL;
	while (--i > -1)
	{
		cpy[i] = ft_strdup(env[i]);
		if (cpy[i] == NULL)
		{
			while (cpy[++i] != NULL)
				free(cpy[i]);
			free(cpy);
			exit(ENOMEM);
		}
	}
	return (cpy);
}

char	**ft_split_path(t_pipex *pipex)
{
	char	*path;
	int		i;

	i = -1;
	path = NULL;
	while (pipex->env && pipex->env[++i] != NULL)
	{
		if (!ft_strncmp(pipex->env[i], "PATH=", 5))
		{
			path = ft_strdup(pipex->env[i] + 5);
			if (path == NULL)
				error_handler(MALLOC_ERROR, pipex, 1);
		}
	}
	if (!path)
		return (NULL);
	pipex->path = ft_split(path, ':');
	free(path);
	if (pipex->path == NULL)
		error_handler(MALLOC_ERROR, pipex, 1);
	return (pipex->path);
}

void	shell(t_pipex *pipex)
{
	char			*entry;

	while (true)
	{
		setup_signal_handling(READLINE);
		entry = readline("my_prompt :");
		if (entry != NULL)
		{
			if (entry[0] == '\0')
				free(entry);
			else
			{
				add_history(entry);
				ft_manage_entry(entry, pipex);
			}
		}
		else
		{
			write(2, "\n", 1);
			clear_history();
			destroy_all_allocations(pipex);
			exit (pipex->err_no);
		}
	}
}

int	main(int argc, char **argv, char **env)
{
	static t_pipex	pipex;

	(void)argv;
	if (argc != 1)
		error_handler(ARG_ERROR, &pipex, 1);
	pipex.env = ft_cpy_env(env);
	pipex.path = ft_split_path(&pipex);
	shell (&pipex);
	return (0);
}
