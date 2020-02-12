/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anorjen <anorjen@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/12 15:12:21 by anorjen           #+#    #+#             */
/*   Updated: 2020/02/12 18:16:16 by anorjen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <stdlib.h>
# include "libft.h"

typedef struct		s_element
{
	int				value;
	struct s_stack	*prev;
	struct s_stack	*next;
}					t_element;

typedef struct		s_stack
{
	t_element		*elements;
	int				size;
}					t_stack;

typedef void		(*t_spe_key)(t_stack *a, t_stack *b);

typedef struct		s_operation
{
	char			*name;
	t_spe_key		operation;
}					t_operation;

/*
** ps_operation.c
*/

void	sa(t_stack *stack_a, t_stack *stack_b);
void	pa(t_stack *stack_a, t_stack *stack_b);
void	ra(t_stack *stack_a, t_stack *stack_b);
void	rra(t_stack *stack_a, t_stack *stack_b);

void	sb(t_stack *stack_a, t_stack *stack_b);
void	pb(t_stack *stack_a, t_stack *stack_b);
void	rb(t_stack *stack_a, t_stack *stack_b);
void	rrb(t_stack *stack_a, t_stack *stack_b);

void	ss(t_stack *stack_a, t_stack *stack_b);
void	rr(t_stack *stack_a, t_stack *stack_b);
void	rrr(t_stack *stack_a, t_stack *stack_b);

/*
** stack.c
*/

t_element		*new_element(int value);
t_stack			*add_element(t_stack *stack, t_element *element);
void			free_stack(t_stack *stack);

/*
** stack_operation.c
*/

void			swap_elements(t_stack *stack);
void			push_element(t_stack *from, t_stack *to);
void			rotate_elements(t_stack *stack);
void			rrotate_elements(t_stack *stack);

t_operation			g_operations[12] = {
	{"sa", sa},
	{"sb", sb},
	{"ss", ss},
	{"pa", pa},
	{"pb", pb},
	{"ra", ra},
	{"rb", rb},
	{"rr", rr},
	{"rra", rra},
	{"rrb", rrb},
	{"rrr", rrr},
	{NULL, NULL}
};

#endif
