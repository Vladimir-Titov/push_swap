/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jharras <jharras@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 14:58:08 by jharras           #+#    #+#             */
/*   Updated: 2022/02/17 13:41:51 by jharras          ###   ########.fr       */
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

void	ss(t_array *stack)
{
	sa(stack, 0);
	sb(stack, 0);
	write(1, "ss\n", 3);
}
