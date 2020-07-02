/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_sorting2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anorjen <anorjen@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/30 19:58:09 by anorjen           #+#    #+#             */
/*   Updated: 2020/07/03 00:48:55 by anorjen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
// #define CHUNK 11

int			get_chunk(int size)
{
	if (size > 0 && size <= 25)
	{
		return (1);
	}
	else if (size <= 100)
	{
		return (size / 25);
	}
	else if (size <= 500)
	{
		return (size / 50);
	}
	else
	{
		return (10);
	}

}

static void	align_b(t_list **lst_operations, t_stack *stack, char *sort)
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
	shift_b(lst_operations, stack, steps);
}

void	first_chunk(t_list **lst_operations, t_stack *stack_a, t_stack *stack_b)
{
	int	count;

	count = stack_a->size / get_chunk(stack_a->size);
	from_a_to_b(lst_operations, stack_a, stack_b, count, "desc");
	align_b(lst_operations, stack_b, "desc");
	move_b_to_a(lst_operations, stack_a, stack_b, count);
	shift_a(lst_operations, stack_a, count);
}

int		count_sorted(t_stack *stack)
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

void	next_chunk(t_list **lst_operations, t_stack *stack_a, t_stack *stack_b)
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
	from_a_to_b(lst_operations, stack_a, stack_b, count, "asc");
	align_b(lst_operations, stack_b, "asc");
	shift_a(lst_operations, stack_a, -nbr_sorted);
	merge(lst_operations, stack_a, stack_b, nbr_sorted, count);
	// shift_a(lst_operations, stack_a, nbr_sorted + count);
}

void	sorting(t_list **lst_operations, t_stack *stack_a, t_stack *stack_b)
{
	indexing(stack_a);
	first_chunk(lst_operations, stack_a, stack_b);
	while (count_sorted(stack_a) < stack_a->size)
	{
		next_chunk(lst_operations, stack_a, stack_b);
	}
	// align(lst_operations, stack_a);
}
