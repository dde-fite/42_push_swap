/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dde-fite <dde-fite@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 20:37:15 by dde-fite          #+#    #+#             */
/*   Updated: 2025/12/12 16:40:16 by dde-fite         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_reapeated(t_stack *lst, int nbr)
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

int	initialize_stacks(t_global *stacks, char *argv[])
{
	t_stack	*_lst;
	char	*_tmp;
	long	nbr;

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
				nbr = ft_atol(_tmp);
				if (nbr > INT_MAX || nbr < INT_MIN
					|| is_reapeated(stacks->stack_a, nbr))
					return (memory_error(stacks));
				_lst = lstnew(nbr);
				if (!_lst)
					return (memory_error(stacks));
				lstadd_back(&stacks->stack_a, _lst);
				if (*_tmp == '-' || *_tmp == '+')
					_tmp++;
				while (*_tmp && ft_isdigit(*_tmp))
					_tmp++;
				if (*_tmp == '-' || *_tmp == '+')
					return (memory_error(stacks));
			}
			else
			{
				if (!ft_isspace(*_tmp))
					return (memory_error(stacks));
				_tmp++;
			}
		}
		argv++;
	}
	stacks->len = lstsize(stacks->stack_a);
	return (0);
}

int	main(int argc, char *argv[])
{
	t_global	global_stacks;

	if (argc < 2)
		return (0);
	if (initialize_stacks(&global_stacks, argv + 1))
		return (-1);
	if (lstsize(global_stacks.stack_a) < 2)
		return (0);
	method_switch(&global_stacks);
	print_stack(&global_stacks);
	lstclear(&global_stacks.stack_a);
	lstclear(&global_stacks.stack_b);
	return (0);
}
