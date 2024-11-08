/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkubina <gkubina@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 11:48:31 by daleliev          #+#    #+#             */
/*   Updated: 2024/05/24 15:53:23 by gkubina          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

static void	ft_add_to_env(char *str, t_pipex *pipex)
{
	char	**temp;
	int		size;
	int		i;

	size = 0;
	while (pipex->env[size] != NULL)
		size++;
	temp = ft_calloc(sizeof(char *), (size + 2));
	if (temp == NULL)
		error_handler(MALLOC_ERROR, pipex, 1);
	i = -1;
	while (++i < size)
		temp[i] = pipex->env[i];
	temp[i] = ft_strdup(str);
	if (temp[i] == NULL)
		error_handler(MALLOC_ERROR, pipex, 1);
	temp[i + 1] = NULL;
	free(pipex->env);
	pipex->env = temp;
}

static void	ft_compare(t_pipex *pipex, int i)
{
	int	j;
	int	c;

	c = 0;
	while (pipex->commands->args[i][c] != '='
		&& pipex->commands->args[i][c] != '\0')
		c++;
	j = -1;
	while (pipex->env[++j] != NULL)
	{
		if (!ft_strncmp(pipex->env[j], pipex->commands->args[i], c))
		{
			free(pipex->env[j]);
			pipex->env[j] = ft_strdup(pipex->commands->args[i]);
			if (pipex->env[j] == NULL)
				error_handler(MALLOC_ERROR, pipex, 1);
			return ;
		}
	}
	if (pipex->env[j] == NULL)
		ft_add_to_env(pipex->commands->args[i], pipex);
}

static int	ft_check_export_args(char *arg)
{
	int	i;
	int	len;

	len = ft_strlen(arg);
	i = 0;
	if (((arg[i] >= 'a' && arg[i] <= 'z') || (arg[i] >= 'A' && arg[i] <= 'Z')
			|| arg[i] == '_') && i < len)
		i++;
	else
		return (0);
	while (((arg[i] >= 'a' && arg[i] <= 'z')
			|| (arg[i] >= 'A' && arg[i] <= 'Z')
			|| arg[i] == '_' || (arg[i] >= '0' && arg[i] <= '9')) && i < len)
		i++;
	if (i == len)
		return (-1);
	if (i < len && arg[i] != '=')
		return (0);
	return (1);
}

static void	check_other_options(t_pipex *pipex, int i)
{
	if (ft_check_export_args(pipex->commands->args[i]) == -1)
		pipex->err_no = 0;
	else
	{
		ft_compare(pipex, i);
		if (ft_strncmp(pipex->commands->args[i], "PATH=", 5) == 0)
		{
			destroy_path(pipex);
			pipex->path = ft_split_path(pipex);
		}
	}
}

void	ft_export(t_pipex *pipex)
{
	int	i;

	i = 0;
	while (pipex->commands->args[i] != NULL)
		i++;
	if (i == 1)
		write (2, "Argument needed (see man) \n", 27);
	else
	{
		i = 0;
		while (pipex->commands->args[++i] != NULL)
		{
			if (!ft_check_export_args(pipex->commands->args[i]))
			{
				write(2, pipex->commands->args[i],
					ft_strlen(pipex->commands->args[i]));
				write(2, "': is not a valid export identifier\n", 37);
				pipex->err_no = 1;
			}
			else
				check_other_options(pipex, i);
		}
	}
}
