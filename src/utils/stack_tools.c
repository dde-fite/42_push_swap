/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_tools.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dde-fite <dde-fite@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/12 15:32:46 by dde-fite          #+#    #+#             */
/*   Updated: 2025/12/19 17:12:29 by dde-fite         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*get_by_index(t_stack *stack, int idx)
{
	if (idx == 0)
		return (stack);
	while (stack && idx > 0)
	{
		stack = stack->next;
		idx--;
	}
	return (stack);
}

int	get_index(t_stack *stack, t_stack *node)
{
	int	idx;

	idx = 0;
	while (stack && stack != node)
	{
		stack = stack->next;
		idx++;
	}
	return (idx);
}

t_stack	*get_min_node(t_stack *stack)
{
	t_stack	*acc_stack;

	acc_stack = stack;
	while (stack)
	{
		if (stack->number < acc_stack->number)
			acc_stack = stack;
		stack = stack->next;
	}
	return ((t_stack *)acc_stack);
}

int	is_ordered(t_stack *lst)
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

void	move_to_head(t_stack **stack, t_stack *node, int stack_size)
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
