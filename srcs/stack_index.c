/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_index.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anorjen <anorjen@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/02 20:30:20 by anorjen           #+#    #+#             */
/*   Updated: 2020/07/02 22:37:37 by anorjen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		is_max_index(t_stack *stack, int index)
{
	int			i;
	t_element	*element;

	element = stack->elements;
	i = -1;
	while (++i < stack->size)
	{
		if (index < element->index)
		{
			return (0);
		}
		element = element->next;
	}
	return (1);
}

int		is_min_index(t_stack *stack, int index)
{
	int			i;
	t_element	*element;

	element = stack->elements;
	i = -1;
	while (++i < stack->size)
	{
		if (index > element->index)
		{
			return (0);
		}
		element = element->next;
	}
	return (1);
}

int		get_min_index(t_stack *stack)
{
	int			i;
	t_element	*element;
	int			min;

	element = stack->elements;
	min = element->index;
	i = -1;
	while (++i < stack->size)
	{
		if (min > element->index)
		{
			min = element->index;
		}
		element = element->next;
	}
	return (min);
}

int		get_max_index(t_stack *stack)
{
	int			i;
	t_element	*element;
	int			max;

	element = stack->elements;
	max = element->index;
	i = -1;
	while (++i < stack->size)
	{
		if (max < element->index)
		{
			max = element->index;
		}
		element = element->next;
	}
	return (max);
}

int		to_index(t_stack *stack, int index)
{
	int			i;
	t_element	*element;
	int			steps;

	steps = 0;
	element = stack->elements;
	i = -1;
	while (++i < stack->size)
	{
		if (index != element->index)
		{
			++steps;
		}
		else
		{
			break ;
		}

		element = element->next;
	}
	return (steps);
}
