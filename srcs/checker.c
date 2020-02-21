/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anorjen <anorjen@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/12 15:20:55 by anorjen           #+#    #+#             */
/*   Updated: 2020/02/20 12:01:11 by anorjen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// int	read_operations(t_list **lst_operations)
// {
// 	char	*line;
// 	int		status;

// 	line = NULL;
// 	while ((status = get_next_line(0, &line) == 1))
// 	{
// 		ft_lstadd(lst_operations, ft_lstnew(line, ft_strlen(line)));
// 	}
// 	// write(1, ft_itoa(status), ft_strlen(ft_itoa(status)));
// 	// write(1, "\n", 1);
// 	if (line)
// 		free(line);
// 	return (0);
// }

int	read_operations(t_list **lst_operations)
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
	t_list		*lst_operations;
	int			status;
	// int			size;
	// t_element	*elements;

	stack_a = new_stack();
	stack_b = new_stack();
	lst_operations = NULL;
	status = 0;
	if (ac == 1)
		return (0);
	if ((status = fill_stack(&stack_a, ac, av))
		|| (status = read_operations(&lst_operations))
		|| (status = run(lst_operations, &stack_a, &stack_b)))
		write(2, "Error\n", 6);
	else
	{
		// while (lst_operations)
		// {
		// 	write(1, lst_operations->content, lst_operations->content_size);
		// 	write(1, "\n", 1);
		// 	lst_operations = lst_operations->next;
		// }
		// size = stack_a->size;
		// elements = stack_a->elements;
		// while (size--)
		// {
		// 	write(1, ft_itoa(elements->value), ft_strlen(ft_itoa(elements->value)));
		// 	write(1, "\n", 1);
		// 	elements = elements->next;
		// }
		if (check(stack_a, stack_b))
			write(1, "KO\n", 3);
		else
			write(1, "OK\n", 3);
	}
	finish(lst_operations, stack_a, stack_b);
	return (status);
}
