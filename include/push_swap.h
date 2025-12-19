/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dde-fite <dde-fite@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 17:32:34 by dde-fite          #+#    #+#             */
/*   Updated: 2025/12/19 16:19:34 by dde-fite         ###   ########.fr       */
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
# define SWAP_A "sa\n"
# define SWAP_B "sb\n"
# define SWAP_BOTH "ss\n"
# define PUSH_A "pa\n"
# define PUSH_B "pb\n"
# define ROTATE_A "ra\n"
# define ROTATE_B "rb\n"
# define ROTATE_BOTH "rr\n"
# define REV_ROTATE_A "rra\n"
# define REV_ROTATE_B "rrb\n"
# define REV_ROTATE_BOTH "rrr\n"

/* ******************** STRUCTS, TYPES, OTHER STATEMENTS ******************** */

typedef struct s_stack
{
	int				number;
	int				cost;
	struct s_stack	*target;
	struct s_stack	*next;
}	t_stack;

typedef struct s_global
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	int		len_a;
	int		len_b;
}	t_global;

/* ******************** ERROR HANDLING ******************** */

void	parsing_error(void);
void	cleanup_error(t_global *stacks);

void	initialize_stacks(t_global *stacks, char *argv[]);

/* ******************** OPERATIONS ******************** */
void	method_switch(t_global *global_stacks);
void	turk_algorithm(t_global *global_stacks);

void	sort_three(t_stack **stack);

void	sa(t_stack **stack_a);
void	sb(t_stack **stack_b);
void	ss(t_global *global_stacks);
void	pa(t_global *global_stacks);
void	pb(t_global *global_stacks);
void	ra(t_stack **stack_a);
void	rb(t_stack **stack_b);
void	rr(t_global *global_stacks);
void	rra(t_stack **stack_a);
void	rrb(t_stack **stack_b);
void	rrr(t_global *global_stacks);

/* ******************** UTILS ******************** */

t_stack	*get_max_node(t_stack *stack);
void	move_to_head(t_stack **stack, t_stack *node);
int		is_ordered(t_stack *lst);
int		*get_max_arr_value(int *arr);
t_stack	*get_by_index(t_stack *stack, int idx);
int		get_index(t_stack *stack, t_stack *node);
t_stack	*get_min_node(t_stack *stack);
void	lstadd_back(t_stack **lst, t_stack *new);
void	lstadd_front(t_stack **lst, t_stack *new);
void	lstclear(t_stack **lst);
t_stack	*lstlast(t_stack *lst);
t_stack	*lstnew(int number);
int		lstsize(t_stack *lst);
void	lstdelone(t_stack *lst);

void	print_stack(t_global *global_stacks);

#endif