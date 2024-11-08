/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkdoorsposition.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daleliev <daleliev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 12:59:04 by daleliev          #+#    #+#             */
/*   Updated: 2024/06/29 10:00:09 by daleliev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	check_if_its_allow(t_element *el, int i, int j, char **map)
{
	if (map[i][j + 1] == '1' && map[i][j - 1] == '1'
		&& (map[i + 1][j] == '0' && map[i - 1][j] == '0'))
		return ;
	else if (map[i + 1][j] == '1' && map[i - 1][j] == '1'
		&& (map[i][j + 1] == '0' && map[i][j - 1] == '0'))
		return ;
	else
	{
		err("One door isn't between 2 walls and/or isn't between 2 '0'", el);
		return ;
	}
}

static void	ft_print_how_to_put_doors(void)
{
	printf("Error\nA door should be between 2 walls.\n");
	printf("Either one wall to its right and one to its left,\n");
	printf("Or one to the bottom and one to the top.\n");
	printf("In addition : the two directions who are not '1' have to be");
	printf(" '0'.\n");
}

void	check_doors_position(t_element *el)
{
	int	i;
	int	j;

	i = -1;
	while (el->map[++i])
	{
		j = -1;
		while (el->map[i][++j])
		{
			if (el->map[i][j] == '2')
				check_if_its_allow(el, i, j, el->map);
		}
	}
	if (el->error)
	{
		ft_print_how_to_put_doors();
		ft_free_element(el);
		exit(1);
	}
	else
		return ;
}
