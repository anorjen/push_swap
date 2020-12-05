/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   merge_sort_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anorjen <anorjen@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/23 17:33:43 by anorjen           #+#    #+#             */
/*   Updated: 2020/11/23 18:44:07 by anorjen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	mark(t_element *head, int size)
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
		if (cur->index > index)
		{
			cur->is_a = 1;
			index = cur->index;
		}
		cur = cur->next;
	}
}

static int	count_marked(t_element *head, int size)
{
	int			j;
	int			marked;
	int			index;
	t_element	*cur;

	j = 0;
	marked = 1;
	cur = head->next;
	index = head->index;
	while (++j < size)
	{
		if (cur->index > index)
		{
			++marked;
			index = cur->index;
		}
		cur = cur->next;
	}
	return (marked);
}

void		marker(t_stack *stack, int size)
{
	t_element	*cur;
	t_element	*head;
	int			head_marked;
	int			marked;
	int			head_size;

	cur = stack->elements;
	head = NULL;
	head_marked = 0;
	head_size = 0;
	size += 1;
	while (--size)
	{
		marked = count_marked(cur, size);
		if (!head || head_marked < marked)
		{
			head = cur;
			head_size = size;
			head_marked = marked;
		}
		cur = cur->next;
	}
	stack->marked = head_marked;
	mark(head, head_size);
}
