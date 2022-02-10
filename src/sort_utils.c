/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jharras <jharras@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 14:50:08 by jharras           #+#    #+#             */
/*   Updated: 2022/02/10 14:20:52 by jharras          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_sort(int *array, int size)
{
	int	i;

	i = 0;
	while (i + 1 < size)
	{
		if (array[i] > array[i + 1])
			return (0);
		i++;
	}
	return (1);
}
