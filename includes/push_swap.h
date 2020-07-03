/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anorjen <anorjen@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/12 15:12:21 by anorjen           #+#    #+#             */
/*   Updated: 2020/07/03 18:07:43 by anorjen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# define DEBUG 0
# define ABS(x) (x >= 0 ? x : -x)
# include <stdlib.h>
# include "libft.h"

typedef struct			s_element
{
	int					value;
	int					index;
	int					is_a;
	int					is_sorted;
	// int					rcounter;
	// int					direction;
	struct s_element	*prev;
	struct s_element	*next;
}						t_element;

typedef struct		s_stack
{
	t_element		*elements;
	int				size;
	int				marked;
	char			*name;
}					t_stack;

typedef void		(*t_spe_key)(t_stack *a, t_stack *b);

typedef struct		s_operation
{
	char			*name;
	t_spe_key		operation;
}					t_operation;

t_list			**lst_operations;

/*
** arguments.c
*/
void				free_list(t_list *list);
void				finish(t_list **lst_operation, t_stack *stack_a, t_stack *stack_b);
int					check_number(char *str, int *number);
int					fill_stack(t_stack **stack, int ac, char **av);

/*
** ch_run.c
*/

int					check(t_stack *stack_a, t_stack *stack_b);
int					run(t_list *lst_operation, t_stack **stack_a, t_stack **stack_b);

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
** ps_sort.c
*/

int					find_place(t_stack *stack, int index, char *sort);
void				align(t_stack *stack, char *sort);
void				sort(t_stack *stack_a, t_stack *stack_b);

/*
** ps_utils.c
*/

int					*stack_to_array(t_stack *stack);
void				array_sort(int *array, int size);

/*
** ps_indexing.c
*/

void				indexing(t_stack *stack_a);

/*
** is_markup.c
*/

int					number_of_marked(t_stack *stack);
void				markup(t_stack *stack_a);

/*
** stack_index.c
*/

int					is_max_index(t_stack *stack, int index);
int					is_min_index(t_stack *stack, int index);
int					get_min_index(t_stack *stack);
int					get_max_index(t_stack *stack);
int					to_index(t_stack *stack, int index);

/*
** ms_shift.c
*/

void				shift(t_stack *stack, int count);
void				from_a_to_b(t_stack *stack_a, t_stack *stack_b, int size, char *sort);
void				move_b_to_a(t_stack *stack_a, t_stack *stack_b, int count);
void				merge(t_stack *stack_a, t_stack *stack_b, int sorted);

/*
** logger.c
*/

void				logger(t_stack *stack, char *type);

/*
** insert_sort.c
*/

void				insert_sort(t_stack *stack_a, t_stack *stack_b);

/*
** merge_sort.c
*/

void				merge_sort(t_stack *stack_a, t_stack *stack_b);

/*
** is_rotate.c
*/

int					rotate_ra_or_rra(t_stack *stack);
int					rotate_counter_b(int index, int prev_index, t_stack *stack);

/*
** simple_merge_sort.c
*/

void				simple_merge_sort(t_stack *stack_a, t_stack *stack_b);

#endif
