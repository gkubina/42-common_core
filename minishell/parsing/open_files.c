/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_files.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daleliev <daleliev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/20 11:24:35 by daleliev          #+#    #+#             */
/*   Updated: 2024/05/27 13:29:48 by daleliev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

static void	ft_back_to_shell(t_pipex *pipex)
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
	destroy_three_structs(pipex);
	shell(pipex);
}

// 19/05 petite modif

static void
	ft_write_heredoc(char *str, char *word, t_commands *cmd, t_pipex *pipex)
{
	char	*limiter;

	limiter = ft_strjoin(word, "\n");
	while (1)
	{
		write(1, "heredoc> ", 9);
		str = get_next_line(STDOUT_FILENO);
		if (!str || (str && ft_strncmp(limiter, str, ft_strlen(str)) == 0))
		{
			if (!str && g_last_sig != SIGINT)
				printf("here-doc delimited by EOF (wanted '%s')\n", word);
			break ;
		}
		write(cmd->fd_input, str, ft_strlen(str));
		free(str);
	}
	if (str)
		free(str);
	if (limiter)
		free (limiter);
	close (cmd->fd_input);
	if (g_last_sig != SIGINT)
		cmd->fd_input = open(cmd->input, O_RDONLY, 0644);
	else
		ft_back_to_shell(pipex);
}

// 19/05 petite modif (nom du fichier heredoc)

static void	ft_heredoc(t_commands *cmd, t_token *tokens, int i, t_pipex *pipex)
{
	char	*str;
	char	*file;
	int		temp;

	str = ft_itoa(cmd->position);
	if (str == NULL)
		error_handler(MALLOC_ERROR, pipex, 1);
	file = ft_strjoin(".heredoc", str);
	if (file == NULL)
		error_handler(MALLOC_ERROR, pipex, 1);
	temp = open(file, O_CREAT | O_WRONLY | O_TRUNC, 0644);
	if (cmd->fd_input >= 0)
	{
		if (cmd->input)
			cmd->input = NULL;
		cmd->fd_input = temp;
		cmd->input = file;
		cmd->is_hd = 1;
	}
	free(str);
	str = NULL;
	setup_signal_handling(HEREDOC);
	ft_write_heredoc(str, tokens->word[i], cmd, pipex);
	setup_signal_handling(EXECUTION);
}

static void	ft_manage_files(t_commands *cmd, t_token *tokens, int i)
{
	if (tokens->type[i] == 11 && cmd->fd_input >= 0 && cmd->fd_output >= 0)
	{
		if (cmd->fd_output > 2)
			close(cmd->fd_output);
		cmd->fd_output = open(tokens->word[i], O_WRONLY | O_CREAT | O_APPEND,
				0644);
		cmd->output = tokens->word[i];
	}
	else if (tokens->type[i] == 12 && cmd->fd_input >= 0
		&& cmd->fd_output >= 0)
	{
		if (cmd->fd_output > 2)
			close(cmd->fd_output);
		cmd->fd_output = open(tokens->word[i], O_WRONLY
				| O_CREAT | O_TRUNC, 0644);
		cmd->output = tokens->word[i];
	}
}

void	ft_open_files(t_commands *cmd, t_token *tokens, int i, t_pipex *pipex)
{
	if (tokens->type[i] == 5 || tokens->type[i] == 6)
		i++;
	if (tokens->type[i] == 10 && cmd->fd_input >= 0 && cmd->fd_output >= 0)
	{
		if (cmd->is_hd)
			free_hd(cmd);
		if (cmd->fd_input > 2)
			close(cmd->fd_input);
		ft_heredoc(cmd, tokens, i, pipex);
	}
	else if (tokens->type[i] == 9 && cmd->fd_input >= 0 && cmd->fd_output >= 0)
	{
		if (cmd->is_hd)
			free_hd(cmd);
		if (cmd->fd_input > 2)
			close(cmd->fd_input);
		cmd->fd_input = open(tokens->word[i], O_RDONLY);
		cmd->input = tokens->word[i];
	}
	else if (tokens->type[i] >= 11)
		ft_manage_files(cmd, tokens, i);
}
