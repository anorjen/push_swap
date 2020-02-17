/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anorjen <anorjen@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/14 17:11:35 by anorjen           #+#    #+#             */
/*   Updated: 2020/02/17 12:28:57 by anorjen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print(t_list *lst_operations)
{
	while (lst_operations)
	{
		write(1, lst_operations->content, lst_operations->content_size);
		write(1, "\n", 1);
	}
}

int	main(int ac, char **av)
{
	int		status;
	t_stack	*stack_a;
	t_stack	*stack_b;
	t_list	*lst_operations;

	stack_a = NULL;
	stack_b = NULL;
	lst_operations = NULL;
	status = 0;
	if ((status = fill_stack(&stack_a, ac, av)))
		write(2, "Error\n", 6);
	else
	{
		sorting(&lst_operations, stack_a, stack_b);
		print(lst_operations);
	}
	finish(lst_operations, stack_a, stack_b);
	return (status);
}