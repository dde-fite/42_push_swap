/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dde-fite <dde-fite@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 20:37:15 by dde-fite          #+#    #+#             */
/*   Updated: 2025/12/19 15:47:01 by dde-fite         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char *argv[])
{
	t_global	global_stacks;

	if (argc < 2)
		return (0);
	initialize_stacks(&global_stacks, argv + 1);
	if (global_stacks.len < 2)
		return (0);
	method_switch(&global_stacks);
	lstclear(&global_stacks.stack_a);
	lstclear(&global_stacks.stack_b);
	return (0);
}
