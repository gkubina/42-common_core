/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_stack_helpers.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkubina <gkubina@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 12:47:00 by gkubina           #+#    #+#             */
/*   Updated: 2023/12/14 12:47:21 by gkubina          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	clean(t_stack **stack)
{
	while (*stack)
		*stack = ft_remove_top_stack(*stack);
}

static int	is_number(char *num)
{
	int	i;

	i = 0;
	if (num[0] == '-' && num[1])
		i++;
	while (num[i])
	{
		if (!ft_isdigit(num[i]) || i > 11)
			return (0);
		i++;
	}
	return (1);
}

static int	repetition(char **argv, int num, int pos)
{
	int	i;

	i = 0;
	while (argv[i] && i < pos)
	{
		if (num == ft_atoi(argv[i]))
			return (1);
		i++;
	}
	return (0);
}

void	ft_free(char **args)
{
	size_t	i;

	i = 0;
	while (args[i])
	{
		free(args[i]);
		i++;
	}
	free (args);
}

int	fill_stack(t_stack **stack, char **argv)
{
	long		num;
	int			i;

	i = 0;
	if (argv[0] == NULL)
		return (-1);
	while (argv[i])
		i++;
	while (--i >= 0)
	{
		if (!is_number(argv[i]))
			return (-1);
		num = ft_atoi_long(argv[i]);
		if (num < -2147483648 || num > 2147483647)
			return (-1);
		if (repetition(argv, (int)num, i) == 1)
			return (-1);
		*stack = ft_add_top_stack(*stack, (int)num);
	}
	return (0);
}
