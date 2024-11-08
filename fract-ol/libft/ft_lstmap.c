/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkubina <gkubina@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 09:46:50 by gkubina           #+#    #+#             */
/*   Updated: 2023/10/30 09:48:26 by gkubina          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*newnode;
	t_list	*startpointer;
	void	*content;

	if (!lst || !f || !del)
		return (NULL);
	startpointer = NULL;
	while (lst)
	{
		content = f(lst->content);
		newnode = ft_lstnew(content);
		if (newnode == NULL)
		{
			del(content);
			ft_lstclear(&startpointer, del);
			return (NULL);
		}
		ft_lstadd_back(&startpointer, newnode);
		lst = lst->next;
	}
	return (startpointer);
}
