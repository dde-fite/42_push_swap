/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dde-fite <dde-fite@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 20:21:49 by dde-fite          #+#    #+#             */
/*   Updated: 2025/12/09 21:54:53 by dde-fite         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	swap(t_stack **stack)
{
	t_stack	*_tmp;

	if (!stack || !(*stack)->next)
		return ;
	_tmp = *stack;
	*stack = (*stack)->next;
	_tmp->next = (*stack)->next;
	(*stack)->next = _tmp;
}

void	sa(t_stack **stack_a)
{
	swap(stack_a);
	ft_printf("%s", SWAP_A);
}

void	sb(t_stack **stack_b)
{
	swap(stack_b);
	ft_printf("%s", SWAP_B);
}

void	ss(t_global *global_stacks)
{
	swap(&global_stacks->stack_a);
	swap(&global_stacks->stack_b);
	ft_printf("%s", SWAP_BOTH);
}
