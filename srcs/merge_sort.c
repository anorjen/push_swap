/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   merge_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anorjen <anorjen@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/30 19:58:09 by anorjen           #+#    #+#             */
/*   Updated: 2020/07/03 16:32:03 by anorjen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	get_chunk(int size)
{
	if (size > 0 && size <= 25)
		return (1);
	else if (size <= 100)
		return (size / 25);
	else if (size <= 500)
		return (size / 50);
	else
		return (10);
}

static void	first_chunk(t_stack *stack_a, t_stack *stack_b)
{
	int	count;

	count = stack_a->size / get_chunk(stack_a->size);
	from_a_to_b(stack_a, stack_b, count, "desc");
	align(stack_b, "desc");
	move_b_to_a(stack_a, stack_b, count);
	shift(stack_a, count);
}

static int	count_sorted(t_stack *stack)
{
	int			i;
	int			nbr;
	t_element	*tmp;

	nbr = 0;
	tmp = stack->elements;
	i = -1;
	while (++i < stack->size)
	{
		if (tmp->is_sorted == 1)
		{
			++nbr;
		}
		tmp = tmp->next;
	}
	return (nbr);
}

static void	next_chunk(t_stack *stack_a, t_stack *stack_b)
{
	int	count;
	int	i;
	int	nbr_sorted;

	nbr_sorted = count_sorted(stack_a);
	count = stack_a->size / get_chunk(stack_a->size);
	if ((stack_a->size - nbr_sorted) < count)
	{
		count = stack_a->size - nbr_sorted;
	}
	i = -1;
	from_a_to_b(stack_a, stack_b, count, "asc");
	align(stack_b, "asc");
	shift(stack_a, -nbr_sorted);
	merge(stack_a, stack_b, nbr_sorted);
}

void		merge_sort(t_stack *stack_a, t_stack *stack_b)
{
	indexing(stack_a);
	first_chunk(stack_a, stack_b);
	while (count_sorted(stack_a) < stack_a->size)
	{
		next_chunk(stack_a, stack_b);
	}
}
