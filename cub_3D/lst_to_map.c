/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_to_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daleliev <daleliev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 10:38:12 by daleliev          #+#    #+#             */
/*   Updated: 2024/06/29 10:41:42 by daleliev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	check_first_and_final(char **map, int i, int len, t_element *el)
{
	int	j;
	int	k;

	j = 0;
	k = i;
	while (map[i] && (map[i][j] != '\0'))
	{
		if (map[i][j] != '1' && map[i][j] != ' ')
			el->error++;
		if (map[i][j] == ' ' && i == 0)
		{
			while ((int)ft_strlen(map[i]) >= j && i < len && map[i][j] == ' ')
				i++;
			if ((int)ft_strlen(map[i]) >= j && map[i][j] && i < len
				&& map[i][j] != '1' && map[i][j] != ' ')
				el->error++;
			i = k;
		}
		else if (map[i][j] == ' ' && i == len - 1)
			for_last_line(map, i, j, el);
		j++;
	}
}

static void	check_lines_interlines(char **map, int i, int j, t_element *element)
{
	int	k;
	int	len;

	k = i;
	i = 0;
	while (map[i])
		i++;
	len = i;
	i = k;
	if (map[i][j] == '0' || ft_isalpha(map[i][j]))
	{
		while (i < len && j < (int)ft_strlen(map[i]) && (map[i][j] == '0'
			|| ft_isalpha(map[i][j]) || (map[i][j] == '2' && element->bonus)))
			i++;
		if (map[i][j] != '1')
			element->error++;
		i = k;
		while (i >= 0 && j < (int)ft_strlen(map[i]) && (map[i][j] == '0'
			|| ft_isalpha(map[i][j]) || (map[i][j] == '2' && element->bonus)))
			i--;
		if (map[i][j] != '1')
			element->error++;
		i = k;
	}
}

static void	check_inter_lines(char **map, int k, t_element *element)
{
	int	j;
	int	i;

	j = 0;
	i = k;
	while (map[i][j] == ' ')
		j++;
	if (map[i][j] != '1')
		element->error++;
	while (map[i][j] != '\0')
	{
		check_lines_interlines(map, i, j, element);
		j++;
	}
	while (j >= 0 && map[i][j] == ' ')
		j--;
	if (map[i][j] == '0' || map[i][j] == 'N' || map[i][j] == 'W'
		|| map[i][j] == 'E' || map[i][j] == 'S'
		|| (map[i][j] == '2' && element->bonus))
		element->error++;
}

static void	ft_check_if_map_is_possible(t_element *element, int len)
{
	int	i;

	i = 0;
	while (element->map[i] != NULL)
	{
		if (i == 0 || i == len - 1)
			check_first_and_final(element->map, i, len, element);
		else
			check_inter_lines(element->map, i, element);
		i++;
	}
}

int	ft_lst_to_map(t_element *element)
{
	int	len;

	len = ft_check_lst(element->lst, element);
	if (len == 0)
	{
		printf_error();
		return (element->error);
	}
	element->map = ft_calloc(len + 1, sizeof(char *));
	ft_fill_map(element, len);
	ft_check_if_map_is_possible(element, len);
	if (element->error)
		printf_error();
	return (element->error);
}
