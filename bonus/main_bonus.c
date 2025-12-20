/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dde-fite <dde-fite@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 20:37:15 by dde-fite          #+#    #+#             */
/*   Updated: 2025/12/20 01:42:22 by dde-fite         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

int	main(int argc, char *argv[])
{
	t_global	global_stacks;

	if (argc < 2)
		return (0);
	global_stacks.stack_a = NULL;
	global_stacks.stack_b = NULL;
	global_stacks.len = 0;
	populate_stacks(&global_stacks, argv + 1);
	if (global_stacks.len < 2)
		return (0);
	do_instructions(&global_stacks);
	if (lstsize(global_stacks.stack_a) == global_stacks.len
		&& is_ordered(global_stacks.stack_a))
		ft_putstr_fd(OK_MESSAGE, 1);
	else
		ft_putstr_fd(KO_MESSAGE, 1);
	lstclear(&global_stacks.stack_a);
	lstclear(&global_stacks.stack_b);
	return (0);
}
