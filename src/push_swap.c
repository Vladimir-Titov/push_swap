/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jharras <jharras@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 13:37:29 by jharras           #+#    #+#             */
/*   Updated: 2022/02/10 14:06:37 by jharras          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	print_stack(t_array *stack)
{
	int	i;

	i = 0;
	while (i < stack->size_a || i < stack->size_b)
	{
		printf("%d			%d\n", stack->a[i], stack->b[i]);
		i++;
	}
	printf("\na			b\n");
}

static t_array	*init_array(t_array *stack, int count)
{
	stack = malloc(sizeof(stack));
	if (!stack)
		error_msg_and_exit();
	stack->a = malloc(sizeof(int *) * count);
	stack->b = malloc(sizeof(int *) * count);
	if (!stack->a || !stack->b)
		error_msg_and_exit();
	stack->size_a = 0;
	stack->size_b = 0;
	return (stack);
}

static t_array	*fill_array(int count, t_array *stack, char **data)
{
	int	i;
	int	j;

	i = 1;
	j = 0;
	stack = init_array(stack, count);
	while (i < count)
	{
		stack->a[j++] = ft_atoi(data[i++]);
		stack->size_a++;
	}
	return (stack);
}

int	main(int argc, char **argv)
{
	t_array	*stack;

	stack = NULL;
	validate_arg(argc, argv);
	stack = fill_array(argc, stack, argv);
	print_stack(stack);
	sorting(stack);
	printf("--------------------------------------------\n");
	print_stack(stack);
	printf("size a- %d\n", stack->size_a);
	printf("size b- %d\n", stack->size_b);
	return (0);
}