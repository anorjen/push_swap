/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anorjen <anorjen@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/12 15:14:28 by anorjen           #+#    #+#             */
/*   Updated: 2020/12/01 16:31:01 by anorjen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**	sa :swap a- swap the first 2 elements at the top of stacka.
**		Do nothing if thereis only one or no elements).
**	sb :swap b- swap the first 2 elements at the top of stackb.
**		Do nothing if thereis only one or no elements).
**	ss :sa and sb at the same time.
**	pa :push a- take the first element at the top of b
**		and put it at the top of a. Donothing if b is empty.
**	pb :push b- take the first element at the top of a
**		and put it at the top of b. Donothing ifais empty.
**	ra :rotate a- shift up all elements of stack a by 1.
**		The first element becomes the last one.
**	rb :rotate b- shift up all elements of stack b by 1.
**		The first element becomes the last one.
**	rr :ra and rb at the same time.
**	rra :reverse rotate a- shift down all elements of stack a by 1.
**		The last element becomes the first one.
**	rrb :reverse rotate b- shift down all elements of stackbby 1.
**		The last element becomes the first one.
**	rrr :rra and rrb at the same time.
*/

#include "push_swap.h"

void	ss(t_stack *stack_a, t_stack *stack_b)
{
	sa(stack_a, stack_b);
	sb(stack_a, stack_b);
}

void	rr(t_stack *stack_a, t_stack *stack_b)
{
	ra(stack_a, stack_b);
	rb(stack_a, stack_b);
}

void	rrr(t_stack *stack_a, t_stack *stack_b)
{
	rra(stack_a, stack_b);
	rrb(stack_a, stack_b);
}
