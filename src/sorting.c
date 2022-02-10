/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jharras <jharras@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 13:55:28 by jharras           #+#    #+#             */
/*   Updated: 2022/02/10 14:49:02 by jharras          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	three_sort(t_array *stack)
{
	int	i;

	i = 0;
	if (stack->a[i] > stack->a[i + 1] && stack->a[i] > stack->a[i + 2])
	{
		ra(stack, 1);
		if (check_sort(stack->a, stack->size_a))
			return ;
		sa(stack, 1);
		return ;
	}
	if (stack->a[i] < stack->a[i + 1] && stack->a[i] > stack->a[i + 2])
	{
		rra(stack, 1);
		return ;
	}
	if (stack->a[i] > stack->a[i + 1] && stack->a[i] < stack->a[i + 2])
	{
		sa(stack, 1);
		return ;
	}
	rra(stack, 1);
	sa(stack, 1);
}

static void	six_sort(t_array *stack)
{
	while (stack->size_a > 3)
		pb(stack, 1);
	if (!check_sort(stack->a, stack->size_a))
		three_sort(stack);
	while (stack->size_b >= 0)
	{
		if (stack->a[0] > stack->b[0])
			pa(stack, 1);
		ra(stack, 1);
	}
}

void	sorting(t_array *stack)
{
	if (stack->size_a == 2)
		sa(stack, 1);
	else if (stack->size_a == 3)
		three_sort(stack);
	else if (stack->size_a <= 6)
		six_sort(stack);
}