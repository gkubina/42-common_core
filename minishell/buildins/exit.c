/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkubina <gkubina@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 11:49:18 by daleliev          #+#    #+#             */
/*   Updated: 2024/05/22 10:28:52 by gkubina          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	ft_isnum(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0' && (str[i] < 33))
		i++;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i] != '\0')
	{
		if (str[i] < '0' || str[i] > '9')
			break ;
		i++;
	}
	while (str[i] != '\0' && (str[i] < 33 && str[i] > 0))
		i++;
	if (str[i] == '\0')
		return (0);
	return (1);
}

int	ft_atoull(char *str)
{
	int					i;
	unsigned long long	total;
	int					sign;

	i = 0;
	total = 0;
	sign = 1;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		total = total * 10 + (str[i] - '0');
		if ((total - 1 == 9223372036854775807 && sign == 1)
			|| total > 9223372036854775807)
			return (300);
		i++;
	}
	return ((total * sign) % 256);
}

int	ft_check_exit_args(t_pipex *pipex)
{
	int	i;

	i = 0;
	while (pipex->commands->args[i] != NULL)
		i++;
	if (i == 1)
		return (pipex->err_no);
	else if (ft_isnum(pipex->commands->args[1])
		|| ft_atoull(pipex->commands->args[1]) == 300)
	{
		write(2, pipex->commands->args[1], ft_strlen(pipex->commands->args[1]));
		write(2, ": minishell: exit needs numeric argument", 41);
		return (2);
	}
	else if (i == 2)
		return (ft_atoull(pipex->commands->args[1]));
	write(2, "too many arguments\n", 20);
	return (-1);
}

void	ft_exit(t_pipex *pipex)
{
	int	nbexit;

	if (pipex->commands->next == NULL && pipex->commands->prev == NULL)
		write(2, "exit\n", 6);
	nbexit = ft_check_exit_args(pipex);
	if (nbexit >= 0)
		pipex->err_no = nbexit;
	if (nbexit == -1)
	{
		if ((pipex->commands->next == NULL && pipex->commands->prev == NULL)
			&& pipex->err_no == 0)
			pipex->err_no = 1;
		else if (pipex->commands->prev || pipex->commands->next)
			pipex->err_no = 1;
		return ;
	}
	destroy_all_allocations(pipex);
	exit(pipex->err_no);
}
