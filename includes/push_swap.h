/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anorjen <anorjen@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/12 15:12:21 by anorjen           #+#    #+#             */
/*   Updated: 2020/06/30 18:26:12 by anorjen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# define DEBUG 0
# include <stdlib.h>
# include "libft.h"

typedef struct			s_element
{
	int					value;
	int					index;
	int					is_a;
	int					rcounter;
	int					direction;
	struct s_element	*prev;
	struct s_element	*next;
}						t_element;

typedef struct		s_stack
{
	t_element		*elements;
	int				size;
	int				marked;
}					t_stack;

typedef void		(*t_spe_key)(t_stack *a, t_stack *b);

typedef struct		s_operation
{
	char			*name;
	t_spe_key		operation;
}					t_operation;

/*
** arguments.c
*/
void				free_list(t_list *lst_operations);
void				finish(t_list *lst_operations, t_stack *stack_a, t_stack *stack_b);
int					check_number(char *str, int *number);
int					fill_stack(t_stack **stack, int ac, char **av);

/*
** ch_run.c
*/

int	check(t_stack *stack_a, t_stack *stack_b);
int	run(t_list *lst_operations, t_stack **stack_a, t_stack **stack_b);

/*
** ps_operation.c
*/

void				sa(t_stack *stack_a, t_stack *stack_b);
void				pa(t_stack *stack_a, t_stack *stack_b);
void				ra(t_stack *stack_a, t_stack *stack_b);
void				rra(t_stack *stack_a, t_stack *stack_b);

void				sb(t_stack *stack_a, t_stack *stack_b);
void				pb(t_stack *stack_a, t_stack *stack_b);
void				rb(t_stack *stack_a, t_stack *stack_b);
void				rrb(t_stack *stack_a, t_stack *stack_b);

void				ss(t_stack *stack_a, t_stack *stack_b);
void				rr(t_stack *stack_a, t_stack *stack_b);
void				rrr(t_stack *stack_a, t_stack *stack_b);

/*
** stack.c
*/

t_stack				*new_stack();
t_element			*new_element(int value);
t_stack				*add_element(t_stack *stack, t_element *element);
void				free_stack(t_stack *stack);
t_stack				*copy_stack(t_stack *stack);

/*
** stack_operation.c
*/

void				swap_elements(t_stack *stack);
void				push_element(t_stack *from, t_stack *to);
void				rotate_elements(t_stack *stack);
void				rrotate_elements(t_stack *stack);

/*
** ps_sorting.c
*/

void				sorting(t_list **lst_operations, t_stack *stack_a, t_stack *stack_b);

/*
** ps_utils.c
*/

int					*stack_to_array(t_stack *stack);
void				array_sort(int *array, int size);

#endif
