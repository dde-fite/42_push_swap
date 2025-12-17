/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lis.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dde-fite <dde-fite@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/12 17:27:05 by dde-fite          #+#    #+#             */
/*   Updated: 2025/12/17 01:00:36 by dde-fite         ###   ########.fr       */
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
		_stack = get_by_index(stack, i++);
		acc = INT_MIN;
		while (_stack)
		{
			if (_stack->number > acc || (lis[i - 1] && !lis[i - 1]++))
				acc = _stack->number;
			_stack = _stack->next;
		}
	}
	_stack = get_by_index(stack, (lis - get_max_arr_value(lis)));
	return (free(lis), _stack);
}


void	push_lis_to_b(t_global *global_stacks)
{
	t_stack const	*lis = get_lis(global_stacks->stack_a,
			&global_stacks->error);
	int				acc;
	int				i;

	if (!lis)
		return ;
	while (global_stacks->stack_a != lis)
		ra(&global_stacks->stack_a);
	acc = INT_MIN;
	i = 0;
	while (i < global_stacks->len)
	{
		if (global_stacks->stack_a->number > acc)
		{
			acc = global_stacks->stack_a->number;
			pb(global_stacks);
		}
		else
			ra(&global_stacks->stack_a);
		i++;
	}
}
