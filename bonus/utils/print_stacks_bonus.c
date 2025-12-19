/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_stacks.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dde-fite <dde-fite@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/10 18:09:00 by dde-fite          #+#    #+#             */
/*   Updated: 2025/12/19 21:47:25 by dde-fite         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	print_stack(t_global *global_stacks)
{
	t_stack	*_tmp_a;
	t_stack	*_tmp_b;

	_tmp_a = global_stacks->stack_a;
	_tmp_b = global_stacks->stack_b;
	ft_printf("|==== STACKS =====|\n|=|  A  |  B  |=|\n");
	while (_tmp_a || _tmp_b)
	{
		ft_printf("|=| ");
		if (_tmp_a)
		{
			ft_printf("%d\t|\t", _tmp_a->number);
			_tmp_a = _tmp_a->next;
		}
		else
			ft_printf("-  |  ");
		if (_tmp_b)
		{
			ft_printf("%d  |=|\n", _tmp_b->number);
			_tmp_b = _tmp_b->next;
		}
		else
			ft_printf("-  |=|\n");
	}
	ft_printf("|=================|\n");
}
