/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daleliev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/22 14:54:41 by daleliev          #+#    #+#             */
/*   Updated: 2023/10/22 15:06:56 by daleliev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*l;
	t_list	*next;

	if (!lst || !del)
		return ;
	l = *lst;
	while (l)
	{
		next = l-> next;
		del(l->content);
		free(l);
		l = next;
	}
	*lst = NULL;
}
