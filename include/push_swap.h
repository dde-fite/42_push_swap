/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dde-fite <dde-fite@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 17:32:34 by dde-fite          #+#    #+#             */
/*   Updated: 2025/11/28 20:48:34 by dde-fite         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ************************************************************************** */
/*                           push_swap by dde-fite                            */
/* ************************************************************************** */

/* ************************ PREPROCESSOR STATEMENTS ************************* */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft.h"
// # include <stdlib.h>
// # include <string.h>
// # include <stdint.h>
// # include <limits.h>
// # include <unistd.h>
// # include <stdio.h>

/* ******************** STRUCTS, TYPES, OTHER STATEMENTS ******************** */

typedef struct s_node
{
	int		number;
	int		cost;
	t_node	*target;
	t_node	*prev;
	t_node	*next;
}	t_node;

#endif