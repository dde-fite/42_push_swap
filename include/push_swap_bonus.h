/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dde-fite <dde-fite@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/19 01:43:11 by dde-fite          #+#    #+#             */
/*   Updated: 2025/12/20 00:51:18 by dde-fite         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ************************************************************************** */
/*                           push_swap by dde-fite                            */
/* ************************************************************************** */

/* ************************ PREPROCESSOR STATEMENTS ************************* */

#ifndef PUSH_SWAP_BONUS_H
# define PUSH_SWAP_BONUS_H

# include "ft_printf.h"

# define OK_MESSAGE "OK\n"
# define KO_MESSAGE "KO\n"
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
	struct s_stack	*next;
}	t_stack;

typedef struct s_global
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	int		len;
}	t_global;

/* ******************** ERROR HANDLING ******************** */

void	parsing_error(void);
void	cleanup_error(t_global *stacks);

void	populate_stacks(t_global *stacks, char *argv[]);
void	do_instructions(t_global *stacks);

/* ******************** OPERATIONS ******************** */

int		swap(t_stack **stack);
int		push(t_stack **from, t_stack **dest);
int		revrotate(t_stack **stack);
int		rotate(t_stack **stack);

/* ******************** UTILS ******************** */

int		lstsize(t_stack *lst);
int		is_ordered(t_stack *lst);
void	lstadd_back(t_stack **lst, t_stack *new);
void	lstadd_front(t_stack **lst, t_stack *new);
void	lstclear(t_stack **lst);
t_stack	*lstlast(t_stack *lst);
t_stack	*lstnew(int number);

void	print_stack(t_global *global_stacks);

#endif