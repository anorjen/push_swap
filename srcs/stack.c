/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anorjen <anorjen@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/12 15:42:56 by anorjen           #+#    #+#             */
/*   Updated: 2020/02/12 16:50:30 by anorjen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_stack	*new_stack()
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

	if (!stack)
	{
		stack = new_stack();
	}
	if (stack && element)
	{
		if (!stack->elements)
		{
			stack->elements = element;
		}
		else
		{
			last = stack->elements->prev;
			element->next = stack->elements;
			element->prev = last;
			last->next = element;
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
