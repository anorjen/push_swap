/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anorjen <anorjen@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/12 15:20:55 by anorjen           #+#    #+#             */
/*   Updated: 2020/02/12 18:37:27 by anorjen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_number(char *str, int *number)
{
	*number = ft_atoi(str);
	if (!(*number == 0 && (str[0] == '0' || (str[0] == '-' && str[1] == '0'))))
		return (1);
	return (0);
}

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
}

int	main(int ac, char **av)
{
	t_stack	*stack_a;
	t_list	*lst_operations;

	if (ac == 1)
		return (0);
	if (fill_stack(&stack_a, ac, av)
		|| fill_lst_operation(&lst_operations))
		write(2, "Error\n", 6);


	return (0);
}
