/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_to_map_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daleliev <daleliev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 18:54:58 by daleliev          #+#    #+#             */
/*   Updated: 2024/06/29 11:26:46 by daleliev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	ft_check_each_str(char *str, t_element *element)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '1' || str[i] == ' ' || str[i] == '0'
			|| str[i] == 'N' || str[i] == 'E' || str[i] == 'W'
			|| str[i] == 'S' || (str[i] == '2' && element->bonus))
			i++;
		else
		{
			element->error++;
			return (element->error);
		}
	}
	return (0);
}

int	ft_check_lst(t_listb *lst, t_element *element)
{
	t_listb		*test;
	int			size;
	int			letters;

	test = lst;
	size = 0;
	letters = 0;
	while (test != NULL)
	{
		if (ft_check_each_str(test->str, element))
			return (0);
		letters += test->nb_letter;
		size++;
		test = test->next;
	}
	if (letters != 1)
	{
		element->error++;
		return (0);
	}
	return (size);
}

void	ft_fill_map(t_element *element, int len)
{
	t_listb	*lst;
	int		i;

	lst = element->lst;
	i = 0;
	while (i < len)
	{
		element->map[i] = lst->str;
		i++;
		lst = lst->next;
	}
}

void	for_last_line(char **map, int i, int j, t_element *el)
{
	while (i > 0 && map[i][j] && map[i][j] == ' ')
		i--;
	if ((int)ft_strlen(map[i]) >= j && map[i][j]
		&& map[i][j] != '1' && map[i][j] != ' ')
		el->error++;
}

void	check_for_conditions(char **map, int j, int i, t_element *element)
{
	int	x;

	x = j;
	while (map[i][j] && (map[i][j] == '0' || ft_isalpha(map[i][j])))
		j++;
	if (map[i][j] != '1')
		element->error++;
	j = x;
	while (j >= 0 && (map[i][j] == '0' || ft_isalpha(map[i][j])))
		j--;
	if (map[i][j] != '1')
		element->error++;
	j = x;
}
