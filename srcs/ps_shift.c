/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_shift.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anorjen <anorjen@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/02 19:06:54 by anorjen           #+#    #+#             */
/*   Updated: 2020/07/02 22:55:10 by anorjen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	shift_a(t_list **lst_operations, t_stack *stack, int count)
{
	int	i;

	i = (count >= 0 ? count : -count);
	while (i > 0)
	{
		if (count < 0)
		{
			rrotate_elements(stack);
			ft_lstadd(lst_operations, ft_lstnew("rra", 3));
		}
		else
		{
			rotate_elements(stack);
			ft_lstadd(lst_operations, ft_lstnew("ra", 2));
		}
		--i;
	}
}

void	shift_b(t_list **lst_operations, t_stack *stack, int count)
{
	int	i;

	i = (count >= 0 ? count : -count);
	while (i > 0)
	{
		if (count < 0)
		{
			rrotate_elements(stack);
			ft_lstadd(lst_operations, ft_lstnew("rrb", 3));
		}
		else
		{
			rotate_elements(stack);
			ft_lstadd(lst_operations, ft_lstnew("rb", 2));
		}
		--i;
	}
}

static int		find_place(t_stack *stack, int index, char *sort)
{
	int			i;
	int			steps;
	t_element	*element;

	steps = 0;
	element = stack->elements;
	if (is_max_index(stack, index) || is_min_index(stack, index))
	{
		if (ft_strcmp(sort, "asc") == 0)
		{
			steps = to_index(stack, get_min_index(stack));
		}
		else if (ft_strcmp(sort, "desc") == 0)
		{
			steps = to_index(stack, get_max_index(stack));
		}
	}
	else
	{
		i = -1;
		while (++i < stack->size)
		{
			if ( ((ft_strcmp(sort, "asc") == 0 && element->index > index && element->prev->index < index))
				|| (ft_strcmp(sort, "desc") == 0 && element->index < index && element->prev->index > index) )
			{
				break ;
			}
			++steps;
			element = element->next;
		}
	}
	return (steps <= stack->size / 2 ? steps : -(stack->size - steps));
}

void	from_a_to_b(t_list **lst_operations, t_stack *stack_a, t_stack *stack_b, int size, char *sort)
{
	int	i;
	int	count;

	i = -1;
	while (++i < size)
	{
		if (i < 2)
		{
			pb(stack_a, stack_b);
			ft_lstadd(lst_operations, ft_lstnew("pb", 2));
		}
		else
		{
			count = find_place(stack_b, stack_a->elements->index, sort);
			shift_b(lst_operations, stack_b, count);
			pb(stack_a, stack_b);
			ft_lstadd(lst_operations, ft_lstnew("pb", 2));
		}
	}
}

void	move_b_to_a(t_list **lst_operations, t_stack *stack_a, t_stack *stack_b, int count)
{
	int	i;

	i = -1;
	while (++i < count)
	{
		stack_b->elements->is_sorted = 1;
		pa(stack_a, stack_b);
		ft_lstadd(lst_operations, ft_lstnew("pa", 2));
	}
}

void	merge(t_list **lst_operations, t_stack *stack_a, t_stack *stack_b, int sorted, int count)
{
	int	i;

	i = 0;
	(void)count;
	while (stack_b->size > 0 || i < sorted)
	{
		if (stack_b->size > 0 && (stack_a->elements->index > stack_b->elements->index
			|| i == sorted))
		{
			stack_b->elements->is_sorted = 1;
			pa(stack_a, stack_b);
			ft_lstadd(lst_operations, ft_lstnew("pa", 2));
			ra(stack_a, stack_b);
			ft_lstadd(lst_operations, ft_lstnew("ra", 2));
		}
		else
		{
			ra(stack_a, stack_b);
			ft_lstadd(lst_operations, ft_lstnew("ra", 2));
			++i;
		}
	}
}
