/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkubina <gkubina@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 12:39:26 by gkubina           #+#    #+#             */
/*   Updated: 2023/12/14 12:48:17 by gkubina          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "./libft/libft.h"

typedef struct s_stack
{
	int				value;
	size_t			pos;
	struct s_stack	*prec;
	struct s_stack	*next;
}			t_stack;

//rotation_list
t_stack		*ft_add_top_stack(t_stack *stack, int value);
t_stack		*ft_remove_top_stack(t_stack *stack);
int			ft_value_top_stack(t_stack *stack);
int			ft_value_stack_node(t_stack *stack, size_t no);
size_t		ft_size_stack(t_stack *stack);

//fill_stack_helpers
void		clean(t_stack **stack);
int			fill_stack(t_stack **stack, char **argv);
void		ft_free(char **args);

//print_stacks
void		print_2_stacks(t_stack *st_a, t_stack *st_b);

//operators
void		swap(t_stack *stack);
void		push(t_stack **from, t_stack **to);
void		rotate(t_stack **stack);
void		rev_rotate(t_stack **stack);

//manipulations
void		manipulate(char *com, t_stack **a, t_stack **b);
void		double_manipulate(char *com, t_stack **a, t_stack **b);

//sort_stacks
void		solve(t_stack **a, t_stack **b);
void		sort_3_stack(t_stack **aa, t_stack **bb);
void		sort_small_stack(t_stack **a, t_stack **b);
void		sort_big_stack(t_stack **a, t_stack **b);

//cost_analyzers
int			calc_cost(t_stack **a, t_stack **b, int num);
int			cheapest_num(t_stack **a, t_stack **b);
char		*best_rotate_dir(t_stack **stack, int num);
int			best_rotate_cost(t_stack **stack, int num);
int			cost_merge_position_to_top(t_stack **stack, int num);

//number_movers
int			merge_num_to_top(t_stack **stack, int num);
int			merge_num_to_top_ord(t_stack **stack, int num);
void		good_num_up(t_stack **a, t_stack **b, int num_a, int num_b);

//sort_big_stack_helpers
void		push_to_b(t_stack **a, t_stack **b);
void		push_to_a(t_stack **a, t_stack **b);
void		rotate_a(t_stack **a, t_stack **b);

//stack_information
int			max_num_in_stack(t_stack **stack);
int			min_num_in_stack(t_stack **stack);
int			stack_position(t_stack **a, int num);
int			stack_sorted(t_stack **stack);

//utils
long		ft_atoi_long(const char *nptr);

#endif
