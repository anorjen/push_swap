/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anorjen <anorjen@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/17 12:31:39 by anorjen           #+#    #+#             */
/*   Updated: 2020/11/24 11:15:58 by anorjen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		*stack_to_array(t_stack *stack)
{
	t_element	*elements;
	int			size;
	int			*array;
	int			i;

	size = stack->size;
	array = (int*)malloc(sizeof(int) * size);
	elements = stack->elements;
	i = -1;
	while (++i < size)
	{
		array[i] = elements->value;
		elements = elements->next;
	}
	return (array);
}

void	array_sort(int *array, int size)
{
	int	i;
	int	buf;

	while (size)
	{
		i = -1;
		while (++i < size - 1)
		{
			if (array[i] > array[i + 1])
			{
				buf = array[i];
				array[i] = array[i + 1];
				array[i + 1] = buf;
			}
		}
		--size;
	}
}
