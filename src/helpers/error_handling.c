/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handling.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dde-fite <dde-fite@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/04 15:53:27 by dde-fite          #+#    #+#             */
/*   Updated: 2025/12/08 19:19:29 by dde-fite         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	parsing_error(void)
{
	ft_putstr_fd(ERROR_MESSAGE, 2);
	return (-1);
}

int	memory_error(t_global *stacks)
{
	if (stacks->stack_a)
		lstclear(&stacks->stack_a);
	if (stacks->stack_b)
		lstclear(&stacks->stack_b);
	ft_putstr_fd(ERROR_MESSAGE, 2);
	return (-1);
}
