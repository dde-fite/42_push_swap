/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dde-fite <dde-fite@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 20:37:15 by dde-fite          #+#    #+#             */
/*   Updated: 2025/12/08 20:01:33 by dde-fite         ###   ########.fr       */
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
			if (ft_isdigit(*_tmp))
			{
				nbr = ft_atoi(_tmp);
				if (nbr > INT_MAX || is_reapeated(stacks->stack_a, nbr))
					return (memory_error(stacks));
				_lst = lstnew(nbr);
				if (!_lst)
					return (memory_error(stacks));
				lstadd_back(&stacks->stack_a, _lst);
				while (*_tmp && ft_isdigit(*_tmp))
					_tmp++;
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

int	is_ordered(t_stack *lst)
{
	if (!lst)
		return (0);
	while (lst && lst->next)
	{
		if (lst->number > lst->next->number)
			return (0);
		lst = lst->next;
	}
	return (1);
}

void	method_switch(t_global *global_stacks)
{
	if (is_ordered(global_stacks->stack_a))
		return ;
	if (global_stacks->len == 3)
	{
		
	}
	if (global_stacks->len == 5)
	{
		
	}
	else
	{
		
	}
}

int	main(int argc, char *argv[])
{
	t_global	global_stacks;

	if (argc < 3)
		return (parsing_error());
	if (initialize_stacks(&global_stacks, argv + 1))
		return (-1);
	method_switch(&global_stacks);
	return (0);
}
