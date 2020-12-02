/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ch_run.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anorjen <anorjen@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/14 16:08:00 by anorjen           #+#    #+#             */
/*   Updated: 2020/12/01 18:42:24 by anorjen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_operation			g_operations[] = {
	{"sa", sa},
	{"sb", sb},
	{"ss", ss},
	{"pa", pa},
	{"pb", pb},
	{"ra", ra},
	{"rb", rb},
	{"rr", rr},
	{"rra", rra},
	{"rrb", rrb},
	{"rrr", rrr},
	{NULL, NULL}
};

int		check(t_stack *stack_a, t_stack *stack_b)
{
	t_element	*element1;
	t_element	*element2;
	int			size;

	if (stack_b && stack_b->size != 0)
		return (1);
	element1 = stack_a->elements;
	element2 = stack_a->elements->next;
	size = stack_a->size;
	while (--size)
	{
		if (element1->value > element2->value)
			return (1);
		element1 = element2;
		element2 = element2->next;
	}
	return (0);
}

void	print_stack(char *name, t_stack *stack)
{
	int			size;
	t_element	*elements;

	write(1, name, ft_strlen(name));
	if (stack)
	{
		size = stack->size;
		elements = stack->elements;
		while (size--)
		{
			write(1, ft_itoa(elements->value),
							ft_strlen(ft_itoa(elements->value)));
			write(1, "  ", 2);
			elements = elements->next;
		}
	}
	write(1, "\n", 1);
}

void	viewer(char *op, t_stack *stack_a, t_stack *stack_b)
{
	write(1, op, ft_strlen(op));
	write(1, "\n", 1);
	print_stack("a:  ", stack_a);
	print_stack("b:  ", stack_b);
	write(1, "\n\n", 2);
}

int		run(t_list *lst_operations, t_stack **stack_a, t_stack **stack_b)
{
	int	i;
	int	err;

	err = 1;
	if (DEBUG)
		viewer("start", *stack_a, *stack_b);
	while (lst_operations)
	{
		i = -1;
		while (g_operations[++i].name)
		{
			if (ft_strcmp(g_operations[i].name, lst_operations->content) == 0)
			{
				g_operations[i].operation(*stack_a, *stack_b);
				err = 0;
				if (DEBUG)
					viewer(g_operations[i].name, *stack_a, *stack_b);
				break ;
			}
		}
		if (err)
			return (1);
		lst_operations = lst_operations->next;
	}
	return (0);
}
