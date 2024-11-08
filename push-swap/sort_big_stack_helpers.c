/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_big_stack_helpers.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkubina <gkubina@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 12:47:00 by gkubina           #+#    #+#             */
/*   Updated: 2023/12/14 12:48:54 by gkubina          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_to_b(t_stack **a, t_stack **b)
{
	int		ch_num;
	int		mer_num;
	char	*dir_a;
	char	*dir_b;

	ch_num = cheapest_num(a, b);
	mer_num = merge_num_to_top(b, ch_num);
	dir_a = best_rotate_dir(a, ch_num);
	dir_b = best_rotate_dir(b, mer_num);
	if (dir_a == dir_b)
	{
		while ((*a)->value != ch_num && (*b)->value != mer_num)
		{
			if (ft_strncmp(dir_a, "rr", 2) == 0)
				manipulate ("rrr", a, b);
			else if (ft_strncmp(dir_a, "r", 1) == 0)
				manipulate ("rr", a, b);
		}
	}
	good_num_up(a, b, ch_num, mer_num);
	manipulate ("pb", a, b);
}

void	push_to_a(t_stack **a, t_stack **b)
{
	int	mer_num;

	mer_num = merge_num_to_top_ord(a, (*b)->value);
	print_2_stacks(*a, *b);
	good_num_up(a, b, mer_num, (*b)->value);
	manipulate("pa", a, b);
}

void	rotate_a(t_stack **a, t_stack **b)
{
	char	*dir_a;

	dir_a = best_rotate_dir(a, min_num_in_stack(a));
	while (!((*a)->value == min_num_in_stack(a)))
	{
		if (ft_strncmp(dir_a, "rr", 2) == 0)
			manipulate ("rra", a, b);
		else if (ft_strncmp(dir_a, "r", 1) == 0)
			manipulate ("ra", a, b);
	}
}

void	good_num_up(t_stack **a, t_stack **b, int num_a, int num_b)
{
	char	*rot_a;
	char	*rot_b;

	rot_a = best_rotate_dir(a, num_a);
	rot_b = best_rotate_dir(b, num_b);
	while ((*a)->value != num_a)
	{
		if (ft_strncmp(rot_a, "rr", 2) == 0)
			manipulate ("rra", a, b);
		else if (ft_strncmp(rot_a, "r", 1) == 0)
			manipulate ("ra", a, b);
	}
	while ((*b)->value != num_b)
	{
		if (ft_strncmp(rot_b, "rr", 2) == 0)
			manipulate ("rrb", a, b);
		else if (ft_strncmp(rot_b, "r", 1) == 0)
			manipulate ("rb", a, b);
	}
}
