/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stacktools.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dde-fite <dde-fite@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/12 15:32:46 by dde-fite          #+#    #+#             */
/*   Updated: 2025/12/12 16:35:10 by dde-fite         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
