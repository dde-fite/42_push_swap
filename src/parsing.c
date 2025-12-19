/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dde-fite <dde-fite@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/17 21:17:46 by dde-fite          #+#    #+#             */
/*   Updated: 2025/12/19 17:05:49 by dde-fite         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	add_to_stack(t_global *stacks, t_stack **last, int nbr)
{
	t_stack	*lst;

	lst = lstnew(nbr);
	if (!lst)
		cleanup_error(stacks);
	if (*last)
		(*last)->next = lst;
	else
		stacks->stack_a = lst;
	stacks->len_a++;
	*last = lst;
}

static int	is_reapeated(t_stack *lst, int nbr)
{
	if (!lst)
		return (0);
	while (lst)
	{
		if (nbr == lst->number)
			return (1);
		lst = lst->next;
	}
	return (0);
}

static int	normalize_input(t_global *global_stacks, char *str)
{
	long	nbr;

	nbr = ft_atol(str);
	if (nbr > INT_MAX || nbr < INT_MIN
		|| is_reapeated(global_stacks->stack_a, nbr))
		cleanup_error(global_stacks);
	return (nbr);
}

void	initialize_stacks(t_global *stacks, char *argv[])
{
	t_stack	*last;
	char	*_tmp;

	stacks->stack_a = NULL;
	stacks->stack_b = NULL;
	stacks->len_a = 0;
	stacks->len_b = 0;
	last = NULL;
	while (*argv)
	{
		_tmp = *argv;
		while (*_tmp)
		{
			if (ft_isdigit(*_tmp) || ((*_tmp == '-' || *_tmp == '+')
					&& ft_isdigit(*(_tmp + 1))))
			{
				add_to_stack(stacks, &last, normalize_input(stacks, _tmp));
				if (*_tmp == '-' || *_tmp == '+')
					_tmp++;
				while (*_tmp && ft_isdigit(*_tmp))
					_tmp++;
				if (*_tmp == '-' || *_tmp == '+')
					cleanup_error(stacks);
			}
			else
			{
				if (!ft_isspace(*_tmp))
					cleanup_error(stacks);
				_tmp++;
			}
		}
		argv++;
	}
}
