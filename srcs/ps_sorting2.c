/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_sorting2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anorjen <anorjen@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/30 19:58:09 by anorjen           #+#    #+#             */
/*   Updated: 2020/06/30 20:43:37 by anorjen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#define CHUNK 5

void	first_chunk(t_list **lst_operations, t_stack *stack_a, t_stack *stack_b)
{
	int	count;
	int	i;

	count = stack_a->size / 5;
	i = -1;
	while (++i < count)
	{
		from_a_to_b(lst_operations, stack_a, stack_b, 0);
	}
	move_b_to_a(lst_operations, stack_a, stack_b);
	shift(lst_operations, stack_a, count);
}

int		count_sorted(t_stack *stack)
{
	int			i;
	int			nbr;
	t_element	*tmp;

	tmp = stack->elements;
	i = -1;
	while (++i < stack->size)
	{
		if (tmp->is_sorted == 1)
		{
			++nbr;
		}
	}
	return (nbr);
}

void	next_chunk(t_list **lst_operations, t_stack *stack_a, t_stack *stack_b)
{
	int	count;
	int	i;
	int	nbr_sorted;

	nbr_sorted = count_sorted(stack_a);
	count = stack_a->size / 5;
	if (stack_a->size - nbr_sorted < count)
	{
		count = stack_a->size - nbr_sorted;
	}
	i = -1;
	while (++i < count)
	{
		from_a_to_b(lst_operations, stack_a, stack_b, 0);
	}
	merge(lst_operations, stack_a, stack_b, nbr_sorted, count);
	shift(lst_operations, stack_a, nbr_sorted + count);
}

void	sorting(t_list **lst_operations, t_stack *stack_a, t_stack *stack_b)
{
	indexing(stack_a);
	first_chunk(lst_operations, stack_a, stack_b);
	while (count_sorted(stack_a) < stack_a->size)
	{
		next_chunk(lst_operations, stack_a, stack_b);
	}
	align(lst_operations, stack_a);
}
