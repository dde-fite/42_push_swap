/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   methods.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dde-fite <dde-fite@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/10 20:55:53 by dde-fite          #+#    #+#             */
/*   Updated: 2025/12/19 17:15:49 by dde-fite         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	sort_two(t_stack **stack)
{
	if (!is_ordered(*stack))
		sa(stack);
}

void	sort_three(t_stack **stack)
{
	while (!is_ordered(*stack))
	{
		if ((*stack)->number > (*stack)->next->number)
			sa(stack);
		else
			rra(stack);
	}
}

static void	sort_five(t_global *stacks)
{
	move_to_head(&stacks->stack_a, get_min_node(stacks->stack_a),
		stacks->len_a);
	pb(stacks);
	move_to_head(&stacks->stack_a, get_min_node(stacks->stack_a),
		stacks->len_a);
	pb(stacks);
	sort_three(&stacks->stack_a);
	pa(stacks);
	pa(stacks);
}

void	method_switch(t_global *stacks)
{
	if (is_ordered(stacks->stack_a))
		return ;
	if (stacks->len_a == 2)
		sort_two(&stacks->stack_a);
	else if (stacks->len_a == 3)
		sort_three(&stacks->stack_a);
	else if (stacks->len_a == 5)
		sort_five(stacks);
	else
		turk_algorithm(stacks);
}
