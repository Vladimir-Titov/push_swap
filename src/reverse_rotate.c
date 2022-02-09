/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jharras <jharras@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 15:37:22 by jharras           #+#    #+#             */
/*   Updated: 2022/02/09 15:48:01 by jharras          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rra(t_array *stack, int flag_write)
{
	int	tmp;
	int	i;

	i = 1;
	tmp = stack->a[stack->size_a - 1];
	while (i < stack->size_a)
	{
		stack->a[i] = stack->a[i - 1];
		i++;
	}
	stack->a[0] = tmp;
	if (flag_write == 1)
		write(1, "rra\n", 4);
}

void	rrb(t_array *stack, int flag_write)
{
	int	tmp;
	int	i;

	i = 1;
	tmp = stack->b[stack->size_b - 1];
	while (i < stack->size_b)
	{
		stack->b[i] = stack->b[i - 1];
		i++;
	}
	stack->b[0] = tmp;
	if (flag_write == 1)
		write(1, "rrb\n", 4);
}

void	rrr(t_array *stack)
{
	rra(stack, 0);
	rrb(stack, 0);
	write(1, "rrr\n", 1);
}
