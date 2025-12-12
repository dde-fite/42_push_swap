/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lis.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dde-fite <dde-fite@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/12 17:27:05 by dde-fite          #+#    #+#             */
/*   Updated: 2025/12/12 21:29:08 by dde-fite         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_stack	*get_lis(t_global *global_stack, t_stack *stack)
{
	int const	stack_size = lstsize(stack);
	int			*lis_count;
	int			i;
	int			acc;
	t_stack		*_stack;

	i = 0;
	lis_count = ft_calloc(stack_size, sizeof(int));
	if (!lis_count)
	{
		global_stack->error = true;
		return (NULL);
	}
	while (i < stack_size)
	{
		_stack = get_by_index(stack, i);
		while (_stack)
		{
			acc = INT_MIN;
			if (_stack->number > acc)
			{
				acc = _stack->number;
				lis_count[i]++;
			}
			_stack = _stack->next;
		}
		i++;
	}
	return (get_by_index(stack,
			(int)(lis_count - get_max_arr_value(lis_count))));
}

void	push_nolis_to_b(t_global *global_stacks)
{
	t_stack const	*lis = get_lis(global_stacks->stack_a);
	t_stack			*_stack_a;
	int				acc;

	if (!lis)
		return ;
	_stack_a = global_stacks->stack_a;
	acc = INT_MIN;
	while (_stack_a && _stack_a != lis)
	{
		pb(global_stacks);
		_stack_a = _stack_a->next;
	}
	while (_stack_a)
	{
		if (_stack_a->number > acc)
			acc = _stack_a->number;
		else
			pb(global_stacks);
		_stack_a = _stack_a->next;
	}
}
