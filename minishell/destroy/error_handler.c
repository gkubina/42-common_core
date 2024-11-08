/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkubina <gkubina@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 12:02:43 by gkubina           #+#    #+#             */
/*   Updated: 2024/05/24 16:01:21 by gkubina          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	destroy_all_allocations(t_pipex *pipex)
{
	destroy_env(pipex);
	destroy_path(pipex);
	destroy_token(pipex);
	destroy_tokenlist(pipex);
	destroy_commands(pipex);
	close(0);
	close(1);
	close(2);
}

static void	close_fds(t_pipex *pipex)
{
	while (pipex->commands->prev != NULL)
	{
		if (pipex->commands->fd_input > 2)
			close(pipex->commands->fd_input);
		if (pipex->commands->fd_output > 2)
			close (pipex->commands->fd_output);
		pipex->commands = pipex->commands->prev;
	}
	if (pipex->commands->fd_input > 2)
		close(pipex->commands->fd_input);
	if (pipex->commands->fd_output > 2)
		close (pipex->commands->fd_output);
}

int	error_handler(int error, t_pipex *pipex, int close_prog)
{
	if (error == MALLOC_ERROR)
		perror("Malloc Error");
	else if (error == FORK_ERROR)
		perror("Fork Error");
	else if (error == PIPE_ERROR)
		perror("Pipe Error");
	else if (error == ARG_ERROR)
		perror("Minishell does not need any argument");
	else if (error == SIGNAL_ERROR)
		perror("Signal setup error");
	if ((error == FORK_ERROR || error == MALLOC_ERROR || error == PIPE_ERROR))
		close_fds(pipex);
	destroy_all_allocations(pipex);
	clear_history();
	if (close_prog == 1)
		exit(errno);
	return (-1);
}
