/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cost_analyzers.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkubina <gkubina@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 12:47:00 by gkubina           #+#    #+#             */
/*   Updated: 2023/12/14 12:47:09 by gkubina          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	calc_cost(t_stack **a, t_stack **b, int num)
{
	int	cost;

	cost = 0;
	if (ft_strncmp(best_rotate_dir(a, num),
			best_rotate_dir(b, merge_num_to_top(b, num)), 2) == 0)
	{
		if (cost_merge_position_to_top(b, num) < best_rotate_cost(a, num))
			cost = best_rotate_cost(a, num);
		else
			cost = cost_merge_position_to_top(b, num);
	}
	else
	{
		cost += best_rotate_cost(a, num);
		cost += cost_merge_position_to_top(b, num);
	}
	return (cost);
}

int	cheapest_num(t_stack **a, t_stack **b)
{
	t_stack	*check;
	int		cost;
	int		num;
	size_t	i;
	size_t	size;

	size = ft_size_stack(*a);
	i = 0;
	check = *a;
	cost = calc_cost(a, b, check->value);
	num = check->value;
	while (i < size)
	{
		if (calc_cost(a, b, check->value) < cost)
		{
			cost = calc_cost(a, b, check->value);
			num = check->value;
		}
		check = check->next;
		i++;
	}
	return (num);
}

char	*best_rotate_dir(t_stack **stack, int num)
{
	int	pos;
	int	size;

	size = ft_size_stack (*stack);
	pos = stack_position(stack, num);
	if (pos < size - pos)
		return ("r");
	return ("rr");
}

int	best_rotate_cost(t_stack **stack, int num)
{
	int	pos;
	int	size;

	size = ft_size_stack (*stack);
	pos = stack_position(stack, num);
	if (pos < size - pos)
		return (pos);
	return (size - pos);
}

int	cost_merge_position_to_top(t_stack **stack, int num)
{
	t_stack	*check;
	size_t	i;
	size_t	size;

	size = ft_size_stack(*stack);
	i = 0;
	check = *stack;
	if (num > max_num_in_stack(stack))
		return (best_rotate_cost(stack, max_num_in_stack(stack)));
	if (num < min_num_in_stack(stack))
		return (best_rotate_cost(stack, max_num_in_stack(stack)));
	else
	{
		while (i < size)
		{
			if (check->value < num && check->prec->value > num)
				return (best_rotate_cost(stack, check->value));
			check = check->next;
			i++;
		}
	}
	return (best_rotate_cost(stack, check->value));
}
