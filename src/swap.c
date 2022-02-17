/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jharras <jharras@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 14:58:08 by jharras           #+#    #+#             */
/*   Updated: 2022/02/17 15:05:13 by jharras          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_array *stack, int flag_write)
{
	int	tmp;

	tmp = stack->arr[0];
	stack->arr[0] = stack->arr[1];
	stack->arr[1] = tmp;
	if (flag_write == 1)
		write(1, "sa\n", 3);
}

void	sb(t_array *stack, int flag_write)
{
	int	tmp;

	tmp = stack->arr[0];
	stack->arr[0] = stack->arr[1];
	stack->arr[1] = tmp;
	if (flag_write == 1)
		write(1, "sb\n", 3);
}

void	ss(t_stacks *stacks, int flag_write)
{
	sa(stacks->a, 0);
	sb(stacks->b, 0);
	if (flag_write == 1)
		write(1, "ss\n", 3);
}
