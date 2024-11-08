/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daleliev <daleliev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 11:48:53 by daleliev          #+#    #+#             */
/*   Updated: 2024/05/21 18:31:18 by daleliev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	ft_env(t_pipex *pipex)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (pipex->commands->args[j] != NULL)
		j++;
	if (j != 1)
	{
		write(2, "env does not take arguments\n", 28);
		return ;
	}
	while (j == 1 && pipex->env && pipex->env[i] != NULL)
	{
		write(1, pipex->env[i], ft_strlen(pipex->env[i]));
		write(1, "\n", 1);
		i++;
	}
}
