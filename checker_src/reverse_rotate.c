/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jharras <jharras@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 15:37:22 by jharras           #+#    #+#             */
/*   Updated: 2022/02/17 15:48:31 by jharras          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	rra(t_array *stack, int flag_write)
{
	int	tmp;
	int	i;

	i = stack->size - 1;
	tmp = stack->arr[stack->size - 1];
	while (i >= 0)
	{
		stack->arr[i] = stack->arr[i - 1];
		i--;
	}
	stack->arr[0] = tmp;
	if (flag_write == 1)
		write(1, "rra\n", 4);
}

void	rrb(t_array *stack, int flag_write)
{
	int	tmp;
	int	i;

	i = stack->size - 1;
	tmp = stack->arr[stack->size - 1];
	while (i >= 0)
	{
		stack->arr[i] = stack->arr[i - 1];
		i--;
	}
	stack->arr[0] = tmp;
	if (flag_write == 1)
		write(1, "rrb\n", 4);
}

void	rrr(t_stacks *stacks, int flag_write)
{
	rra(stacks->a, 0);
	rrb(stacks->b, 0);
	if (flag_write == 1)
		write(1, "rrr\n", 1);
}
