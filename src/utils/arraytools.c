/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arraytools.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dde-fite <dde-fite@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/12 18:52:49 by dde-fite          #+#    #+#             */
/*   Updated: 2025/12/12 21:09:37 by dde-fite         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	*get_max_arr_value(int *arr)
{
	int	*acc;

	acc = arr;
	while (*arr)
	{
		if (*acc < *arr)
			acc = arr;
		arr++;
	}
	return (acc);
}
