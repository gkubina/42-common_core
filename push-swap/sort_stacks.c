/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stacks.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkubina <gkubina@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 12:47:00 by gkubina           #+#    #+#             */
/*   Updated: 2023/12/14 12:49:13 by gkubina          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_3_stack(t_stack **aa, t_stack **bb)
{
	int	a;
	int	b;
	int	c;

	a = (*aa)->value;
	b = (*aa)->next->value;
	c = (*aa)->next->next->value;
	if (a < b && a < c && b > c)
	{
		manipulate ("rra", aa, bb);
		manipulate ("sa", aa, bb);
	}
	if (a > b && a > c && b > c)
	{
		manipulate ("ra", aa, bb);
		manipulate ("sa", aa, bb);
	}
	if (a > b && a < c && b < c)
		manipulate ("sa", aa, bb);
	if (a < b && a > c && b > c)
		manipulate ("rra", aa, bb);
	if (a > b && a > c && b < c)
		manipulate ("ra", aa, bb);
}

void	sort_small_stack(t_stack **a, t_stack **b)
{
	if (ft_size_stack(*a) == 3)
		sort_3_stack(a, b);
	else if (ft_size_stack(*a) == 2)
		manipulate ("sa", a, b);
}

void	sort_big_stack(t_stack **a, t_stack **b)
{
	while (ft_size_stack(*a) > 3 && ft_size_stack(*b) < 2)
		manipulate ("pb", a, b);
	while (!stack_sorted(a) && !(ft_size_stack(*a) < 4))
	{
		push_to_b(a, b);
	}
	if (!stack_sorted(a))
	{
		sort_small_stack(a, b);
	}
	while (*b)
	{
		push_to_a(a, b);
	}
	while (!stack_sorted(a))
	{
		rotate_a(a, b);
	}
}

void	solve(t_stack **a, t_stack **b)
{
	if (stack_sorted(a) == 1)
		return ;
	else if (ft_size_stack(*a) < 4)
		sort_small_stack(a, b);
	else
	{
		sort_big_stack(a, b);
	}
	clean(a);
}
