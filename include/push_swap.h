/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dde-fite <dde-fite@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 17:32:34 by dde-fite          #+#    #+#             */
/*   Updated: 2025/12/04 17:24:46 by dde-fite         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ************************************************************************** */
/*                           push_swap by dde-fite                            */
/* ************************************************************************** */

/* ************************ PREPROCESSOR STATEMENTS ************************* */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "ft_printf.h"
// # include <stdlib.h>
// # include <string.h>
// # include <stdint.h>
// # include <limits.h>
// # include <unistd.h>
// # include <stdio.h>

# define ERROR_MESSAGE "Error\n"

/* ******************** STRUCTS, TYPES, OTHER STATEMENTS ******************** */

typedef struct s_stack
{
	int		number;
	int		cost;
	t_stack	*target;
	t_stack	*prev;
	t_stack	*next;
}	t_stack;

#endif