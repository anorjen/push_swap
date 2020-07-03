/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_rotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anorjen <anorjen@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/03 16:27:43 by anorjen           #+#    #+#             */
/*   Updated: 2020/07/03 16:28:44 by anorjen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	rotate_ra_or_rra(t_stack *stack)
{
	t_element	*elements;
	int			ra_counter;
	int			rra_counter;

	ra_counter = 0;
	rra_counter = 0;
	elements = stack->elements;
	while (elements->is_a == 1)
	{
		++ra_counter;
		elements = elements->next;
	}
	elements = stack->elements;
	while (elements->is_a == 1)
	{
		++rra_counter;
		elements = elements->prev;
	}
	return (rra_counter < ra_counter ? -rra_counter : ra_counter);
}

int	rotate_counter_b(int index, int prev_index, t_stack *stack)
{
	t_element	*elements;
	int			rcounter;
	int			rrcounter;

	rcounter = -1;
	rrcounter = -1;
	elements = stack->elements;
	while (++rcounter < stack->size)
	{
		if (elements->index == index - 1 || elements->index == prev_index + 1)
			break ;
		elements = elements->next;
	}
	elements = stack->elements;
	while (++rrcounter < stack->size)
	{
		if (elements->index == index - 1 || elements->index == prev_index + 1)
			break ;
		elements = elements->prev;
	}
	return (rcounter <= rrcounter ? rcounter : -rrcounter);
}
