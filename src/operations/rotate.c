/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dde-fite <dde-fite@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/10 19:10:51 by dde-fite          #+#    #+#             */
/*   Updated: 2025/12/10 19:44:13 by dde-fite         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	rotate(t_stack **stack)
{
	t_stack	*_tmp;

	if (!*stack || !(*stack)->next)
		return (-1);
	_tmp = (*stack)->next;
	(*stack)->next = NULL;
	lstadd_back(&_tmp, *stack);
	*stack = _tmp;
	return (0);
}

void	ra(t_stack **stack_a)
{
	if (!rotate(stack_a))
		ft_printf(ROTATE_A);
}

void	rb(t_stack **stack_b)
{
	if (!rotate(stack_b))
		ft_printf(ROTATE_B);
}

void	rr(t_global *global_stacks)
{
	if (!rotate(&global_stacks->stack_a) && !rotate(&global_stacks->stack_b))
		ft_printf(ROTATE_BOTH);
}
