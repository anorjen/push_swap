/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anorjen <anorjen@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/12 15:20:55 by anorjen           #+#    #+#             */
/*   Updated: 2020/07/03 13:16:08 by anorjen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	read_operations(t_list **lst_operations)
{
	char	*line;
	int		status;

	line = NULL;

	if ((status = get_next_line(0, &line) != 1))
		return (0);
	read_operations(lst_operations);
	ft_lstadd(lst_operations, ft_lstnew(line, ft_strlen(line)));
	if (line)
		free(line);
	return (0);
}

int	main(int ac, char **av)
{
	t_stack		*stack_a;
	t_stack		*stack_b;
	// t_list		*lst_operations;
	int			status;

	stack_a = new_stack();
	stack_b = new_stack();
	lst_operations = (t_list**)malloc(sizeof(t_list*));
	*lst_operations = NULL;
	status = 0;
	if (ac == 1)
		return (0);
	if ((status = fill_stack(&stack_a, ac, av))
		|| (status = read_operations(lst_operations))
		|| (status = run(*lst_operations, &stack_a, &stack_b)))
		write(2, "Error\n", 6);
	else
	{
		if (check(stack_a, stack_b))
			write(1, "KO\n", 3);
		else
			write(1, "OK\n", 3);
	}
	finish(lst_operations, stack_a, stack_b);
	return (status);
}
