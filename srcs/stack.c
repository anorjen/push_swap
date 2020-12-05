/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anorjen <anorjen@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/12 15:42:56 by anorjen           #+#    #+#             */
/*   Updated: 2020/11/24 11:14:27 by anorjen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack		*new_stack(void)
{
	t_stack	*stack;

	if ((stack = (t_stack*)malloc(sizeof(t_stack))))
	{
		stack->elements = NULL;
		stack->size = 0;
		stack->marked = 0;
		stack->name = NULL;
	}
	return (stack);
}

t_element	*new_element(int value)
{
	t_element	*element;

	element = (t_element*)malloc(sizeof(t_element));
	if (element)
	{
		element->value = value;
		element->is_sorted = 0;
		element->is_a = 0;
		element->next = element;
		element->next = element;
	}
	return (element);
}

t_stack		*add_element(t_stack *stack, t_element *element)
{
	t_element	*last;
	t_element	*first;

	if (!stack)
		stack = new_stack();
	if (stack && element)
	{
		if (!stack->elements)
		{
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
		}
		stack->elements = element;
		stack->size++;
	}
	return (stack);
}

void		free_stack(t_stack *stack)
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
		if (stack->name)
			free(stack->name);
		free(stack);
	}
}

t_stack		*copy_stack(t_stack *stack)
{
	t_stack		*copy;
	t_element	*copy_element;
	t_element	*element;
	int			i;

	copy = new_stack();
	element = stack->elements->prev;
	i = -1;
	while (++i < stack->size)
	{
		copy_element = new_element(element->value);
		copy_element->index = element->index;
		copy_element->is_a = element->is_a;
		add_element(copy, copy_element);
		element = element->prev;
	}
	copy->marked = stack->marked;
	return (copy);
}
