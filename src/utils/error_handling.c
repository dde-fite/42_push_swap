/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handling.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dde-fite <dde-fite@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/04 15:53:27 by dde-fite          #+#    #+#             */
/*   Updated: 2025/12/05 20:22:36 by dde-fite         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	parsing_error(void)
{
	ft_putchar(ERROR_MESSAGE, 2);
	return (-1);
}

int	memory_error(t_stack *lst)
{
	lstclear(&lst);
	ft_putchar(ERROR_MESSAGE, 2);
	return (-1);
}
