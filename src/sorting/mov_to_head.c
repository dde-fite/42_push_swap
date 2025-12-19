/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mov_to_head.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dde-fite <dde-fite@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/19 20:30:52 by dde-fite          #+#    #+#             */
/*   Updated: 2025/12/19 21:39:23 by dde-fite         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	mov_to_head(t_stack **stack, t_stack *node, int stack_size)
{
	int			node_idx;

	node_idx = get_index(*stack, node);
	while (node_idx != 0)
	{
		if (node_idx < stack_size / 2)
			ra(stack);
		else
			rra(stack);
		node_idx = get_index(*stack, node);
	}
}

void	mov_to_head_double(t_global *stacks, t_stack *node)
{
	while (node->cost || node->target->cost)
	{
		if (node->cost > 0 && node->target->cost > 0)
			rr(stacks);
		else if (node->cost < 0 && node->target->cost < 0)
			rrr(stacks);
		else if (node->cost > 0)
			ra(&stacks->stack_a);
		else if (node->cost < 0)
			rra(&stacks->stack_a);
		else if (node->target->cost > 0)
			rb(&stacks->stack_b);
		else if (node->target->cost < 0)
			rrb(&stacks->stack_b);
		calculate_costs(stacks->stack_a, stacks->len_a);
		calculate_costs(stacks->stack_b, stacks->len_b);
	}
}
