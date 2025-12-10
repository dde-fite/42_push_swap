/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   methods.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dde-fite <dde-fite@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/10 20:55:53 by dde-fite          #+#    #+#             */
/*   Updated: 2025/12/10 22:14:08 by dde-fite         ###   ########.fr       */
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

static void	sort_five(t_global *global_stacks)
{
	pb(global_stacks);
	pb(global_stacks);
	sort_three(&global_stacks->stack_a);
	if (global_stacks->stack_b->number > global_stacks->stack_b->next->number)
		sb(global_stacks->stack_b);
}

void	method_switch(t_global *global_stacks)
{
	const size_t	len = lstsize(global_stacks->stack_a);

	if (is_ordered(global_stacks->stack_a))
		return ;
	if (len == 3)
		sort_three(&global_stacks->stack_a);
	if (len == 5)
		sort_five(global_stacks);
	// else
	// {
	// }
}
