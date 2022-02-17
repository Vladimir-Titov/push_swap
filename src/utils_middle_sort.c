/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_middle_sort.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jharras <jharras@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 17:55:42 by jharras           #+#    #+#             */
/*   Updated: 2022/02/17 13:43:07 by jharras          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_less(t_array *stack, int less)
{
	int	i;

	i = 0;
	while (i < stack->size)
	{
		if (stack->arr[i] <= less)
			return (1);
		i++;
	}
	return (0);
}

int	get_digit_less(t_array *stack, int less)
{
	int	i;

	i = 0;
	while (i < stack->size)
	{
		if (stack->arr[i] <= less)
			return (stack->arr[i]);
		i++;
	}
	return (0);
}

int	find_max(t_array *stack)
{
	int	max;
	int	i;

	i = 0;
	max = stack->arr[0];
	while (stack->size > i)
	{
		if (stack->arr[i] > max)
			max = stack->arr[i];
		i++;
	}
	return (max);
}

int	val_aprox(float m)
{
	int	k;

	k = (int) m;
	if ((m - k) >= 0.5)
		return ((int) m + 1);
	else
		return ((int) m);
}

int	get_key(t_array *tmp)
{
	int	i;

	i = -1;
	quick_sort(tmp->arr, 0, tmp->size - 1);
	if (tmp->size <= 12)
		i = val_aprox(tmp->size / 2);
	else if (tmp->size > 12 && tmp->size < 200)
		i = val_aprox(tmp->size / 4);
	else
		i = val_aprox(tmp->size / 8);
	return (tmp->arr[i]);
}
