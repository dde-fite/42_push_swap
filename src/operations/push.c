/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dde-fite <dde-fite@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 21:59:02 by dde-fite          #+#    #+#             */
/*   Updated: 2025/12/09 22:34:34 by dde-fite         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	push(t_stack **from, t_stack **dest)
{
	t_stack	*_tmp;

	if (!from || !dest)
		return ;
	_tmp = *from;
	
}

void	pa(t_global *global_stacks)
{
	push(global_stacks);
	ft_printf("%s", PUSH_A);
}

void	pb(t_global *global_stacks)
{
	push(global_stacks);
	ft_printf("%s", PUSH_B);
}