/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkubina <gkubina@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 15:39:35 by daleliev          #+#    #+#             */
/*   Updated: 2024/05/22 10:17:58 by gkubina          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	ft_execute_onlychild(t_pipex *pipex)
{
	if (ft_handle_error(pipex) != 1)
		return ;
	if (ft_is_builtins(pipex->commands->args[0]) == 1)
	{
		ft_execute_builtins(pipex);
		ft_manage_fd_only_child_no_fork(pipex);
	}
	else
	{
		pipex->commands->pid = fork();
		if (pipex->commands->pid == -1)
			error_handler(FORK_ERROR, pipex, EAGAIN);
		if (pipex->commands->pid == 0)
		{
			ft_manage_fd_onlychild(pipex);
			ft_execcmd(pipex);
		}
		else
		{
			ft_manage_fd_only_child_no_fork(pipex);
			waitpid(pipex->commands->pid, &pipex->err_no, 0);
			pipex->err_no = WEXITSTATUS(pipex->err_no);
		}
	}
}

void	ft_execute_firstchild(t_pipex *pipex)
{
	if (pipe(pipex->commands->fd) == -1)
		error_handler(PIPE_ERROR, pipex, EPIPE);
	pipex->commands->pid = fork();
	if (pipex->commands->pid == -1)
		error_handler(FORK_ERROR, pipex, EAGAIN);
	if (pipex->commands->pid == 0)
	{
		ft_handle_error(pipex);
		ft_manage_fd_out(pipex);
		ft_manage_fd_in(pipex);
		ft_execcmd(pipex);
	}
	else
	{
		close(pipex->commands->fd[1]);
		if (pipex->commands->fd_input > 2)
			close(pipex->commands->fd_input);
		if (pipex->commands->fd_output > 2)
			close(pipex->commands->fd_output);
	}
}

void	ft_execute_inter_childs(t_pipex *pipex)
{
	if (pipe(pipex->commands->fd) == -1)
		error_handler(PIPE_ERROR, pipex, EAGAIN);
	pipex->commands->pid = fork();
	if (pipex->commands->pid == -1)
		error_handler(FORK_ERROR, pipex, EAGAIN);
	if (pipex->commands->pid == 0)
	{
		ft_handle_error(pipex);
		ft_manage_fd_out(pipex);
		ft_manage_fd_in(pipex);
		ft_execcmd(pipex);
	}
	else
	{
		close(pipex->commands->prev->fd[0]);
		close(pipex->commands->fd[1]);
		if (pipex->commands->fd_input > 2)
			close(pipex->commands->fd_input);
		if (pipex->commands->fd_output > 2)
			close(pipex->commands->fd_output);
	}
}

void	ft_execute_lastchild(t_pipex *pipex)
{
	pipex->commands->pid = fork();
	if (pipex->commands->pid == -1)
		error_handler(FORK_ERROR, pipex, EAGAIN);
	if (pipex->commands->pid == 0)
	{
		ft_handle_error(pipex);
		ft_manage_fd_out(pipex);
		ft_manage_fd_in(pipex);
		ft_execcmd(pipex);
	}
	else
	{
		close(pipex->commands->prev->fd[0]);
		if (pipex->commands->fd_input > 2)
			close(pipex->commands->fd_input);
		if (pipex->commands->fd_output > 2)
			close(pipex->commands->fd_output);
	}
}

void	ft_execute(t_pipex *pipex)
{
	if (pipex->commands->next == NULL)
		ft_execute_onlychild(pipex);
	else
	{
		ft_execute_firstchild(pipex);
		pipex->commands = pipex->commands->next;
		while (pipex->commands != NULL && pipex->commands->next != NULL)
		{
			ft_execute_inter_childs(pipex);
			pipex->commands = pipex->commands->next;
		}
		ft_execute_lastchild(pipex);
		wait_children(pipex);
	}
	destroy_three_structs(pipex);
}
