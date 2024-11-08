/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   only_spaces.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkubina <gkubina@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 09:49:15 by daleliev          #+#    #+#             */
/*   Updated: 2024/05/24 16:06:49 by gkubina          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	ft_isspace(char c)
{
	if (c == ' ' || c == '\f' || c == '\n' || c == '\r'
		|| c == '\t' || c == '\v')
		return (1);
	return (0);
}

int	only_spaces(char *line)
{
	int	i;

	i = 0;
	while (line && line[i])
	{
		if (ft_isspace(line[i]))
			i++;
		else
			return (0);
	}
	return (-1);
}
