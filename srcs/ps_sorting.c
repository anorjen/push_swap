/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_sorting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anorjen <anorjen@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/17 12:17:26 by anorjen           #+#    #+#             */
/*   Updated: 2020/02/19 18:59:57 by anorjen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	indexing(t_stack *stack_a)
{
	int			*array;
	int			i;
	int			j;
	t_element	*tmp;

	array = stack_to_array(stack_a);
	array_sort(array, stack_a->size);
	i = -1;
	while (++i < stack_a->size)
	{
		j = 0;
		tmp = stack_a->elements;
		while (j < stack_a->size)
		{
			if (tmp->value == array[i])
				tmp->index = i;
			tmp = tmp->next;
			++j;
		}
	}
	free(array);
}

void	mark(t_element *head, int size)
{
	int			i;
	int			index;
	t_element	*cur;

	index = head->index;
	head->is_a = 1;
	i = 0;
	cur = head->next;
	while (++i < size)
	{
		if (cur->index != index + 1)
			cur->is_a = 0;
		else
		{
			cur->is_a = 1;
			index = cur->index;
		}
		cur = cur->next;
	}
}

int		count_marked(t_element *head, int size)
{
	int			j;
	int			marked;
	int			index;
	t_element	*cur;

	j = 0;
	marked = 0;
	cur = head->next;
	index = head->index;
	while (++j < size)
	{
		if (cur->index != index + 1)
			++marked;
		else
			++index;
		cur = cur->next;
	}
	return (marked);
}

void	markup(t_stack *stack_a)
{
	t_element	*cur;
	t_element	*head;
	int			i;
	int			head_marked;
	int			marked;

	cur = stack_a->elements;
	head = NULL;
	i = -1;
	while (++i < stack_a->size)
	{
		marked = count_marked(cur, stack_a->size);
		if (!head || head_marked > marked)
		{
			head = cur;
			head_marked = marked;
		}
		cur = cur->next;
	}
	stack_a->marked = head_marked;
	mark(head, stack_a->size);
}

void	from_a_to_b(t_list **lst_operations, t_stack *stack_a, t_stack *stack_b)
{
	int	size;
	int	i;

	size = stack_a->size;
	i = -1;
	while (++i < size)
	{
		if (stack_a->elements->is_a == 0)
		{
			pb(stack_a, stack_b);
			ft_lstadd(lst_operations, ft_lstnew("pb", 2));
		}
		else
		{
			ra(stack_a, stack_b);
			ft_lstadd(lst_operations, ft_lstnew("ra", 2));
		}
	}
}

int		rotate_counter(int index, t_stack *stack, int *direction)
{
	t_element	*elements;
	int			counter;
	int			i;

	counter = 0;
	elements = stack->elements;
	i = -1;
	while (++i < stack->size)
	{
		if (elements->index != index)
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
	// int	size_a;
	// int	size_b;
	int	rcount_a;
	int	rcount_b;
	int	direction_a;
	int	direction_b;
	// int	i;

	while (stack_b && stack_b->size > 0)
	{
		rcount_a = rotate_counter(stack_b->elements->index + 1, stack_a, &direction_a);
		rcount_b = rotate_counter(stack_a->elements->index - 1, stack_b, &direction_b);
		if (rcount_a == -1 && rcount_b == -1)
		{
			ra(stack_a, stack_b);
			ft_lstadd(lst_operations, ft_lstnew("ra", 2));
			continue ;
		}
		if (rcount_b == -1 || (rcount_a != -1 && rcount_a < rcount_b))
		{
			while (rcount_a)
			{
				if (!direction_a)
				{
					ra(stack_a, stack_b);
					ft_lstadd(lst_operations, ft_lstnew("ra", 2));
				}
				else
				{
					rra(stack_a, stack_b);
					ft_lstadd(lst_operations, ft_lstnew("rra", 3));
				}
				--rcount_a;
			}
			pa(stack_a, stack_b);
			ft_lstadd(lst_operations, ft_lstnew("pa", 2));
		}
		else if (rcount_a == -1 || (rcount_b != -1 && rcount_b < rcount_a))
		{
			while (rcount_b)
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
		}
	}
}

void	to_align(t_list **lst_operations, t_stack *stack_a, t_stack *stack_b)
{
	t_element	*first;
	int			i;

	(void)stack_b;
	first = stack_a->elements;
	i = 0;
	while (first->index != 0 && i < stack_a->size)
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
	if (stack_a->marked > 0)
	{
		from_a_to_b(lst_operations, stack_a, stack_b);
		from_b_to_a(lst_operations, stack_a, stack_b);
	}
	to_align(lst_operations, stack_a, stack_b);
}
