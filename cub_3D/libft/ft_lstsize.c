/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkubina <gkubina@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 15:35:57 by gkubina           #+#    #+#             */
/*   Updated: 2023/10/24 15:48:56 by gkubina          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	int		size;
	t_list	*pointer;

	if (!lst)
		return (0);
	pointer = lst;
	size = 1;
	while (pointer->next != NULL)
	{
		size++;
		pointer = pointer->next;
	}
	return (size);
}
