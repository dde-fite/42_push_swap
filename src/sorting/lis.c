/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lis.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dde-fite <dde-fite@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/12 17:27:05 by dde-fite          #+#    #+#             */
/*   Updated: 2025/12/13 23:10:06 by dde-fite         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_stack	*get_lis(t_stack *stack, bool *error)
{
	int const	stack_size = ft_maxnbr(0, lstsize(stack) - 1);
	int			*lis;
	int			i;
	int			acc;
	t_stack		*_stack;

	lis = ft_calloc(stack_size + 1, sizeof(int));
	if (!lis)
	{
		*error = true;
		return (NULL);
	}
	i = 0;
	while (i < stack_size)
	{
		_stack = get_by_index(stack, i);
		acc = INT_MIN;
		while (_stack)
		{
			if (_stack->number > acc)
			{
				acc = _stack->number;
				lis[i]++;
			}
			_stack = _stack->next;
		}
		i++;
	}
	return (get_by_index(stack,
			(int)(lis - get_max_arr_value(lis))));
}

void	push_nolis_to_b(t_global *global_stacks)
{
	t_stack const	*lis = get_lis(global_stacks->stack_a,
			&global_stacks->error);
	t_stack			*_stack_a;
	int				acc;

	if (!lis)
		return ;
	_stack_a = global_stacks->stack_a;
	while (_stack_a && _stack_a != lis)
	{
		pb(global_stacks);
		_stack_a = _stack_a->next;
	}
	acc = INT_MIN;
	while (_stack_a)
	{
		if (_stack_a->number > acc)
			acc = _stack_a->number;
		else
			pb(global_stacks);
		_stack_a = _stack_a->next;
	}
}
