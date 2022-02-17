/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jharras <jharras@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 12:53:24 by jharras           #+#    #+#             */
/*   Updated: 2022/02/17 15:48:08 by jharras          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

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

void	pa(t_stacks *stacks, int flag_write)
{
	free_space(stacks->a->arr, &stacks->a->size);
	stacks->a->arr[0] = stacks->b->arr[0];
	move_stack(stacks->b->arr, &stacks->b->size);
	if (flag_write == 1)
		write(1, "pa\n", 3);
}

void	pb(t_stacks *stacks, int flag_write)
{
	free_space(stacks->b->arr, &stacks->b->size);
	stacks->b->arr[0] = stacks->a->arr[0];
	move_stack(stacks->a->arr, &stacks->a->size);
	if (flag_write == 1)
		write(1, "pb\n", 3);
}
