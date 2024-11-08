/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daleliev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/22 14:25:57 by daleliev          #+#    #+#             */
/*   Updated: 2023/10/22 14:45:04 by daleliev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*l;

	l = *lst;
	if (!l)
	{
		new->next = NULL;
		*lst = new;
	}
	else
	{
		while (l->next != NULL)
			l = l->next;
		l->next = new;
	}
}
