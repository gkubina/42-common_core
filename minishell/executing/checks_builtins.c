/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks_builtins.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daleliev <daleliev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 16:25:05 by daleliev          #+#    #+#             */
/*   Updated: 2024/05/21 19:28:18 by daleliev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	ft_execute_builtins(t_pipex *pipex)
{
	if (!ft_strncmp(pipex->commands->args[0], "cd", 2)
		&& ft_strlen(pipex->commands->args[0]) == 2)
		ft_cd(pipex);
	else if (!ft_strncmp(pipex->commands->args[0], "echo", 4)
		&& ft_strlen(pipex->commands->args[0]) == 4)
		ft_echo(pipex);
	else if (!ft_strncmp(pipex->commands->args[0], "pwd", 3)
		&& ft_strlen(pipex->commands->args[0]) == 3)
		ft_pwd(pipex);
	else if (!ft_strncmp(pipex->commands->args[0], "export", 6)
		&& ft_strlen(pipex->commands->args[0]) == 6)
		ft_export(pipex);
	else if (!ft_strncmp(pipex->commands->args[0], "unset", 5)
		&& ft_strlen(pipex->commands->args[0]) == 5)
		ft_unset(pipex);
	else if (!ft_strncmp(pipex->commands->args[0], "env", 3)
		&& ft_strlen(pipex->commands->args[0]) == 3)
		ft_env(pipex);
	else if (!ft_strncmp(pipex->commands->args[0], "exit", 4)
		&& ft_strlen(pipex->commands->args[0]) == 4)
		ft_exit(pipex);
	return ;
}

int	ft_is_builtins(char *str)
{
	if (str && !ft_strncmp(str, "cd", 2) && ft_strlen(str) == 2)
		return (1);
	else if (str && !ft_strncmp(str, "echo", 4) && ft_strlen(str) == 4)
		return (2);
	else if (str && !ft_strncmp(str, "pwd", 3) && ft_strlen(str) == 3)
		return (2);
	else if (str && !ft_strncmp(str, "export", 6) && ft_strlen(str) == 6)
		return (1);
	else if (str && !ft_strncmp(str, "unset", 5) && ft_strlen(str) == 5)
		return (1);
	else if (str && !ft_strncmp(str, "env", 3) && ft_strlen(str) == 3)
		return (1);
	else if (str && !ft_strncmp(str, "exit", 4) && ft_strlen(str) == 4)
		return (1);
	return (0);
}

// int	have_to_dup (char *str)
// {
// 	if (str && !ft_strncmp(str, "cd", 2) && ft_strlen(str) == 2)
// 		return 1;
// 	else if (str && !ft_strncmp(str, "echo", 4) && ft_strlen(str) == 4)
// 		return 1;
// 	else if (str && !ft_strncmp(str, "pwd", 3) && ft_strlen(str) == 3)
// 		return 1;
// 	else if (str && !ft_strncmp(str, "export", 6) && ft_strlen(str) == 6)
// 		return 1;
// 	else if (str && !ft_strncmp(str, "unset", 5) && ft_strlen(str) == 5)
// 		return 1;
// 	else if (str && !ft_strncmp(str, "env", 3) && ft_strlen(str) == 3)
// 		return 1;
// 	else if (str && !ft_strncmp(str, "exit", 4) && ft_strlen(str) == 4)
// 		return 1;
// 	return 0;
// }