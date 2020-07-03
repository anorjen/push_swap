/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple_merge_sort.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anorjen <anorjen@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/30 19:58:09 by anorjen           #+#    #+#             */
/*   Updated: 2020/07/03 18:31:44 by anorjen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Deprecated
*/

#include "push_swap.h"

static void	sms_from_a_to_b(t_stack *stack_a, t_stack *stack_b, int size, char *sort)
{
	int			i;
	int			count;

	i = 0;
	while (i < size)
	{
		if (stack_a->elements->is_a == 0)
		{
			if (stack_b->size >= 2)
			{
				count = find_place(stack_b, stack_a->elements->index, sort);
				shift(stack_b, count);
			}
			pb(stack_a, stack_b);
			logger(stack_b, "p");
			++i;
		}
		else
		{
			ra(stack_a, stack_b);
			logger(stack_a, "r");
		}
	}
}

void		simple_merge_sort(t_stack *stack_a, t_stack *stack_b)
{
	indexing(stack_a);
	markup(stack_a);
	sms_from_a_to_b(stack_a, stack_b, number_of_marked(stack_a), "asc");
	align(stack_a, "asc");
	align(stack_b, "asc");
	merge(stack_a, stack_b, stack_a->size);
}
