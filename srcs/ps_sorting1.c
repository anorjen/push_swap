/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_sorting1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anorjen <anorjen@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/17 12:17:26 by anorjen           #+#    #+#             */
/*   Updated: 2020/06/30 20:08:53 by anorjen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		number_of_marked(t_stack *stack)
{
	int			size;
	t_element	*elements;
	int			nbr;

	size = stack->size;
	elements = stack->elements;
	nbr = 0;
	while (size--)
	{
		if (elements->is_a == 0)
			++nbr;
		elements = elements->next;
	}
	return (nbr);
}

int		is_need_sa(t_stack *stack_a, t_stack *stack_b)
{
	int		old_marked;
	int		new_marked;
	t_stack	*copy;

	copy = copy_stack(stack_a);
	old_marked = number_of_marked(copy);
	sa(copy, stack_b);
	markup(copy);
	new_marked = number_of_marked(copy);
	// sa(copy, stack_b);
	// markup(stack_a);
	free_stack(copy);
	if (new_marked < old_marked)
		return (1);
	return (0);
}

int		rotate_ra_or_rra(t_stack *stack, int *direction)
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
	*direction = (rra_counter < ra_counter ? 1 : 0);
	return (rra_counter < ra_counter ? rra_counter : ra_counter);
}

void	from_a_to_b(t_list **lst_operations, t_stack *stack_a, t_stack *stack_b)
{
	int	size;
	int	i;
	int	direction;
	int	count;

	size = stack_a->size;
	i = -1;
	while (number_of_marked(stack_a))
	{
		if (is_need_sa(stack_a, stack_b))
		{
			sa(stack_a, stack_b);
			ft_lstadd(lst_operations, ft_lstnew("sa", 2));
			markup(stack_a);
			// size = stack_a->size;
			// i = -1;
		}
		else if (stack_a->elements->is_a == 0)
		{
			pb(stack_a, stack_b);
			ft_lstadd(lst_operations, ft_lstnew("pb", 2));
			// write(1, "pb\n", 3);
		}
		else
		{
			count = rotate_ra_or_rra(stack_a, &direction);
			while (count--)
			{
				if (direction)
				{
					rra(stack_a, stack_b);
					ft_lstadd(lst_operations, ft_lstnew("rra", 3));
					// write(1, "rra\n", 4);
				}
				else
				{
					ra(stack_a, stack_b);
					ft_lstadd(lst_operations, ft_lstnew("ra", 2));
					// write(1, "ra\n", 3);
				}
			}
		}
	}
}

int		rotate_counter_a(int index, t_stack *stack, int *direction)
{
	t_element	*elements;
	int			counter;
	int			i;

	counter = 0;
	elements = stack->elements;
	i = -1;
	while (++i < stack->size)
	{
		if (elements->index != index + 1 && elements->prev->index != index - 1)
			++counter;
		else
		{
			*direction = (counter > stack->size / 2 ? 1 : 0);
			return (*direction == 1 ? stack->size - counter : counter);
		}
		elements = elements->next;
	}
	return (-1);

}

int		rotate_counter_b(int index, int prev_index, t_stack *stack, int *direction)
{
	t_element	*elements;
	t_element	*one;
	t_element	*two;
	int			counter;
	int			i;

	one = NULL;
	two = NULL;
	counter = 0;
	elements = stack->elements;
	i = -1;
	while (++i < stack->size)
	{
		if (elements->index == index - 1 || elements->index == prev_index + 1)
		{
			if (!one)
			{
				one = elements;
				one->direction = (counter > stack->size / 2 ? 1 : 0);
				one->rcounter = (one->direction == 1 ? stack->size - counter : counter);
			}
			else
			{
				two = elements;
				two->direction = (counter > stack->size / 2 ? 1 : 0);
				two->rcounter = (two->direction == 1 ? stack->size - counter : counter);
			}
		}
		elements = elements->next;
		++counter;
	}
	if (!one && !two)
		return (-1);
	if (!two)
	{
		*direction = one->direction;
		return (one->rcounter);
	}
	*direction = (one->rcounter <= two->rcounter ? one->direction : two->direction);
	return (one->rcounter <= two->rcounter ? one->rcounter : two->rcounter);


}

// int		rotate_counter(int index, t_stack *stack, int *direction)
// {
// 	t_element	*elements;
// 	int			counter;
// 	int			i;

// 	counter = 0;
// 	elements = stack->elements;
// 	i = -1;
// 	while (++i < stack->size)
// 	{
// 		if (elements->index != index)
// 			++counter;
// 		else
// 		{
// 			*direction = (counter > stack->size / 2 ? 1 : 0);
// 			return (*direction == 1 ? stack->size - counter : counter);
// 		}
// 		elements = elements->next;
// 	}
// 	return (-1);

// }

// void	rotate_stack(t_list *lst_operations, t_stack *stack, int direction, int counts)
// {
// 	while (counts)
// 	{
// 		if (!direction_a)
// 		{
// 			ra(stack_a, stack_b);
// 			ft_lstadd(lst_operations, ft_lstnew("ra", 3));
// 		}
// 		else
// 		{
// 			rra(stack_a, stack_b);
// 			ft_lstadd(lst_operations, ft_lstnew("rra", 4));
// 		}
// 		--counts;
// 	}
// }

void	from_b_to_a(t_list **lst_operations, t_stack *stack_a, t_stack *stack_b)
{
	// int	rcount_a;
	int	rcount_b;
	// int	direction_a;
	int	direction_b;

	while (stack_b && stack_b->size > 0)
	{
		rcount_b = rotate_counter_b(stack_a->elements->index, stack_a->elements->prev->index, stack_b, &direction_b);
		while (rcount_b > 0)
		{
			if (!direction_b)
			{
				rb(stack_a, stack_b);
				ft_lstadd(lst_operations, ft_lstnew("rb", 2));
			}
			else
			{
				rrb(stack_a, stack_b);
				ft_lstadd(lst_operations, ft_lstnew("rrb", 3));
			}
			--rcount_b;
		}
		pa(stack_a, stack_b);
		ft_lstadd(lst_operations, ft_lstnew("pa", 2));
		if (stack_a->elements->index == stack_a->elements->prev->index + 1)
		{
			ra(stack_a, stack_b);
			ft_lstadd(lst_operations, ft_lstnew("ra", 2));
		}
	}
}

void	to_align(t_list **lst_operations, t_stack *stack_a, t_stack *stack_b)
{
	t_element	*first;
	int			min_index;
	int			i;

	(void)stack_b;
	first = stack_a->elements;
	min_index = first->index;
	i = -1;
	while (++i < stack_a->size)
	{
		if (first->index < min_index)
			min_index = first->index;
		first = first->next;

	}
	i = 0;
	first = stack_a->elements;
	while (first->index != min_index && i < stack_a->size)
	{
		first = first->next;
		++i;
	}
	if (i < stack_a->size / 2)
	{
		while (i)
		{
			ra(stack_a, stack_b);
			ft_lstadd(lst_operations, ft_lstnew("ra", 2));
			--i;
		}
	}
	else
	{
		i = stack_a->size - i;
		while (i)
		{
			rra(stack_a, stack_b);
			ft_lstadd(lst_operations, ft_lstnew("rra", 3));
			--i;
		}
	}
}

void	sorting(t_list **lst_operations, t_stack *stack_a, t_stack *stack_b)
{
	indexing(stack_a);
	markup(stack_a);
	// if (stack_a->marked > 0)
	// {
		from_a_to_b(lst_operations, stack_a, stack_b);
		to_align(lst_operations, stack_a, stack_b);
		from_b_to_a(lst_operations, stack_a, stack_b);
	// }
	to_align(lst_operations, stack_a, stack_b);
}
