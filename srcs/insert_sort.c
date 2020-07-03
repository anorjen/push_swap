/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insert_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anorjen <anorjen@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/17 12:17:26 by anorjen           #+#    #+#             */
/*   Updated: 2020/07/03 16:30:31 by anorjen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	is_need_sa(t_stack *stack_a, t_stack *stack_b)
{
	int		old_marked;
	int		new_marked;
	t_stack	*copy;

	copy = copy_stack(stack_a);
	old_marked = number_of_marked(copy);
	sa(copy, stack_b);
	markup(copy);
	new_marked = number_of_marked(copy);
	free_stack(copy);
	if (new_marked < old_marked)
		return (1);
	return (0);
}

static void	is_from_a_to_b(t_stack *stack_a, t_stack *stack_b)
{
	int	size;
	int	i;

	size = stack_a->size;
	i = -1;
	while (number_of_marked(stack_a))
	{
		if (is_need_sa(stack_a, stack_b))
		{
			sa(stack_a, stack_b);
			logger(stack_a, "s");
			markup(stack_a);
		}
		else if (stack_a->elements->is_a == 0)
		{
			pb(stack_a, stack_b);
			logger(stack_b, "p");
		}
		else
		{
			shift(stack_a, rotate_ra_or_rra(stack_a));
		}
	}
}

static void	is_from_b_to_a(t_stack *stack_a, t_stack *stack_b)
{
	int	count;

	while (stack_b && stack_b->size > 0)
	{
		count = rotate_counter_b(stack_a->elements->index, stack_a->elements->prev->index, stack_b);
		shift(stack_b, count);
		pa(stack_a, stack_b);
		logger(stack_a, "p");
		if (stack_a->elements->index == stack_a->elements->prev->index + 1)
		{
			ra(stack_a, stack_b);
			logger(stack_a, "r");
		}
	}
}

void		insert_sort(t_stack *stack_a, t_stack *stack_b)
{
	indexing(stack_a);
	markup(stack_a);
	is_from_a_to_b(stack_a, stack_b);
	align(stack_a, "asc");
	is_from_b_to_a(stack_a, stack_b);
	align(stack_a, "asc");
}
