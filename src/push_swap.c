/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jharras <jharras@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 13:37:29 by jharras           #+#    #+#             */
/*   Updated: 2022/02/17 13:40:29 by jharras          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// static void	print_stack(t_array *stack , char *name)
// {
// 	int	i;

// 	i = 0;
// 	while (i < stack->size)
// 	{
// 		printf("%d\n", stack->arr[i]);
// 		i++;
// 	}
// 	printf("_\n%s\n\n", name);
// }

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

int	main(int argc, char **argv)
{
	t_stacks	*stacks;

	stacks = NULL;
	validate_arg(argc, argv);
	stacks = fill_array(argc, stacks, argv);
	sorting(stacks);
	exit(0);
}
