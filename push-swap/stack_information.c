/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_information.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkubina <gkubina@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 12:47:00 by gkubina           #+#    #+#             */
/*   Updated: 2023/12/14 12:49:21 by gkubina          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	stack_sorted(t_stack **stack)
{
	size_t		i;
	size_t		size;
	t_stack		**check;

	check = stack;
	size = ft_size_stack(*check);
	i = 0;
	while (i < size - 1)
	{
		if ((*check)->value > (*check)->next->value)
			return (0);
		i++;
		check = &((*check)->next);
	}
	return (1);
}

int	stack_position(t_stack **stack, int num)
{
	int			pos;
	size_t		i;
	size_t		size;
	t_stack		*check;

	size = ft_size_stack(*stack);
	check = *stack;
	i = 0;
	pos = 0;
	while (i < size)
	{
		if (check->value == num)
			return (pos);
		check = check->next;
		pos++;
		i++;
	}
	return (-1);
}

int	max_num_in_stack(t_stack **stack)
{
	int		max;
	size_t	i;
	size_t	size;
	t_stack	*check;

	size = ft_size_stack(*stack);
	i = 0;
	check = *stack;
	max = check->value;
	while (i < size)
	{
		if (check->value > max)
			max = check->value;
		check = check->next;
		i++;
	}
	return (max);
}

int	min_num_in_stack(t_stack **stack)
{
	int		min;
	size_t	i;
	size_t	size;
	t_stack	*check;

	size = ft_size_stack(*stack);
	i = 0;
	check = *stack;
	min = check->value;
	while (i < size)
	{
		if (check->value < min)
			min = check->value;
		check = check->next;
		i++;
	}
	return (min);
}
