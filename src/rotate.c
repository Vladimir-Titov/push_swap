/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jharras <jharras@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 15:05:03 by jharras           #+#    #+#             */
/*   Updated: 2022/02/09 15:27:40 by jharras          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra(t_array *stack, int flag_write)
{
	int	tmp;
	int	i;

	i = 1;
	tmp = stack->a[0];
	while (i < stack->size_a)
	{
		stack->a[i - 1] = stack->a[i];
		i++;
	}
	stack->a[i - 1] = tmp;
	if (flag_write == 1)
		write(1, "ra\n", 3);
}

void	rb(t_array *stack, int flag_write)
{
	int	tmp;
	int	i;

	i = 1;
	tmp = stack->b[0];
	while (i < stack->size_b)
	{
		stack->b[i - 1] = stack->b[i];
		i++;
	}
	stack->b[i - 1] = tmp;
	if (flag_write == 1)
		write(1, "rb\n", 3);
}

void	rr(t_array *stack)
{
	ra(stack, 0);
	rb(stack, 0);
	write(1, "rr\n", 3);
}
