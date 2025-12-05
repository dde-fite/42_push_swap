/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lstadd_front.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dde-fite <dde-fite@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/16 16:00:53 by dde-fite          #+#    #+#             */
/*   Updated: 2025/12/05 17:56:57 by dde-fite         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	lstadd_front(t_stack **lst, t_stack *new)
{
	new->next = *lst;
	*lst = new;
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
// 	while (begin)
// 	{
// 		printf("%s\n", (char *)begin->content);
// 		begin = begin->next;
// 	}
// }
