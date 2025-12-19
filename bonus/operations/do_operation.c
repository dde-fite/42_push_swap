/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_operation.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dde-fite <dde-fite@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/20 00:25:46 by dde-fite          #+#    #+#             */
/*   Updated: 2025/12/20 00:45:34 by dde-fite         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

static void	do_swap(t_global *stacks, char *ln, size_t ln_len)
{
	if (ft_strncmp(SWAP_A, ln, ln_len))
		swap(&stacks->stack_a);
	else if (ft_strncmp(SWAP_B, ln, ln_len))
		swap(&stacks->stack_b);
	else if (ft_strncmp(SWAP_BOTH, ln, ln_len))
	{
		swap(&stacks->stack_a);
		swap(&stacks->stack_b);
	}
	else
		cleanup_error(stacks);
}

static void	do_push(t_global *stacks, char *ln, size_t ln_len)
{
	if (ft_strncmp(PUSH_A, ln, ln_len))
		push(&stacks->stack_b, &stacks->stack_a);
	else if (ft_strncmp(PUSH_B, ln, ln_len))
		push(&stacks->stack_a, &stacks->stack_b);
	else
		cleanup_error(stacks);
}

static void	do_revrotate(t_global *stacks, char *ln, size_t ln_len)
{
	if (ft_strncmp(REV_ROTATE_A, ln, ln_len))
		revrotate(&stacks->stack_a);
	else if (ft_strncmp(REV_ROTATE_B, ln, ln_len))
		revrotate(&stacks->stack_b);
	else if (ft_strncmp(REV_ROTATE_BOTH, ln, ln_len))
	{
		revrotate(&stacks->stack_a);
		revrotate(&stacks->stack_b);
	}
	else
		cleanup_error(stacks);
}

static void	do_rotate(t_global *stacks, char *ln, size_t ln_len)
{
	if (ft_strncmp(ROTATE_A, ln, ln_len))
		rotate(&stacks->stack_a);
	else if (ft_strncmp(ROTATE_B, ln, ln_len))
		rotate(&stacks->stack_b);
	else if (ft_strncmp(ROTATE_BOTH, ln, ln_len))
	{
		rotate(&stacks->stack_a);
		rotate(&stacks->stack_b);
	}
	else
		cleanup_error(stacks);
}

void	do_instructions(t_global *stacks)
{
	char	*ln;
	size_t	ln_len;

	ln = get_next_line(1);
	while (ln)
	{
		ln_len = ft_strlen(ln);
		if (*ln == 's')
			do_swap(stacks, ln, ln_len);
		else if (*ln == 'p')
			do_push(stacks, ln, ln_len);
		else if (*ln == 'r')
		{
			if (ln[1] == 'r')
				do_revrotate(stacks, ln, ln_len);
			else
				do_rotate(stacks, ln, ln_len);
		}
		else
			cleanup_error(stacks);
		free(ln);
		ln = get_next_line(1);
	}
}
