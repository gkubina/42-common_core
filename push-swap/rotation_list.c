/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotation_list.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkubina <gkubina@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 12:47:00 by gkubina           #+#    #+#             */
/*   Updated: 2023/12/14 12:48:39 by gkubina          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*ft_add_top_stack(t_stack *stack, int value)
{
	t_stack	*new;

	new = malloc (sizeof(t_stack));
	if (new == NULL)
		return (NULL);
	new->value = value;
	if (stack == NULL)
	{
		new->next = new;
		new->prec = new;
		new->pos = 1;
	}
	else
	{
		new->prec = stack->prec;
		new->next = stack;
		stack->prec->next = new;
		stack->prec = new;
		new->pos = 1;
		stack->pos = 0;
	}
	stack = new;
	return (stack);
}

t_stack	*ft_remove_top_stack(t_stack *stack)
{
	t_stack	*old;

	old = stack;
	if (!stack)
		return (NULL);
	if (stack == stack->next)
	{
		free(old);
		return (NULL);
	}
	stack->prec->next = stack->next;
	stack->next->prec = stack->prec;
	stack = stack->next;
	stack->pos = 1;
	free(old);
	return (stack);
}

int	ft_value_top_stack(t_stack *stack)
{
	return (stack->value);
}

int	ft_value_stack_node(t_stack *stack, size_t no)
{
	size_t		i;
	t_stack		*cp;

	if (!stack)
		return (0);
	i = 0;
	cp = stack;
	while (i < no)
	{
		cp = cp->next;
		i++;
	}
	return (cp->value);
}

size_t	ft_size_stack(t_stack *stack)
{
	size_t	size;
	t_stack	*cp;

	size = 0;
	if (!stack)
		return (size);
	cp = stack;
	size++;
	cp = cp->next;
	while (cp != stack)
	{
		size++;
		cp = cp->next;
	}
	return (size);
}
