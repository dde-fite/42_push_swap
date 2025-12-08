/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dde-fite <dde-fite@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 17:32:34 by dde-fite          #+#    #+#             */
/*   Updated: 2025/12/08 19:16:22 by dde-fite         ###   ########.fr       */
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
	int				number;
	int				cost;
	struct s_stack	*target;
	struct s_stack	*prev;
	struct s_stack	*next;
}	t_stack;

typedef struct s_global
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	int		len;
}	t_global;

int		parsing_error(void);
int		memory_error(t_global *stacks);

int		initialize_stacks(t_global *stacks, char *argv[]);

void	lstadd_back(t_stack **lst, t_stack *new);
void	lstadd_front(t_stack **lst, t_stack *new);
void	lstclear(t_stack **lst);
t_stack	*lstlast(t_stack *lst);
t_stack	*lstnew(int number);
int		lstsize(t_stack *lst);
void	lstdelone(t_stack *lst);

#endif