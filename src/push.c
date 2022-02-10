/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jharras <jharras@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 12:53:24 by jharras           #+#    #+#             */
/*   Updated: 2022/02/10 14:23:00 by jharras          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	free_space(int *array, int *size)
{
	int	i;
	int	j;

	(*size)++;
	i = *size;
	j = i - 2;
	while (i > 0)
	{
		array[i - 1] = array[j];
		i--;
		j--;
	}
}

static void	move_stack(int *array, int *size)
{
	int	i;

	i = 0;
	while (i < *size)
	{
		array[i] = array[i + 1];
		i++;
	}
	(*size)--;
}

void	pa(t_array *stack, int flag_write)
{
	int	i;

	i = 0;
	free_space(stack->a, &stack->size_a);
	stack->a[0] = stack->b[0];
	move_stack(stack->b, &stack->size_b);
	if (flag_write)
		write(1, "pa\n", 3);
}

void	pb(t_array *stack, int flag_write)
{
	int	i;

	i = 0;
	free_space(stack->b, &stack->size_b);
	stack->b[0] = stack->a[0];
	move_stack(stack->a, &stack->size_a);
	if (flag_write)
		write(1, "pb\n", 3);
}