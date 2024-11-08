/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maptolst.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daleliev <daleliev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 13:31:23 by daleliev          #+#    #+#             */
/*   Updated: 2024/07/01 09:16:25 by daleliev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	ft_check_str(t_listb *lst, char *str)
{
	int	i;

	i = -1;
	while (str[++i] != '\0')
	{
		if (str[i] == 'E' || str[i] == 'W' || str[i] == 'N'
			|| str[i] == 'S')
			lst->nb_letter++;
		if (str[i] == 'E')
			lst->letter = 'E';
		if (str[i] == 'W')
			lst->letter = 'W';
		if (str[i] == 'S')
			lst->letter = 'S';
		if (str[i] == 'N')
			lst->letter = 'N';
		if (str[i] == '2')
			lst->nb_door++;
	}
	i--;
	while (str[i] && str[i] != '1')
		i--;
	lst->len = i + 1;
}

static char	*ft_dup_good_size(char *line, int len)
{
	char	*str;
	int		i;

	str = malloc(sizeof(char) * (len + 1));
	i = 0;
	while (i < len)
	{
		str[i] = line[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

void	ft_map_to_lst(char *line, t_element *element)
{
	t_listb	*bis;
	int		i;

	i = 0;
	while (line[i] && line[i] != '\n')
	{
		if (line[i] == ' ' || line[i] == '1' || line[i] == '0' || line[i] == 'N'
			|| line[i] == 'S' || line[i] == 'E' || line[i] == 'W'
			|| (line[i] == '2' && element->bonus))
			i++;
		else
		{
			element->error++;
			i++;
		}
	}
	bis = element->lst;
	while (bis->next != NULL)
		bis = bis->next;
	bis->next = ft_calloc(sizeof(t_listb), 1);
	bis = bis->next;
	bis->str = ft_dup_good_size(line, i);
	ft_check_str(bis, bis->str);
}

char	*ft_start_lst(char *line, t_element *element, int fd)
{
	int		i;

	i = 0;
	while (line && line[i] && line[i] != '\n')
	{
		if (line[i] == ' ' || line[i] == '1' || line[i] == '0' || line[i] == 'N'
			|| line[i] == 'S' || line[i] == 'E' || line[i] == 'W'
			|| (line[i] == '2' && element->bonus))
			i++;
		else
		{
			element->error++;
			i++;
		}
	}
	element->lst->str = ft_dup_good_size(line, i);
	ft_check_str(element->lst, element->lst->str);
	free(line);
	return (get_next_line(fd));
}
