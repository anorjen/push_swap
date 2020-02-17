/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_sorting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anorjen <anorjen@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/17 12:17:26 by anorjen           #+#    #+#             */
/*   Updated: 2020/02/17 14:38:11 by anorjen          ###   ########.fr       */
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
			ft_lstadd(lst_operations, ft_lstnew("pb", 3));
		}
		else
		{
			ra(stack_a, stack_b);
			ft_lstadd(lst_operations, ft_lstnew("ra", 3));
		}
	}
}

void	sorting(t_list **lst_operations, t_stack *stack_a, t_stack *stack_b)
{
	indexing(stack_a);
	markup(stack_a);
	from_a_to_b(lst_operations, stack_a, stack_b);
	from_b_to_a(lst_operations, stack_a, stack_b);
	to_align(lst_operations, stack_a);
}
