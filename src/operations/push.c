/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dde-fite <dde-fite@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 21:59:02 by dde-fite          #+#    #+#             */
/*   Updated: 2025/12/10 19:35:30 by dde-fite         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	push(t_stack **from, t_stack **dest)
{
	t_stack	*_tmp;

	if (!from || !dest || !*from)
		return (-1);
	_tmp = (*from)->next;
	lstadd_front(dest, *from);
	*from = _tmp;
	return (0);
}

void	pa(t_global *global_stacks)
{
	if (!push(&global_stacks->stack_b, &global_stacks->stack_a))
		ft_printf(PUSH_A);
}

void	pb(t_global *global_stacks)
{
	if (!push(&global_stacks->stack_a, &global_stacks->stack_b))
		ft_printf(PUSH_B);
}
