/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_run.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anorjen <anorjen@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/14 16:08:00 by anorjen           #+#    #+#             */
/*   Updated: 2020/02/14 17:04:47 by anorjen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check(t_stack *stack_a, t_stack *stack_b)
{
	t_element	*element1;
	t_element	*element2;
	int			size;

	if (stack_b && stack_b->size != 0)
		return (1);
	element1 = stack_a->elements;
	element1 = stack_a->elements->next;
	size = stack_a->size;
	while (size--)
	{
		if (element1 > element2)
			return (1);
		element1 = element2;
		element2 = element2->next;
	}
	return (0);
}

int	run(t_list *lst_operations, t_stack **stack_a, t_stack **stack_b)
{
	int	i;
	int	err;

	err = 1;
	while (lst_operations)
	{
		i = -1;
		while (g_operations[++i].name)
		{
			if (ft_strcmp(g_operations[i].name, lst_operations->content))
			{
				g_operations[i].operation(*stack_a, *stack_b);
				err = 0;
				break ;
			}
		}
		if (err)
			return(1);
		lst_operations = lst_operations->next;
	}
	return (0);
}
