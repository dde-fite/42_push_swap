/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turk_algorithm.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dde-fite <dde-fite@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/15 20:41:26 by dde-fite          #+#    #+#             */
/*   Updated: 2025/12/19 17:16:09 by dde-fite         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_stack	*seek_cheapest_combination(t_stack *stack_a)
{
	t_stack			*s_acc;
	int				acc;
	int				_tmp;

	acc = INT_MAX;
	while (stack_a)
	{
		if ((stack_a->cost > 0 && stack_a->target->cost > 0)
			|| (stack_a->cost < 0 && stack_a->target->cost < 0))
			_tmp = ft_maxnbr(ft_abs(stack_a->cost),
					ft_abs(stack_a->target->cost));
		else
			_tmp = ft_abs(stack_a->cost) + ft_abs(stack_a->target->cost);
		if (_tmp < acc)
		{
			acc = _tmp;
			s_acc = stack_a;
		}
		stack_a = stack_a->next;
	}
	return (s_acc);
}

static void	set_targets_a(t_stack *stack_a, t_stack *stack_b)
{
	t_stack const	*_stack_b = stack_b;
	t_stack			*acc;

	while (stack_a)
	{
		stack_b = (t_stack *)_stack_b;
		acc = NULL;
		while (stack_b)
		{
			if (stack_b->number < stack_a->number
				&& (!acc || stack_b->number > acc->number))
				acc = stack_b;
			stack_b = stack_b->next;
		}
		if (acc && acc->number < stack_a->number)
			stack_a->target = acc;
		else
			stack_a->target = get_max_node((t_stack *)_stack_b);
		stack_a = stack_a->next;
	}
}

static void	set_targets_b(t_stack *stack_a, t_stack *stack_b)
{
	t_stack const	*_stack_a = stack_a;
	t_stack			*acc;

	while (stack_b)
	{
		stack_a = (t_stack *)_stack_a;
		acc = NULL;
		while (stack_a)
		{
			if (stack_b->number < stack_a->number
				&& (!acc || stack_a->number < acc->number))
				acc = stack_a;
			stack_a = stack_a->next;
		}
		if (acc && acc->number > stack_b->number)
			stack_b->target = acc;
		else
			stack_b->target = get_min_node((t_stack *)_stack_a);
		stack_b = stack_b->next;
	}
}

static void	calculate_costs(t_stack *stack, int stack_size)
{
	int	i;

	i = 0;
	while (stack)
	{
		if (i < stack_size / 2)
			stack->cost = i;
		else
			stack->cost = -(stack_size - i);
		i++;
		stack = stack->next;
	}
}

static void	mov_to_head_double(t_global *global_stacks, t_stack *node)
{
	while (node->cost || node->target->cost)
	{
		if ((node->cost > 0
				&& node->target->cost > 0))
			rr(global_stacks);
		else if (node->cost < 0
			&& node->target->cost < 0)
			rrr(global_stacks);
		else if (node->cost > 0)
			ra(&global_stacks->stack_a);
		else if (node->cost < 0)
			rra(&global_stacks->stack_a);
		else if (node->target->cost > 0)
			rb(&global_stacks->stack_b);
		else if (node->target->cost < 0)
			rrb(&global_stacks->stack_b);
		calculate_costs(global_stacks->stack_a, global_stacks->len_a);
		calculate_costs(global_stacks->stack_b, global_stacks->len_b);
	}
}

void	turk_algorithm(t_global *stacks)
{
	pb(stacks);
	pb(stacks);
	while (stacks->len_a > 3)
	{
		calculate_costs(stacks->stack_a, stacks->len_a);
		calculate_costs(stacks->stack_b, stacks->len_b);
		set_targets_a(stacks->stack_a, stacks->stack_b);
		mov_to_head_double(stacks, seek_cheapest_combination(stacks->stack_a));
		pb(stacks);
	}
	sort_three(&stacks->stack_a);
	while (stacks->stack_b)
	{
		set_targets_b(stacks->stack_a, stacks->stack_b);
		move_to_head(&stacks->stack_a, stacks->stack_b->target, stacks->len_a);
		pa(stacks);
	}
	while (!is_ordered(stacks->stack_a))
		move_to_head(&stacks->stack_a, get_min_node(stacks->stack_a),
			stacks->len_a);
}
