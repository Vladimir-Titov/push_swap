/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jharras <jharras@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 14:32:41 by jharras           #+#    #+#             */
/*   Updated: 2022/02/17 18:35:46 by jharras          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	ft_memset(char *str)
{
	while (*str)
	{	
		*str = '\0';
		str++;
	}
}

int	ft_strcmp(char *str1, char *str2)
{
	while (*str1 && *str2)
	{
		if (*str1 != *str2)
			return (-1);
		str1++;
		str2++;
	}
	return (0);
}

t_stacks	*init_array(t_stacks *stacks, int count)
{
	stacks = malloc(sizeof(stacks));
	if (!stacks)
		error_msg_and_exit();
	stacks->a = malloc(sizeof(stacks->a));
	stacks->b = malloc(sizeof(stacks->b));
	if (!stacks->a || !stacks->b)
		error_msg_and_exit();
	stacks->a->arr = malloc(sizeof(int *) * count);
	stacks->b->arr = malloc(sizeof(int *) * count);
	if (!stacks->a->arr || !stacks->b->arr)
		error_msg_and_exit();
	stacks->a->size = 0;
	stacks->b->size = 0;
	return (stacks);
}

t_stacks	*fill_array(int count, t_stacks *stacks, char **data)
{
	int	i;
	int	j;

	i = 1;
	j = 0;
	stacks = init_array(stacks, count);
	stacks->a->min = ft_atoi(data[1]);
	while (i < count)
	{
		stacks->a->arr[j] = ft_atoi(data[i]);
		if (stacks->a->min > stacks->a->arr[j])
			stacks->a->min = stacks->a->arr[j];
		stacks->a->size++;
		i++;
		j++;
	}
	return (stacks);
}
