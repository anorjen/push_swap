/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_shift.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anorjen <anorjen@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/02 19:06:54 by anorjen           #+#    #+#             */
/*   Updated: 2020/07/03 16:43:41 by anorjen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	shift(t_stack *stack, int count)
{
	int	i;

	i = (count >= 0 ? count : -count);
	while (i > 0)
	{
		if (count < 0)
		{
			rrotate_elements(stack);
			logger(stack, "rr");
		}
		else
		{
			rotate_elements(stack);
			logger(stack, "r");
		}
		--i;
	}
}

void	from_a_to_b(t_stack *stack_a, t_stack *stack_b, int size, char *sort)
{
	int	i;
	int	count;

	i = -1;
	while (++i < size)
	{
		if (i >= 2)
		{
			count = find_place(stack_b, stack_a->elements->index, sort);
			shift(stack_b, count);
		}
		pb(stack_a, stack_b);
		logger(stack_b, "p");
	}
}

void	move_b_to_a(t_stack *stack_a, t_stack *stack_b, int count)
{
	int	i;

	i = -1;
	while (++i < count)
	{
		stack_b->elements->is_sorted = 1;
		pa(stack_a, stack_b);
		logger(stack_a, "p");
	}
}

void	merge(t_stack *stack_a, t_stack *stack_b, int sorted)
{
	int	i;

	i = 0;
	while (stack_b->size > 0 || i < sorted)
	{
		if (stack_b->size > 0 && (stack_a->elements->index > stack_b->elements->index
			|| i == sorted))
		{
			stack_b->elements->is_sorted = 1;
			pa(stack_a, stack_b);
			logger(stack_a, "p");
			ra(stack_a, stack_b);
			logger(stack_a, "r");
		}
		else
		{
			ra(stack_a, stack_b);
			logger(stack_a, "r");
			++i;
		}
	}
}
