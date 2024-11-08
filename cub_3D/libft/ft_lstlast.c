/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkubina <gkubina@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 15:51:13 by gkubina           #+#    #+#             */
/*   Updated: 2023/10/24 16:03:10 by gkubina          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	int		listsize;
	t_list	*pointer;

	if (!lst)
		return (NULL);
	pointer = lst;
	listsize = ft_lstsize(lst);
	while (listsize > 1)
	{
		listsize--;
		pointer = pointer->next;
	}
	return (pointer);
}
