/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turk_algorithm.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dde-fite <dde-fite@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/15 20:41:26 by dde-fite          #+#    #+#             */
/*   Updated: 2025/12/17 21:15:53 by dde-fite         ###   ########.fr       */
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
		_tmp = 0;
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

static void	calculate_costs(t_stack *stack)
{
	int const		half_point = lstsize(stack) / 2;
	t_stack const	*_stack = stack;

	while (stack)
	{
		stack->cost = get_index((t_stack *)_stack, stack);
		if (stack->cost > half_point)
			stack->cost = -(stack->cost - half_point);
		stack = stack->next;
	}
}

static void	mov_to_head_double(t_global *global_stacks, t_stack *node)
{
	while (global_stacks->stack_a != node
		|| global_stacks->stack_b != node->target)
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
			rrb(&global_stacks->stack_a->target);
	}
}

void	turk_algorithm(t_global *global_stacks)
{
	pb(global_stacks);
	pb(global_stacks);
	while (lstsize(global_stacks->stack_a) > 3)
	{
		calculate_costs(global_stacks->stack_a);
		calculate_costs(global_stacks->stack_b);
		set_targets_a(global_stacks->stack_a, global_stacks->stack_b);
		mov_to_head_double(global_stacks,
			seek_cheapest_combination(global_stacks->stack_a));
		pb(global_stacks);
		print_stack(global_stacks);
	}
	sort_three(&global_stacks->stack_a);
	while (global_stacks->stack_b)
	{
		print_stack(global_stacks);
		set_targets_b(global_stacks->stack_a, global_stacks->stack_b);
		move_to_head(&global_stacks->stack_a, global_stacks->stack_b->target);
		pa(global_stacks);
	}
	while (!is_ordered(global_stacks->stack_a))
		move_to_head(&global_stacks->stack_a,
			get_min_node(global_stacks->stack_a));
}
