/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup_map_helpers.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkubina <gkubina@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 12:02:43 by gkubina           #+#    #+#             */
/*   Updated: 2024/06/22 12:00:16 by gkubina          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	x_size_map(t_element *element)
{
	int		x;
	t_listb	*list;

	x = 0;
	list = element->lst;
	while (list)
	{
		if (x < list->len)
			x = list->len;
		list = list->next;
	}
	return (x);
}

int	ft_find_alpha(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (ft_isalpha(str[i]))
			return (i);
		i++;
	}
	return (0);
}

int	y_size_map(t_element *element)
{
	int		y;
	t_listb	*list;

	y = 0;
	list = element->lst;
	while (list)
	{
		y++;
		list = list->next;
	}
	return (y);
}
