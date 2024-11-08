/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_big_stack_helpers2.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkubina <gkubina@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 12:47:00 by gkubina           #+#    #+#             */
/*   Updated: 2023/12/14 12:49:01 by gkubina          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	merge_num_to_top_ord(t_stack **stack, int num)
{
	t_stack		*check;
	size_t		i;
	size_t		size;

	size = ft_size_stack(*stack);
	check = *stack;
	i = 0;
	if (num > max_num_in_stack(stack))
	{
		return (min_num_in_stack(stack));
	}
	if (num < min_num_in_stack(stack))
		return (min_num_in_stack(stack));
	else
	{
		while (i < size)
		{
			if (check->value > num && check->prec->value < num)
				return (check->value);
			check = check->next;
			i++;
		}
	}
	return (check->value);
}

int	merge_num_to_top(t_stack **stack, int num)
{
	t_stack		*check;
	size_t		i;
	size_t		size;

	size = ft_size_stack(*stack);
	check = *stack;
	i = 0;
	if (num > max_num_in_stack(stack))
	{
		return (max_num_in_stack(stack));
	}
	if (num < min_num_in_stack(stack))
		return (max_num_in_stack(stack));
	else
	{
		while (i < size)
		{
			if (check->value < num && check->prec->value > num)
				return (check->value);
			check = check->next;
			i++;
		}
	}
	return (check->value);
}
