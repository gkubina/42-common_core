/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_vars_2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daleliev <daleliev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 09:49:15 by daleliev          #+#    #+#             */
/*   Updated: 2024/05/20 10:44:00 by daleliev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

static char	*search_env(char *var, t_pipex *pipex)
{
	int		i;
	char	*value;

	i = -1;
	value = NULL;
	while (pipex->env && pipex->env[++i])
	{
		if (ft_strncmp(pipex->env[i], var, ft_strlen(var)) == 0
			&& pipex->env[i][ft_strlen(var)] == '=')
		{
			value = ft_strdup(pipex->env[i] + ft_strlen(var) + 1);
			if (value == NULL)
				error_handler(MALLOC_ERROR, pipex, 1);
		}
	}
	return (value);
}
// if var only $ value gets $

char	*get_value_from_env(char *var, t_pipex *pipex)
{
	char	*value;

	value = NULL;
	check_exit_code(pipex);
	if (var[0] == '?')
	{
		value = ft_itoa(pipex->err_no);
		if (value == NULL)
			error_handler(MALLOC_ERROR, pipex, 1);
	}
	else if (var[0] == '\0')
	{
		value = (char *) malloc (2 * sizeof(char));
		if (value == NULL)
			error_handler(MALLOC_ERROR, pipex, 1);
		value[0] = '$';
		value[1] = '\0';
	}
	else if (var[0] == '_' || ft_isalpha(var[0]))
		value = search_env(var, pipex);
	value = ft_add_quotes(value);
	if (value == NULL)
		error_handler(MALLOC_ERROR, pipex, 1);
	return (value);
}
