/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_stacks.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkubina <gkubina@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 12:47:00 by gkubina           #+#    #+#             */
/*   Updated: 2023/12/14 12:47:47 by gkubina          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_2_stacks(t_stack *st_a, t_stack *st_b)
{
	int	maxsize;
	int	size_a;
	int	size_b;
	int	i;

	i = 0;
	size_a = ft_size_stack(st_a) - 1;
	size_b = ft_size_stack(st_b) - 1;
	maxsize = size_b ;
	if (size_a > size_b)
		maxsize = size_a ;
	while (i <= maxsize)
	{
		i++;
	}
}
/*
void    print_2_stacks(t_stack *st_a, t_stack *st_b)
{
        int     maxsize;
        int     size_a;
        int     size_b;
        int     i;

        i = 0;
        size_a = ft_size_stack(st_a) - 1;
        size_b = ft_size_stack(st_b) - 1;
        maxsize = size_b ;
        if (size_a > size_b)
                maxsize = size_a ;
        while (i <= maxsize)
        {
              if (size_a >= maxsize - i)
                        ft_printf("| %10i |",
                                ft_value_stack_node(st_a, i - maxsize + size_a));
                else
                        ft_printf("|            |");
                if (size_b >= maxsize - i)
                        ft_printf("| %10i |\n",
                                ft_value_stack_node(st_b, i - maxsize + size_b));
                else
                        ft_printf("|            |\n");
                i++;
        }
      ft_printf("|     A      ||     B      |\n");
}
*/
