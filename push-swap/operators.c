/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operators.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkubina <gkubina@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 12:47:00 by gkubina           #+#    #+#             */
/*   Updated: 2023/12/14 12:47:38 by gkubina          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_stack *stack)
{
	int	tmp;

	if (!stack || stack->next == stack)
		return ;
	tmp = stack->value;
	stack->value = stack->next->value;
	stack->next->value = tmp;
}

void	push(t_stack **from, t_stack **to)
{
	int	value;

	if (!from)
		return ;
	value = ft_value_top_stack(*from);
	*to = ft_add_top_stack(*to, value);
	*from = ft_remove_top_stack(*from);
}

void	rotate(t_stack **stack)
{
	if (!(*stack))
		return ;
	*stack = (*stack)->next;
}

void	rev_rotate(t_stack **stack)
{
	if (!*stack)
		return ;
	*stack = (*stack)->prec;
}
