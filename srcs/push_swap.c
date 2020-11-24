/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anorjen <anorjen@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/14 17:11:35 by anorjen           #+#    #+#             */
/*   Updated: 2020/11/24 11:23:32 by anorjen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	print(t_list *lst_operations)
{
	if (!lst_operations)
		return ;
	else
	{
		print(lst_operations->next);
		write(1, lst_operations->content, lst_operations->content_size);
		write(1, "\n", 1);
	}
}

int			main(int ac, char **av)
{
	int		status;
	t_stack	*stack_a;
	t_stack	*stack_b;

	stack_a = new_stack();
	stack_a->name = ft_strdup("a");
	stack_b = new_stack();
	stack_b->name = ft_strdup("b");
	g_lst_operations = (t_list**)malloc(sizeof(t_list*));
	*g_lst_operations = NULL;
	status = 0;
	if ((status = fill_stack(&stack_a, ac, av)))
		write(2, "Error\n", 6);
	else
	{
		sort(stack_a, stack_b);
		print(*g_lst_operations);
	}
	finish(g_lst_operations, stack_a, stack_b);
	return (status);
}
