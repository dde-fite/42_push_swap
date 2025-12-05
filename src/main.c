/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dde-fite <dde-fite@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 20:37:15 by dde-fite          #+#    #+#             */
/*   Updated: 2025/12/05 20:50:11 by dde-fite         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	*initialize_stacks(t_stack **lst, char *argv[])
{
	t_stack	*_lst;
	char	*_tmp;

	while (*argv)
	{
		_tmp = *argv;
		while (*_tmp)
		{
			if (ft_isdigit(*_tmp))
			{
				_lst = lstnew(ft_atoi(_tmp));
				if (!_lst)
					return (memory_error(lst));
				lstadd_back(lst, _lst);
			}
			else
			{
				if (!ft_isspace)
					return (memory_error(lst));
				_tmp++;
			}
		}
	}
}

int	main(int argc, char *argv[])
{
	t_stack	*lst;

	lst = NULL;
	if (argc < 2)
		return (parsing_error());
	if (initialize_stacks(&lst, argv))
		return (-1);
}
