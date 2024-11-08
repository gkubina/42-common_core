/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daleliev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/22 21:09:42 by daleliev          #+#    #+#             */
/*   Updated: 2023/10/22 21:09:44 by daleliev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new;
	t_list	*new_elem;
	t_list	*lst_copy;

	if (!lst || !f)
		return (NULL);
	new = NULL;
	lst_copy = lst;
	while (lst_copy)
	{
		new_elem = ft_lstnew(f(lst_copy->content));
		if (!new_elem)
		{
			ft_lstclear(&new, del);
			return (NULL);
		}
		ft_lstadd_back(&new, new_elem);
		lst_copy = lst_copy->next;
	}
	return (new);
}
/*
void *(*f)(void *s)
{
	return (s);
}
void (*del)(void *l)
{
	return;
}

int main ()
{
	
}*/
