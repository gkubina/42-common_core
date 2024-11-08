/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daleliev <daleliev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 11:28:55 by daleliev          #+#    #+#             */
/*   Updated: 2024/06/29 10:19:46 by daleliev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	move_to_next_nb(char *str, int i, t_element *element)
{
	while (ft_isspace_mod(str[i]) && str[i] != ',')
		i++;
	if (str[i] != ',')
	{
		err("The RGB numbers should be separate by ','", element);
		return (0);
	}
	return (i + 1);
}

int	ft_is_cub(char *doc)
{
	int	i;

	i = 0;
	while (doc[i] != '\0')
		i++;
	if (i >= 4 && doc[i - 4] == '.' && doc[i - 3] == 'c'
		&& doc[i - 2] == 'u' && doc[i - 1] == 'b')
		return (1);
	printf("Error\nThe file should end with '.cub'.\n");
	return (0);
}

int	ft_isspace_mod(char c)
{
	if (c == '\f' || c == '\t' || c == '\r' || c == '\v'
		|| c == ' ')
		return (1);
	return (0);
}

int	line_has_smthg(char *line)
{
	int	i;

	i = 0;
	while (line[i] != '\n' && line[i] != '\0')
	{
		if (line[i] > 32 && line[i] < 127)
			return (1);
		i++;
	}
	return (0);
}

char	*dup_with_a_size(char *str, int size)
{
	char	*path;
	int		i;

	path = malloc(sizeof(char) * (size + 1));
	i = -1;
	while (++i < size && (str[i] > 32 && str[i] < 127))
		path[i] = str[i];
	path[i] = '\0';
	return (path);
}
