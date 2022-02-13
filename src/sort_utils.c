/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jharras <jharras@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 14:50:08 by jharras           #+#    #+#             */
/*   Updated: 2022/02/13 15:56:09 by jharras          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_sort(t_array *stack)
{
	int	i;

	i = 0;
	while (i + 1 < stack->size)
	{
		if (stack->arr[i] > stack->arr[i + 1])
			return (0);
		i++;
	}
	return (1);
}

void	find_min(t_array *stack)
{
	int	i;

	i = 0;
	stack->min = stack->arr[0];
	while (i < stack->size)
	{
		if (stack->min > stack->arr[i])
			stack->min = stack->arr[i];
		i++;
	}
}

int	get_index(t_array *stack, int digit)
{
	int	i;

	i = 0;
	while (stack->arr[i] != digit)
		i++;
	return (i);
}
