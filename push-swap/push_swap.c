/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkubina <gkubina@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 12:02:43 by gkubina           #+#    #+#             */
/*   Updated: 2023/12/14 12:48:10 by gkubina          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	error(t_stack *stack)
{
	clean(&stack);
	ft_putstr_fd("Error\n", 2);
	return (-1);
}

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;
	char	**args;
	int		err;

	err = 0;
	a = NULL;
	b = NULL;
	args = NULL;
	if (argc < 2 || argv[1][0] == '\0')
		return (0);
	else if (argc == 2)
	{
		args = ft_split(argv[1], ' ');
		if (fill_stack(&a, args) == -1)
			err = error(a);
	}
	else if (fill_stack(&a, (argv + 1)) == -1)
		err = error(a);
	if (err != -1)
		solve(&a, &b);
	if (args != NULL)
		ft_free(args);
	return (0);
}
