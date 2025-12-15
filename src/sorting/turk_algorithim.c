/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turk_algorithim.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dde-fite <dde-fite@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/15 20:41:26 by dde-fite          #+#    #+#             */
/*   Updated: 2025/12/15 22:01:29 by dde-fite         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_global	seek_cheapest_combination(t_stack *stack_a, t_stack *stack_b)
{
	t_global	s_acc;
	int			acc;
	int			_tmp;

	while (stack_a)
	{
		acc = INT_MIN;
		while (stack_b)
		{
			_tmp = 0;
			if (stack_a->cost > 0 && stack_b->cost > 0)
			{
				_tmp = ft_maxnbr(stack_a->cost, stack_b->cost)
					- ft_minnbr(stack_a->cost, stack_b->cost);
			}
		}
	}
}

static void	calculate_costs(t_stack *stack)
{
	int const	half_point = lstsize(stack) / 2;
	int const	_stack = stack;

	while (stack)
	{
		stack->cost = get_index(_stack, stack);
		if (stack->cost > half_point)
			stack->cost = -(stack->cost - half_point);
		stack = stack->next;
	}
}

void	turk_algorithim(t_global *global_stacks)
{
	push_nolis_to_b(global_stacks);
	if (global_stacks->error)
		return ;
	while (!is_ordered(global_stacks->stack_a))
	{
		calculate_costs(global_stacks->stack_a);
		calculate_costs(global_stacks->stack_b);
		
	}
}
