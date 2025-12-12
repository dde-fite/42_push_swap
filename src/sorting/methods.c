/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   methods.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dde-fite <dde-fite@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/10 20:55:53 by dde-fite          #+#    #+#             */
/*   Updated: 2025/12/12 21:29:53 by dde-fite         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	is_ordered(t_stack *lst)
{
	if (!lst)
		return (0);
	while (lst && lst->next)
	{
		if (lst->number > lst->next->number)
			return (0);
		lst = lst->next;
	}
	return (1);
}

static void	sort_three(t_stack **stack)
{
	while (!is_ordered(*stack))
	{
		if ((*stack)->number > (*stack)->next->number)
			sa(stack);
		else
			rra(stack);
	}
}

static void	move_to_head(t_stack **stack, t_stack *node)
{
	int const	half_point = lstsize(*stack) / 2;
	int			node_idx;

	node_idx = get_index(*stack, node);
	while (node_idx != 0)
	{
		if (node_idx < half_point)
			ra(stack);
		else
			rra(stack);
		node_idx = get_index(*stack, node);
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

static void	turk_algorithim(t_global *global_stacks)
{
	push_nolis_to_b(global_stacks);
	if (global_stacks->error)
		return ;
}

void	method_switch(t_global *global_stacks)
{
	if (is_ordered(global_stacks->stack_a))
		return ;
	if (global_stacks->len == 3)
		sort_three(&global_stacks->stack_a);
	if (global_stacks->len == 5)
		sort_five(global_stacks);
	else
		turk_algorithim(global_stacks);
}
