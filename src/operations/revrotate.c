/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   revrotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dde-fite <dde-fite@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/10 19:10:51 by dde-fite          #+#    #+#             */
/*   Updated: 2025/12/10 20:52:30 by dde-fite         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	revrotate(t_stack **stack)
{
	t_stack	*_tmp;

	if (!*stack || !(*stack)->next)
		return (-1);
	_tmp = *stack;
	while (_tmp->next->next)
		_tmp = _tmp->next;
	lstadd_front(stack, lstlast(*stack));
	_tmp->next = NULL;
	return (0);
}

void	rra(t_stack **stack_a)
{
	if (!revrotate(stack_a))
		ft_printf(REV_ROTATE_A);
}

void	rrb(t_stack **stack_b)
{
	if (!revrotate(stack_b))
		ft_printf(REV_ROTATE_B);
}

void	rrr(t_global *global_stacks)
{
	if (!revrotate(&global_stacks->stack_a)
		&& !revrotate(&global_stacks->stack_b))
		ft_printf(REV_ROTATE_BOTH);
}
