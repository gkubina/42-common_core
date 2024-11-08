/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_element.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daleliev <daleliev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 13:05:55 by daleliev          #+#    #+#             */
/*   Updated: 2024/06/29 09:58:42 by daleliev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	err(char *str, t_element *element)
{
	if (element->error == 0)
		printf("Error\n");
	printf("%s\n", str);
	element->error++;
}

void	free_lst(t_listb *lst)
{
	t_listb	*tmp;

	while (lst)
	{
		tmp = lst->next;
		free(lst->str);
		free(lst);
		lst = tmp;
	}
}

void	free_and_close_texture(t_element *element)
{
	if (element->no_path)
		free(element->no_path);
	if (element->fd_no > 0)
		close(element->fd_no);
	if (element->so_path)
		free(element->so_path);
	if (element->fd_so > 0)
		close(element->fd_so);
	if (element->ea_path)
		free(element->ea_path);
	if (element->fd_ea > 0)
		close(element->fd_ea);
	if (element->we_path)
		free(element->we_path);
	if (element->fd_we > 0)
		close(element->fd_we);
	if (element->d_path)
		free(element->d_path);
	if (element->fd_d > 0)
		close(element->fd_d);
}

void	ft_free_element(t_element *element)
{
	if (element->lst)
		free_lst(element->lst);
	if (element->ceiling)
		free(element->ceiling);
	if (element->floor)
		free(element->floor);
	free_and_close_texture(element);
	free(element->map);
}
