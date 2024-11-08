/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_separators.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daleliev <daleliev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 10:08:57 by daleliev          #+#    #+#             */
/*   Updated: 2024/05/21 19:35:20 by daleliev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	ft_move_to_the_next_similar_c(char *str, int i, char c)
{
	while (str[i] != c && str[i] != '\0')
		i++;
	if (str[i] == '\0')
		return (-1);
	return (i);
}

int	ft_check_consecutives_separator(int i, char *str)
{
	char	c;

	c = str[i];
	if (str[i + 1] == c)
		i++;
	i++;
	while ((str[i] < 33 || str[i] > 126) && str[i] != '\0')
		i++;
	if (str[i] == 60 || str[i] == 62 || str[i] == '|' || str[i] == '\0')
		return (-1);
	i--;
	return (i);
}

int	ft_check_for_pipe_character(int i, char *str)
{
	i++;
	while ((str[i] < 33 || str[i] > 126) && str[i] != '\0')
		i++;
	if (str[i] == '|' || str[i] == '\0')
		return (-1);
	if (str[i] == '>' || str[i] == '<')
	{
		i = ft_check_consecutives_separator(i, str);
		if (i < 0)
			return (-1);
	}
	i--;
	return (i);
}

int	ft_check_conditions(int i, char *str)
{
	if (str[i] == 34 || str[i] == 39)
	{
		i = ft_move_to_the_next_similar_c(str, i + 1, str[i]);
		if (i < 0)
			return (-1);
	}
	else if (str[i] == '>' || str[i] == '<')
	{
		i = ft_check_consecutives_separator(i, str);
		if (i < 0)
			return (-1);
	}
	else if (str[i] == '|')
	{
		i = ft_check_for_pipe_character(i, str);
		if (i < 0)
			return (-1);
	}
	return (i);
}

int	ft_check_separators(char *str)
{
	int	i;

	i = 0;
	while ((str[i] < 33 || str[i] > 126) && str[i] != '\0')
		i++;
	if (str[i] == '|')
		return (-1);
	i--;
	while (str[++i] != '\0')
	{
		i = ft_check_conditions(i, str);
		if (i < 0)
			return (-1);
	}
	return (i);
}
