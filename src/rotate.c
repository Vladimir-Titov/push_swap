/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jharras <jharras@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 15:05:03 by jharras           #+#    #+#             */
/*   Updated: 2022/02/17 13:41:13 by jharras          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra(t_array *stack, int flag_write)
{
	int	tmp;
	int	i;

	i = 1;
	tmp = stack->arr[0];
	while (i < stack->size)
	{
		stack->arr[i - 1] = stack->arr[i];
		i++;
	}
	stack->arr[i - 1] = tmp;
	if (flag_write == 1)
		write(1, "ra\n", 3);
}

void	rb(t_array *stack, int flag_write)
{
	int	tmp;
	int	i;

	i = 1;
	tmp = stack->arr[0];
	while (i < stack->size)
	{
	stack->arr[i - 1] = stack->arr[i];
		i++;
	}
	stack->arr[i - 1] = tmp;
	if (flag_write == 1)
		write(1, "rb\n", 3);
}

void	rr(t_array *stack)
{
	ra(stack, 0);
	rb(stack, 0);
	write(1, "rr\n", 3);
}
