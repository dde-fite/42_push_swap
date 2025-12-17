/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dde-fite <dde-fite@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/17 21:17:46 by dde-fite          #+#    #+#             */
/*   Updated: 2025/12/17 21:33:54 by dde-fite         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

int	initialize_stacks(t_global *stacks, char *argv[])
{
	t_stack	*_lst;
	char	*_tmp;

	stacks->stack_a = NULL;
	stacks->stack_b = NULL;
	while (*argv)
	{
		_tmp = *argv;
		while (*_tmp)
		{
			if (ft_isdigit(*_tmp) || ((*_tmp == '-' || *_tmp == '+')
					&& ft_isdigit(*(_tmp + 1))))
			{
				_lst = lstnew(normalize_input(stacks, _tmp));
				if (!_lst)
					cleanup_error(stacks);
				lstadd_back(&stacks->stack_a, _lst);
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
	stacks->len = lstsize(stacks->stack_a);
	return (0);
}
