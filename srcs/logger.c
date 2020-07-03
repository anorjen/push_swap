/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   logger.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anorjen <anorjen@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/03 12:58:27 by anorjen           #+#    #+#             */
/*   Updated: 2020/07/03 12:58:48 by anorjen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	logger(t_stack *stack, char *type)
{
	char	*op;

	op = ft_strjoin(type, stack->name);
	ft_lstadd(lst_operations, ft_lstnew(op, ft_strlen(op)));
	free(op);
}
