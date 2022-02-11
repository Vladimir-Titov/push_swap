/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jharras <jharras@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 13:55:28 by jharras           #+#    #+#             */
/*   Updated: 2022/02/11 17:09:35 by jharras          ###   ########.fr       */
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

static void	six_sort(t_stacks *stacks)
{
	pb(stacks);
}

void	sorting(t_stacks *stacks)
{
	if (stacks->a->size == 2)
		sa(stacks->a, 1);
	else if (stacks->a->size == 3)
		three_sort(stacks);
	else if (stacks->a->size <= 6)
		six_sort(stacks);
}