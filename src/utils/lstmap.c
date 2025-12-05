/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lstmap.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dde-fite <dde-fite@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/16 18:30:24 by dde-fite          #+#    #+#             */
/*   Updated: 2025/12/05 17:59:56 by dde-fite         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*lstmap(t_stack *lst, void *(*f)(void *), void (*del)(void *))
{
	t_stack	*rsltlst;
	t_stack	*_rslt;
	void	*cntnt_ptr;

	rsltlst = NULL;
	while (lst)
	{
		cntnt_ptr = f(lst->content);
		_rslt = ft_lstnew(cntnt_ptr);
		if (!_rslt)
		{
			del(cntnt_ptr);
			ft_lstclear(&rsltlst, del);
		}
		ft_lstadd_back(&rsltlst, _rslt);
		lst = lst->next;
	}
	return (rsltlst);
}
