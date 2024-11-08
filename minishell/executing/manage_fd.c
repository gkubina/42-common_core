/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_fd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daleliev <daleliev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 12:33:25 by daleliev          #+#    #+#             */
/*   Updated: 2024/05/21 19:31:37 by daleliev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	ft_manage_fd_onlychild(t_pipex *pipex)
{
	if (pipex->commands->fd_input > 2)
	{
		dup2(pipex->commands->fd_input, STDIN_FILENO);
		close(pipex->commands->fd_input);
	}
	if (pipex->commands->fd_output > 2)
	{
		dup2(pipex->commands->fd_output, STDOUT_FILENO);
		close(pipex->commands->fd_output);
	}
}

void	ft_manage_fd_in(t_pipex *pipex)
{
	if (pipex->commands->fd_input > 2)
	{
		dup2(pipex->commands->fd_input, STDIN_FILENO);
		close(pipex->commands->fd_input);
		if (pipex->commands->prev != NULL)
			close(pipex->commands->prev->fd[0]);
	}
	else
	{
		if (pipex->commands->prev != NULL)
		{
			dup2(pipex->commands->prev->fd[0], STDIN_FILENO);
			close(pipex->commands->prev->fd[0]);
		}
	}
	if (pipex->commands->next != NULL)
		close(pipex->commands->fd[0]);
}

void	ft_manage_fd_out(t_pipex *pipex)
{
	if (pipex->commands->fd_output > 2)
	{
		dup2(pipex->commands->fd_output, STDOUT_FILENO);
		close (pipex->commands->fd_output);
		if (pipex->commands->next != NULL)
			close (pipex->commands->fd[1]);
	}
	else
	{
		if (pipex->commands->next != NULL)
		{
			dup2(pipex->commands->fd[1], STDOUT_FILENO);
			close (pipex->commands->fd[1]);
		}
	}
}

void	ft_manage_fd_only_child_no_fork(t_pipex *pipex)
{
	if (pipex->commands->fd_input > 2)
		close(pipex->commands->fd_input);
	if (pipex->commands->fd_output > 2)
		close(pipex->commands->fd_output);
}
