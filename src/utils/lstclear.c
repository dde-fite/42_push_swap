/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lstclear.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dde-fite <dde-fite@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/16 18:18:56 by dde-fite          #+#    #+#             */
/*   Updated: 2025/12/04 18:57:24 by dde-fite         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_lstclear(t_stack **lst, void (*del)(void*))
{
	t_stack	*nxtlst;

	while (*lst)
	{
		nxtlst = (*lst)->next;
		ft_lstdelone(*lst, del);
		*lst = nxtlst;
	}
}
