/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_operation.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anorjen <anorjen@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/12 16:40:35 by anorjen           #+#    #+#             */
/*   Updated: 2020/07/03 13:42:26 by anorjen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

void			swap_elements(t_stack *stack)
{
	t_element	*first;
	t_element	*second;
	t_element	*last;

	if (stack && stack->elements && stack->size > 1)
	{
		if (stack->size == 2)
			rotate_elements(stack);
		else
		{
			first = stack->elements;
			second = stack->elements->next;
			last = first->prev;
			// printf("%d %d %d\n", first->value, second->value, last->value);
			second->prev = last;
			first->next = second->next;
			first->next->prev = first;
			second->next = first;
			first->prev = second;
			last->next = second;
			stack->elements = second;
		}
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
		if (element == last)
		{
			from->elements = NULL;
		}
		else
		{
			from->elements = element->next;
			from->elements->prev = element->prev;
			last->next = from->elements;
		}
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
