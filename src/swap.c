/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jharras <jharras@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 14:58:08 by jharras           #+#    #+#             */
/*   Updated: 2022/02/09 15:20:30 by jharras          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_array *stack, int flag_write)
{
	int	tmp;

	tmp = stack->a[0];
	stack->a[0] = stack->a[1];
	stack->a[1] = tmp;
	if (flag_write == 1)
		write(1, "sa\n", 3);
}

void	sb(t_array *stack, int flag_write)
{
	int	tmp;

	tmp = stack->b[0];
	stack->b[0] = stack->b[1];
	stack->b[1] = tmp;
	if (flag_write == 0)
		write(1, "sb\n", 3);
}

void	ss(t_array *stack)
{
	sa(stack, 0);
	sb(stack, 0);
	write(1, "ss\n", 3);
}