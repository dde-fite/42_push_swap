/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   methods.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dde-fite <dde-fite@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/10 20:55:53 by dde-fite          #+#    #+#             */
/*   Updated: 2025/12/17 20:48:03 by dde-fite         ###   ########.fr       */
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

static void	sort_five(t_global *global_stacks)
{
	move_to_head(&global_stacks->stack_a, get_min_node(global_stacks->stack_a));
	pb(global_stacks);
	move_to_head(&global_stacks->stack_a, get_min_node(global_stacks->stack_a));
	pb(global_stacks);
	sort_three(&global_stacks->stack_a);
	pa(global_stacks);
	pa(global_stacks);
}

void	method_switch(t_global *global_stacks)
{
	if (is_ordered(global_stacks->stack_a))
		return ;
	if (global_stacks->len == 2)
		sort_two(&global_stacks->stack_a);
	else if (global_stacks->len == 3)
		sort_three(&global_stacks->stack_a);
	else if (global_stacks->len == 5)
		sort_five(global_stacks);
	else
		turk_algorithm(global_stacks);
}
