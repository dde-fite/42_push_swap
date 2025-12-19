/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lstsize_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dde-fite <dde-fite@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/16 17:13:45 by dde-fite          #+#    #+#             */
/*   Updated: 2025/12/20 00:51:29 by dde-fite         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

int	lstsize(t_stack *lst)
{
	unsigned int	i;

	if (!lst)
		return (0);
	i = 1;
	while (lst->next)
	{
		lst = lst->next;
		i++;
	}
	return (i);
}

// int	main(void)
// {
// 	t_stack		*begin;
// 	t_stack		*a;
// 	t_stack		*b;
// 	t_stack		*c;
// 	char const	*a_cnt = "1st element";
// 	char const	*b_cnt = "2nd element";
// 	char const	*c_cnt = "3rd element";

// 	begin = NULL;
// 	a = ft_lstnew((void *)a_cnt);
// 	b = ft_lstnew((void *)b_cnt);
// 	c = ft_lstnew((void *)c_cnt);
// 	ft_lstadd_front(&begin, c);
// 	ft_lstadd_front(&begin, b);
// 	ft_lstadd_front(&begin, a);
// 	printf("Number of nodes: %d\n", ft_lstsize(begin));
// }
