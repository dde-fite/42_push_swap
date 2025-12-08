/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lstclear.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dde-fite <dde-fite@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/16 18:18:56 by dde-fite          #+#    #+#             */
/*   Updated: 2025/12/08 18:47:01 by dde-fite         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	lstclear(t_stack **lst)
{
	t_stack	*nxtlst;

	if (!lst)
		return ;
	while (*lst)
	{
		nxtlst = (*lst)->next;
		free(*lst);
		*lst = nxtlst;
	}
}
