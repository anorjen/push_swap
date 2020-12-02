/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anorjen <anorjen@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/12 15:20:55 by anorjen           #+#    #+#             */
/*   Updated: 2020/12/02 10:06:08 by anorjen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

extern t_operation	g_operations[];

static int			check_operation(char *op)
{
	int	i;

	if (op != NULL)
	{
		i = -1;
		while (g_operations[++i].name)
		{
			if (ft_strequ(g_operations[i].name, op))
				return (0);
		}
	}
	return (1);
}

static int			check_operations(t_list *lst_operations)
{
	t_list	*tmp;
	char	*op;

	if (lst_operations != NULL)
	{
		tmp = lst_operations;
		while (tmp)
		{
			op = (char*)tmp->content;
			if (check_operation(op) == 1)
				return (1);
			tmp = tmp->next;
		}
	}
	return (0);
}

static int			read_operations(t_list **lst_operations)
{
	char	*line;
	int		status;

	line = NULL;
	if ((status = get_next_line(0, &line)) != 1)
		return (0);
	read_operations(lst_operations);
	ft_lstadd(lst_operations, ft_lstnew(line, ft_strlen(line)));
	if (line)
		free(line);
	return (0);
}

int					main(int ac, char **av)
{
	t_stack		*stack_a;
	t_stack		*stack_b;
	int			status;

	stack_a = new_stack();
	stack_b = new_stack();
	g_lst_operations = (t_list**)malloc(sizeof(t_list*));
	*g_lst_operations = NULL;
	status = 0;
	if (ac == 1)
		return (0);
	if ((status = fill_stack(&stack_a, ac, av))
		|| (status = read_operations(g_lst_operations))
		|| (status = check_operations(*g_lst_operations))
		|| (status = run(*g_lst_operations, &stack_a, &stack_b)))
		write(2, "Error\n", 6);
	else
	{
		if (check(stack_a, stack_b))
			write(1, "KO\n", 3);
		else
			write(1, "OK\n", 3);
	}
	finish(g_lst_operations, stack_a, stack_b);
	return (status);
}
