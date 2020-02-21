/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_operation.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anorjen <anorjen@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/12 16:40:35 by anorjen           #+#    #+#             */
/*   Updated: 2020/02/20 16:56:05 by anorjen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void			swap_elements(t_stack *stack)
{
	t_element	*first;
	t_element	*second;

	if (stack && stack->elements && stack->size > 1)
	{
		first = stack->elements;
		second = stack->elements->next;
		second->prev = first->prev;
		first->next = second->next;
		second->next = first;
		first->prev = second;
		stack->elements = second;
	}
}

void			push_element(t_stack *from, t_stack *to)
{
	t_element	*element;
	t_element	*last;

	if (from && from->elements && from->size)
	{
		last = from->elements->prev;
		element = from->elements;
		from->elements = element->next;
		from->elements->prev = element->prev;
		last->next = from->elements;
		from->size--;
		to = add_element(to, element);
	}
}

void			rotate_elements(t_stack *stack)
{
	if (stack && stack->elements)
		stack->elements = stack->elements->next;
}

void			rrotate_elements(t_stack *stack)
{
	if (stack && stack->elements)
		stack->elements = stack->elements->prev;
}
