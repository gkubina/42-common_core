/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daleliev <daleliev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 11:44:49 by daleliev          #+#    #+#             */
/*   Updated: 2024/05/18 10:55:25 by daleliev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

static void	ft_write_code_error(t_pipex *pipex)
{
	char	*result;
	int		i;
	int		size;

	i = pipex->err_no;
	size = 1;
	while (i > 9)
	{
		i /= 10;
		size++;
	}
	result = ft_itoa(pipex->err_no);
	write (1, result, size);
	if (pipex->commands->args[i + 1])
		write (1, " ", 1);
	free (result);
}

void	ft_echo(t_pipex *pipex)
{
	int	i;
	int	n;

	i = 1;
	n = 0;
	while (pipex->commands->args[i] != NULL)
	{
		if (i == 1 && ft_strncmp("-n", pipex->commands->args[i], 2) == 0
			&& ft_strlen(pipex->commands->args[i]) == 2)
			n++;
		else if (!ft_strncmp(pipex->commands->args[i], "$?", 2)
			&& ft_strlen(pipex->commands->args[i]) == 2)
			ft_write_code_error(pipex);
		else
		{
			write(1, pipex->commands->args[i],
				ft_strlen(pipex->commands->args[i]));
			if (pipex->commands->args[i + 1])
				write (1, " ", 1);
		}
		i++;
	}
	if (n == 0)
		write(1, "\n", 1);
}
