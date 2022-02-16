/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   middle_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jharras <jharras@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/13 17:40:31 by jharras           #+#    #+#             */
/*   Updated: 2022/02/16 17:43:41 by jharras          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// static void printArray(int *array, int size)
// {
//   for (int i = 0; i < size; i++) {
//     printf("%d  ", array[i]);
//   }
//   printf("\n");
// }

static t_array *init_tmp(t_array *tmp, int size)
{
	tmp = (t_array *)malloc(sizeof(t_array));
	if (!tmp)
		error_msg_and_exit();
	tmp->arr = (int *)malloc(sizeof(int *) * size);
	if (!tmp->arr)
		error_msg_and_exit();
	tmp->size = size;
	return (tmp);
}

static void	arr_cpy(int *dest, int *src, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		dest[i] = src[i];
		i++;
	}
}

static int	check_and_swap(t_stacks *stacks, int key)
{
	int	middle;
	int	index_key;
	int	i;
	int	less;

	i = 0;
	while (find_less(stacks->a, key))
	{
		less = get_digit_less(stacks->a, key);
		index_key = get_index(stacks->a, less);
		middle = (stacks->a->size) / 2;
		if (index_key <= middle)
		{
			while (index_key-- > 0)
				ra(stacks->a, 1);
		}
		else
		{
			while (index_key-- > stacks->a->size)
				rra(stacks->a, 1);
		}
		pb(stacks);
		i++;
	}
	return (-1);
}

static void	end_sort(t_stacks *stacks)
{
	int	max;
	int	index_max;
	int	middle;

	while (stacks->b->size > 0)
	{
		max = find_max(stacks->b);
		index_max = get_index(stacks->b, max);
		middle = (stacks->b->size) / 2;
		if (index_max <= middle)
		{
			while (index_max-- > 0)
				rb(stacks->b, 1);
		}
		else
		{
			while (index_max++ < stacks->b->size)
				rrb(stacks->b, 1);
		}
		pa(stacks);
		max = find_max(stacks->b);
	}
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
	quick_sort(tmp->arr, 0, tmp->size - 1);
	if (tmp->size <= 12)
		i = val_aprox(tmp->size / 2);
	else if (tmp->size > 12 && tmp->size < 200)
		i = val_aprox(tmp->size / 4);
	else if (tmp->size >= 200)
		i = val_aprox(tmp->size / 8);
	return (tmp->arr[i]);
}

void	middle_sort(t_stacks *stacks)
{
	t_array	*tmp;
	int	key;
	int	size;

	size = stacks->a->size;
	tmp = NULL;
	while (stacks->a->size >= val_aprox(size / 4))
	{
		tmp = init_tmp(tmp, stacks->a->size);
		arr_cpy(tmp->arr, stacks->a->arr, tmp->size);
		key = get_key(tmp);
		while (check_and_swap(stacks, key) != -1)
			continue ;
		free(tmp);
	}
	while (stacks->a->size > 0)
		pb(stacks);
	end_sort(stacks);
}