/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manipulations.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkubina <gkubina@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 12:47:00 by gkubina           #+#    #+#             */
/*   Updated: 2023/12/14 12:47:32 by gkubina          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	manipulate(char *com, t_stack **a, t_stack **b)
{
	ft_printf("%s\n", com);
	if (ft_strncmp(com, "sa", 2) == 0)
		swap(*a);
	else if (ft_strncmp(com, "sb", 2) == 0)
		swap(*b);
	else if (ft_strncmp(com, "rra", 3) == 0)
		rev_rotate(a);
	else if (ft_strncmp(com, "rrb", 3) == 0)
		rev_rotate(b);
	else if (ft_strncmp(com, "rrr", 3) == 0)
		double_manipulate("rrr", a, b);
	else if (ft_strncmp(com, "ss", 2) == 0)
		double_manipulate("ss", a, b);
	else if (ft_strncmp(com, "pa", 2) == 0)
		push(b, a);
	else if (ft_strncmp(com, "pb", 2) == 0)
		push(a, b);
	else if (ft_strncmp(com, "ra", 2) == 0)
		rotate(a);
	else if (ft_strncmp(com, "rb", 2) == 0)
		rotate(b);
	else if (ft_strncmp(com, "rr", 2) == 0)
		double_manipulate("rr", a, b);
}

void	double_manipulate(char *com, t_stack **a, t_stack **b)
{
	if (ft_strncmp(com, "ss", 2) == 0)
	{
		swap(*a);
		swap(*b);
	}
	else if (ft_strncmp(com, "rrr", 3) == 0)
	{
		rev_rotate(a);
		rev_rotate(b);
	}
	else if (ft_strncmp(com, "rr", 2) == 0)
	{
		rotate(a);
		rotate(b);
	}
}
