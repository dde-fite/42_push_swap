/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dde-fite <dde-fite@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/17 21:17:46 by dde-fite          #+#    #+#             */
/*   Updated: 2025/12/19 23:36:11 by dde-fite         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

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
	stacks->len++;
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

static int	parse_input(t_global *global_stacks, char *str)
{
	long	nbr;

	nbr = ft_atol(str);
	if (nbr > INT_MAX || nbr < INT_MIN
		|| is_reapeated(global_stacks->stack_a, nbr))
		cleanup_error(global_stacks);
	return (nbr);
}

static void	goto_end_of_nbr(t_global *stacks, char **str)
{
	if (ft_issign(**str))
		(*str)++;
	while (**str && ft_isdigit(**str))
		(*str)++;
	if (ft_issign(**str))
		cleanup_error(stacks);
}

void	populate_stacks(t_global *stacks, char *argv[])
{
	t_stack	*last;
	char	*_tmp;

	last = NULL;
	while (*argv)
	{
		_tmp = *argv;
		while (*_tmp)
		{
			if (ft_isdigit(*_tmp) || (ft_issign(*_tmp) && ft_isdigit(_tmp[1])))
			{
				add_to_stack(stacks, &last, parse_input(stacks, _tmp));
				goto_end_of_nbr(stacks, &_tmp);
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
