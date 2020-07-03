/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anorjen <anorjen@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/14 17:11:35 by anorjen           #+#    #+#             */
/*   Updated: 2020/07/03 18:20:30 by anorjen          ###   ########.fr       */
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
// static void	ops_del_elem(t_list **list)
// {
// 	t_list	*elem;
// 	t_list	*prev;
// 	t_list	*next;

// 	elem = (*list)->next;
// 	prev = *list;
// 	next = elem->next;
// 	prev->next = next;
// 	free(elem->content);
// 	free(elem);
// }

// static int	delete_excess(void)
// {
// 	t_list	*ops;
// 	int		counter;

// 	counter = 0;
// 	ops = *lst_operations;
// 	while (ops->next)
// 	{
// 		if ( (ft_strequ(ops->content, "ra") && ft_strequ(ops->next->content, "rb"))
// 			|| (ft_strequ(ops->content, "rb") && ft_strequ(ops->next->content, "ra")) )
// 		{
// 			free(ops->content);
// 			ops->content = ft_strdup("rr");
// 			ops->content_size = ft_strlen(ops->content);
// 			ops_del_elem(&ops);
// 			++counter;
// 		}
// 		else if ( (ft_strequ(ops->content, "rra") && ft_strequ(ops->next->content, "rrb"))
// 			|| (ft_strequ(ops->content, "rrb") && ft_strequ(ops->next->content, "rra")) )
// 		{
// 			free(ops->content);
// 			ops->content = ft_strdup("rrr");
// 			ops->content_size = ft_strlen(ops->content);
// 			ops_del_elem(&ops);
// 			++counter;
// 		}
// 		// else if ( (ft_strequ(ops->content, "rra") && ft_strequ(ops->next->content, "rrb"))
// 		// 	|| (ft_strequ(ops->content, "rrb") && ft_strequ(ops->next->content, "rra")) )
// 		// {
// 		// 	free(ops->content);
// 		// 	ops->content = ft_strdup("rrr");
// 		// 	ops->content_size = ft_strlen(ops->content);
// 		// 	ops_del_elem(&ops);
// 		// }
// 		ops = ops->next;
// 	}
// 	return (counter);
// }

int	main(int ac, char **av)
{
	int		status;
	t_stack	*stack_a;
	t_stack	*stack_b;
	// int		excess;
	// t_list	*lst_operations;

	stack_a = new_stack();
	stack_a->name = ft_strdup("a");
	stack_b = new_stack();
	stack_b->name = ft_strdup("b");
	lst_operations = (t_list**)malloc(sizeof(t_list*));
	*lst_operations = NULL;
	status = 0;
	if ((status = fill_stack(&stack_a, ac, av)))
		write(2, "Error\n", 6);
	else
	{
		sort(stack_a, stack_b);
		// excess = delete_excess();
		// write(2, "\n", 1);
		// write(2, "\n", 1);
		// write (2, ft_itoa(excess), ft_strlen(ft_itoa(excess)));
		// write(2, "\n", 1);
		// write(2, "\n", 1);
		print(*lst_operations);
	}
	finish(lst_operations, stack_a, stack_b);
	return (status);
}
