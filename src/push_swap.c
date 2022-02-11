/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jharras <jharras@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 13:37:29 by jharras           #+#    #+#             */
/*   Updated: 2022/02/11 17:08:38 by jharras          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	print_stack(t_stacks *stacks)
{
	int	i;

	i = 0;
	while (i < stacks->a->size || i < stacks->b->size)
	{
		printf("%d			%d\n", stacks->a->arr[i], stacks->b->arr[i]);
		i++;
	}
	printf("\na			b\n");
}

static t_stacks	*init_array(t_stacks *stacks, int count)
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

static t_stacks	*fill_array(int count, t_stacks *stacks, char **data)
{
	int	i;
	int	j;

	i = 1;
	j = 0;
	stacks = init_array(stacks, count);
	while (i < count)
	{
		stacks->a->arr[j++] = ft_atoi(data[i++]);
		stacks->a->size++;
	}
	return (stacks);
}

int	main(int argc, char **argv)
{
	t_stacks	*stacks;

	stacks = NULL;
	validate_arg(argc, argv);
	stacks = fill_array(argc, stacks, argv);
	print_stack(stacks);
	sorting(stacks);
	printf("--------------------------------------------\n");
	print_stack(stacks);
	return (0);
}