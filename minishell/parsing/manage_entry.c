/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_entry.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkubina <gkubina@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 09:49:15 by daleliev          #+#    #+#             */
/*   Updated: 2024/05/24 16:16:03 by gkubina          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	ft_check_if_not_close(char *str, int i, char c)
{
	while (str[i] != '\0')
	{
		if (str[i] == c)
			return (i);
		i++;
	}
	return (0);
}

int	ft_check_quote(char *str)
{
	int	i;
	int	nbquote;

	i = -1;
	nbquote = 0;
	while (str[++i] != '\0')
	{
		if (str[i] == 34)
		{
			i = ft_check_if_not_close(str, ++i, 34);
			nbquote++;
			if (i == 0)
				return (-1);
		}
		else if (str[i] == 39)
		{
			i = ft_check_if_not_close(str, ++i, 39);
			nbquote++;
			if (i == 0)
				return (-1);
		}
	}
	return (i - nbquote * 2);
}

int	ft_manage_entry(char *entry, t_pipex *pipex)
{
	char			*line;

	line = replace_vars(entry, pipex);
	if (ft_check_quote(line) < 0 || ft_check_separators(line) < 0)
	{
		write (1, "Syntax error !\n", 16);
		free (line);
		return (0);
	}
	if (only_spaces (line) < 0)
	{
		free (line);
		return (0);
	}
	create_tokenlist(line, pipex);
	ft_manage_tokens(pipex->token, pipex, -1);
	while (pipex->commands->prev != NULL)
		pipex->commands = pipex->commands->prev;
	check_exit_code(pipex);
	setup_signal_handling(EXECUTION);
	ft_execute(pipex);
	check_exit_code(pipex);
	return (0);
}
