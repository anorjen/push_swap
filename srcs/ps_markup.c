/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_mark.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anorjen <anorjen@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/30 20:04:36 by anorjen           #+#    #+#             */
/*   Updated: 2020/06/30 20:07:32 by anorjen          ###   ########.fr       */
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

static int		count_marked(t_element *head, int size)
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
	head_marked = stack_a->size;
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
	// write(1, ft_itoa(head->index), ft_strlen(ft_itoa(head->index)));
	// write(1, "\n", 1);
	mark(head, stack_a->size);
}
