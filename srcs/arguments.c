/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arguments.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anorjen <anorjen@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/14 17:19:30 by anorjen           #+#    #+#             */
/*   Updated: 2020/02/17 12:22:39 by anorjen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_list(t_list *lst_operations)
{
	t_list	*tmp;

	while (lst_operations)
	{
		tmp = lst_operations->next;
		free(lst_operations->content);
		free(lst_operations);
		lst_operations = tmp;
	}
}

void	finish(t_list *lst_operations, t_stack *stack_a, t_stack *stack_b)
{
	free_stack(stack_a);
	free_stack(stack_b);
	free_list(lst_operations);
}

int	check_number(char *str, int *number)
{
	*number = ft_atoi(str);
	if (!(*number == 0 && (str[0] == '0' || (str[0] == '-' && str[1] == '0'))))
		return (1);
	return (0);
}

//todo добавить проверку на уникальность

int	fill_stack(t_stack **stack, int ac, char **av)
{
	int	i;
	int	number;

	i = ac;
	while (--i >= 0)
	{
		if (check_number(av[i], &number))
		{
			free_stack(*stack);
			return (1);
		}
		*stack = add_element(*stack, new_element(number));
	}
	return (0);
}
