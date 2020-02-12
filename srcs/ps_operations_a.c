/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_a.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anorjen <anorjen@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/12 15:10:27 by anorjen           #+#    #+#             */
/*   Updated: 2020/02/12 16:25:35 by anorjen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** sa :swap a- swap the first 2 elements at the top of stack a. Do nothing if thereis only one or no elements).
** sb :swap b- swap the first 2 elements at the top of stack b. Do nothing if thereis only one or no elements).
** ss :sa and sb at the same time.
** pa :push a- take the first element at the top of b and put it at the top of a. Donothing if b is empty.
** pb :push b- take the first element at the top of a and put it at the top of b. Donothing ifais empty.
** ra :rotate a- shift up all elements of stack a by 1. The first element becomes the last one.
** rb :rotate b- shift up all elements of stack b by 1. The first element becomes the last one.
** rr :ra and rb at the same time.
** rra :reverse rotate a- shift down all elements of stack a by 1. The last element becomes the first one.
** rrb :reverse rotate b- shift down all elements of stackbby 1. The last element becomes the first one.
** rrr :rra and rrb at the same time.
*/

#include "push_swap.h"

void	sa(t_stack *stack_a, t_stack *stack_b)
{
	(void)stack_b;
	swap_elements(stack_a);
}

void	pa(t_stack *stack_a, t_stack *stack_b)
{
	push_element(stack_b, stack_a);
}

void	ra(t_stack *stack_a, t_stack *stack_b)
{
	(void)stack_b;
	rotate_elements(stack_a);
}

void	rra(t_stack *stack_a, t_stack *stack_b)
{
	(void)stack_b;
	rrotate_elements(stack_a);
}
