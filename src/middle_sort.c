/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   middle_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jharras <jharras@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/13 17:40:31 by jharras           #+#    #+#             */
/*   Updated: 2022/02/13 18:06:52 by jharras          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void printArray(int *array, int size)
{
  for (int i = 0; i < size; i++) {
    printf("%d  ", array[i]);
  }
  printf("\n");
}

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

static void	check_and_swap(t_stacks *stacks, int key, int count_iter)
{
	int	middle;
	int	index_key;
	int	i;

	i = 0;
	while (i < count_iter)
	{
		index_key = get_index(stacks->a, key);
		middle = (stacks->a->size) / 2;
		if (index_key <= middle)
		{
			while (index_key-- > 0)
				ra(stacks->a, 1);
		}
		else
		{
			while (index_key-- > 0)
				rra(stacks->a, 1);
		}
		pb(stacks);
		i++;
	}
}

void	middle_sort(t_stacks *stacks)
{
	t_array	*tmp;
	int	key;

	tmp = NULL;
	tmp = init_tmp(tmp, stacks->a->size);
	arr_cpy(tmp->arr, stacks->a->arr, tmp->size);
	quick_sort(tmp->arr, 0, tmp->size - 1);
	key = tmp->size / 4;
	check_and_swap(stacks, key, stacks->a->size / 4);
	printArray(stacks->b->arr, stacks->b->size);
}