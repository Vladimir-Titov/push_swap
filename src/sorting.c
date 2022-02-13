/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jharras <jharras@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 13:55:28 by jharras           #+#    #+#             */
/*   Updated: 2022/02/13 18:07:54 by jharras          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	three_sort(t_stacks *stacks)
{
	int	i;

	i = 0;
	if (stacks->a->arr[i] > stacks->a->arr[i + 1] &&
		stacks->a->arr[i] > stacks->a->arr[i + 2])
	{
		ra(stacks->a, 1);
		if (check_sort(stacks->a))
			return ;
		sa(stacks->a, 1);
		return ;
	}
	if (stacks->a->arr[i] < stacks->a->arr[i + 1] &&
		stacks->a->arr[i] > stacks->a->arr[i + 2])
	{
		rra(stacks->a, 1);
		return ;
	}
	if (stacks->a->arr[i] > stacks->a->arr[i + 1] &&
		stacks->a->arr[i] < stacks->a->arr[i + 2])
	{
		sa(stacks->a, 1);
		return ;
	}
	rra(stacks->a, 1);
	sa(stacks->a, 1);
}

static void	small_sort(t_stacks *stacks)
{
	int	index_min;
	int	middle;

	while (stacks->a->size > 3)
	{
		index_min = get_index(stacks->a, stacks->a->min);
		middle = (stacks->a->size) / 2;
		if (index_min <= middle)
		{
			while (index_min-- > 0)
				ra(stacks->a, 1);
		}
		else
		{
			while (index_min-- > 0)
				rra(stacks->a, 1);
		}
		pb(stacks);
		find_min(stacks->a);
	}
	if (!check_sort(stacks->a))
		three_sort(stacks);
	while (stacks->b->size > 0)
		pa(stacks);
}

void	sorting(t_stacks *stacks)
{
	if (stacks->a->size == 2)
		sa(stacks->a, 1);
	else if (stacks->a->size == 3)
		three_sort(stacks);
	else if (stacks->a->size > 3 && stacks->a->size < 10)
		small_sort(stacks);
	else if (stacks->a->size > 10 && stacks->a->size < 100)
		middle_sort(stacks);
}
