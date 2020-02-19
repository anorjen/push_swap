/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anorjen <anorjen@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/12 15:42:56 by anorjen           #+#    #+#             */
/*   Updated: 2020/02/19 17:16:39 by anorjen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*new_stack()
{
	t_stack	*stack;

	stack = (t_stack*)malloc(sizeof(t_stack));
	return (stack);
}

t_element		*new_element(int value)
{
	t_element	*element;

	element = (t_element*)malloc(sizeof(t_element));
	if (element)
	{
		element->value = value;
		element->next = element;
		element->next = element;
	}
	return (element);
}

t_stack			*add_element(t_stack *stack, t_element *element)
{
	t_element	*last;
	t_element	*first;

	if (!stack)
	{
		stack = new_stack();
	}
	if (stack && element)
	{
		if (!stack->elements)
		{
			stack->elements = element;
			element->next = element;
			element->prev = element;
		}
		else
		{
			first = stack->elements;
			last = stack->elements->prev;
			element->next = first;
			element->prev = last;
			last->next = element;
			first->prev = element;
			// if (stack->size == 1)
			// 	last->prev = element;
			stack->elements = element;
		}
		stack->size++;
	}
	return (stack);
}

void			free_stack(t_stack *stack)
{
	t_element	*element;
	int			size;

	if (stack)
	{
		if (stack->elements && stack->size)
		{
			size = stack->size;
			while (size)
			{
				element = stack->elements;
				stack->elements = stack->elements->next;
				free(element);
				--size;
			}
		}
		free(stack);
	}
}
