/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turk_algorithm.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dde-fite <dde-fite@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/15 20:41:26 by dde-fite          #+#    #+#             */
/*   Updated: 2025/12/17 01:55:31 by dde-fite         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_global	seek_cheapest_combination(t_stack *stack_a, t_stack *stack_b)
{
	t_stack const	*_stack_b = stack_b;
	t_global		s_acc;
	int				acc;
	int				_tmp;

	acc = INT_MAX;
	while (stack_a)
	{
		while (stack_b)
		{
			_tmp = 0;
			if ((stack_a->cost > 0 && stack_b->cost > 0)
				|| (stack_a->cost < 0 && stack_b->cost < 0))
				_tmp = ft_maxnbr(ft_abs(stack_a->cost), ft_abs(stack_b->cost));
			else
				_tmp = ft_abs(stack_a->cost) + ft_abs(stack_b->cost);
			if (_tmp < acc)
			{
				s_acc.stack_a = stack_a;
				s_acc.stack_b = stack_b;
				acc = _tmp;
			}
			stack_b = stack_b->next;
		}
		stack_a = stack_a->next;
		stack_b = (t_stack *)_stack_b;
	}
	return (s_acc);
}

static void	calculate_costs(t_stack *stack)
{
	int const		half_point = lstsize(stack) / 2;
	t_stack const	*_stack = stack;

	while (stack)
	{
		stack->cost = get_index((t_stack *)_stack, stack);
		if (stack->cost > half_point)
			stack->cost = -(stack->cost - half_point);
		stack = stack->next;
	}
}

void	turk_algorithm(t_global *global_stacks)
{
	pa(global_stacks);
	pa(global_stacks);
	while (global_stacks->stack_b)
	{
		calculate_costs(global_stacks->stack_a);
		calculate_costs(global_stacks->stack_b);
		seek_cheapest_combination(global_stacks->stack_a,
			global_stacks->stack_b);
	}
}
