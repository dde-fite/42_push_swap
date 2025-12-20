/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dde-fite <dde-fite@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 21:59:02 by dde-fite          #+#    #+#             */
/*   Updated: 2025/12/20 01:18:10 by dde-fite         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

int	swap(t_stack **stack)
{
	t_stack	*_tmp;

	if (!*stack || !(*stack)->next)
		return (-1);
	_tmp = *stack;
	*stack = (*stack)->next;
	_tmp->next = (*stack)->next;
	(*stack)->next = _tmp;
	return (0);
}

int	push(t_stack **from, t_stack **dest)
{
	t_stack	*_tmp;

	if (!from || !dest || !*from)
		return (-1);
	_tmp = (*from)->next;
	lstadd_front(dest, *from);
	*from = _tmp;
	return (0);
}

int	revrotate(t_stack **stack)
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

int	rotate(t_stack **stack)
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
