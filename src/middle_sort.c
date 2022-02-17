/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   middle_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jharras <jharras@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/13 17:40:31 by jharras           #+#    #+#             */
/*   Updated: 2022/02/17 13:53:09 by jharras          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_array	*init_tmp(t_array *tmp, int size)
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

void	middle_sort(t_stacks *stacks)
{
	t_array	*tmp;
	int		key;
	int		size;

	size = stacks->a->size;
	tmp = NULL;
	while (stacks->a->size >= val_aprox(size / 4))
	{
		tmp = init_tmp(tmp, stacks->a->size);
		arr_cpy(tmp->arr, stacks->a->arr, tmp->size);
		key = get_key(tmp);
		while (check_and_swap(stacks, key) != -1)
			continue ;
		free_stack(tmp);
	}
	while (stacks->a->size > 0)
		pb(stacks);
	end_sort(stacks);
}
