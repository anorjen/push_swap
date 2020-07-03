/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anorjen <anorjen@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/03 13:22:39 by anorjen           #+#    #+#             */
/*   Updated: 2020/07/03 17:20:59 by anorjen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static	int find_place_asc(t_stack *stack, int index)
{
	int			i;
	int			steps;
	t_element	*element;

	steps = 0;
	element = stack->elements;
	if (is_max_index(stack, index) || is_min_index(stack, index))
		steps = to_index(stack, get_min_index(stack));
	else
	{
		i = -1;
		while (++i < stack->size)
		{
			if (element->index > index && element->prev->index < index)
				break ;
			++steps;
			element = element->next;
		}
	}
	return (steps <= stack->size / 2 ? steps : -(stack->size - steps));
}

static int		find_place_desc(t_stack *stack, int index)
{
	int			i;
	int			steps;
	t_element	*element;

	steps = 0;
	element = stack->elements;
	if (is_max_index(stack, index) || is_min_index(stack, index))
		steps = to_index(stack, get_max_index(stack));
	else
	{
		i = -1;
		while (++i < stack->size)
		{
			if (element->index < index && element->prev->index > index)
				break ;
			++steps;
			element = element->next;
		}
	}
	return (steps <= stack->size / 2 ? steps : -(stack->size - steps));
}

int		find_place(t_stack *stack, int index, char *sort)
{
	if (ft_strcmp(sort, "desc") == 0)
		return (find_place_desc(stack, index));
	else if (ft_strcmp(sort, "asc") == 0)
		return (find_place_asc(stack, index));
	return (0);
}

void	align(t_stack *stack, char *sort)
{
	int	steps;

	steps = 0;
	if (ft_strcmp(sort, "desc") == 0)
	{
		steps = to_index(stack, get_max_index(stack));
	}
	else if (ft_strcmp(sort, "asc") == 0)
	{
		steps = to_index(stack, get_min_index(stack));
	}
	shift(stack, steps);
}

void	sort(t_stack *stack_a, t_stack *stack_b)
{

	if (stack_a->size < 50)
		insert_sort(stack_a, stack_b);
	else
		merge_sort(stack_a, stack_b);
}
