/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_execute.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkubina <gkubina@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 13:27:55 by daleliev          #+#    #+#             */
/*   Updated: 2024/05/22 11:54:13 by gkubina          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

static void	close_next_fds(t_pipex *pipex)
{
	t_commands	*cmd;

	cmd = pipex->commands->next;
	while (cmd != NULL)
	{
		if (cmd->fd_input > 2)
			close(cmd->fd_input);
		if (cmd->fd_output > 2)
			close (cmd->fd_output);
		cmd = cmd->next;
	}
}

static void	ft_quit_if_error(t_pipex *pipex)
{
	if (pipex->commands->prev)
		close (pipex->commands->prev->fd[1]);
	if (pipex->commands->next)
	{
		close (pipex->commands->fd[0]);
		close (pipex->commands->fd[1]);
	}
	if (!pipex->commands->prev && !pipex->commands->next)
	{
		if (pipex->commands->fd_input > 2)
			close(pipex->commands->fd_input);
		if (pipex->commands->fd_output > 2)
			close(pipex->commands->fd_output);
	}
	if (pipex->commands->next || pipex->commands->prev)
	{
		clear_history();
		destroy_all_allocations(pipex);
		exit(EXIT_FAILURE);
	}
}

int	ft_handle_error(t_pipex *pipex)
{
	if (pipex->commands->fd_input == -1)
	{
		write(2, pipex->commands->input, ft_strlen(pipex->commands->input));
		write(2, ": No such file or directory\n", 28);
		ft_quit_if_error(pipex);
		pipex->err_no = 1;
		return (0);
	}
	else if (pipex->commands->fd_output == -1)
	{
		write(2, pipex->commands->output, ft_strlen(pipex->commands->output));
		write(2, ": Permission denied\n", 20);
		ft_quit_if_error(pipex);
		pipex->err_no = 1;
		return (0);
	}
	else if (pipex->commands->args[0] == NULL)
	{
		ft_quit_if_error(pipex);
		pipex->err_no = 0;
		return (0);
	}
	return (1);
}

void	wait_children(t_pipex *pipex)
{
	while (pipex->commands->prev != NULL)
	{
		if (pipex->commands->next == NULL)
		{
			waitpid(pipex->commands->pid, &pipex->err_no, 0);
			pipex->err_no = WEXITSTATUS(pipex->err_no);
		}
		else
			waitpid(pipex->commands->pid, NULL, 0);
		pipex->commands = pipex->commands->prev;
	}
	waitpid(pipex->commands->pid, NULL, 0);
}

void	ft_execcmd(t_pipex *pipex)
{
	int	rc;

	rc = 0;
	close_next_fds(pipex);
	if (ft_is_builtins(pipex->commands->args[0]))
	{
		ft_execute_builtins(pipex);
		destroy_all_allocations(pipex);
		clear_history();
		exit(EXIT_SUCCESS);
	}
	else
	{
		if (pipex->commands->cmd && access(pipex->commands->cmd, X_OK) == 0)
			rc = execve(pipex->commands->cmd,
					pipex->commands->args, pipex->env);
		write(2, pipex->commands->args[0], ft_strlen(pipex->commands->args[0]));
		write(2, " : command not found\n", 21);
	}
	destroy_all_allocations(pipex);
	clear_history();
	exit(127 + rc);
}
