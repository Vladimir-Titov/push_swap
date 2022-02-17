/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jharras <jharras@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 17:54:27 by jharras           #+#    #+#             */
/*   Updated: 2022/02/17 18:47:55 by jharras          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

static void	execute(char *command, t_stacks *stacks)
{
	if (ft_strcmp(command, "sa\n") == 0)
		sa(stacks->a, 0);
	else if (ft_strcmp(command, "sb\n") == 0)
		sb(stacks->b, 0);
	else if (ft_strcmp(command, "ss\n") == 0)
		ss(stacks, 0);
	else if (ft_strcmp(command, "pa\n") == 0)
		pa(stacks, 0);
	else if (ft_strcmp(command, "pb\n") == 0)
		pb(stacks, 0);
	else if (ft_strcmp(command, "ra\n") == 0)
		ra(stacks->a, 0);
	else if (ft_strcmp(command, "rb\n") == 0)
		rb(stacks->b, 0);
	else if (ft_strcmp(command, "rr\n") == 0)
		rr(stacks, 0);
	else if (ft_strcmp(command, "rra\n") == 0)
		rra(stacks->a, 0);
	else if (ft_strcmp(command, "rrb\n") == 0)
		rrb(stacks->b, 0);
	else if (ft_strcmp(command, "rrr\n") == 0)
		rrr(stacks, 0);
	else
		error_msg_and_exit();
}

static int	checking(t_stacks *stacks)
{
	char	commands[5];
	int		i;

	i = 0;
	while (read(0, &commands[i], 1) != 0)
	{
		if (commands[i] == '\n')
		{
			execute(commands, stacks);
			ft_memset(commands);
			i = 0;
			continue ;
		}
		i++;
	}
	if (check_sort(stacks->a) != 1 || stacks->b->size != 0)
		write(1, "KO\n", 3);
	else
		write(1, "OK\n", 3);
	exit(0);
}

int	main(int argc, char **argv)
{
	t_stacks	*stacks;

	stacks = NULL;
	validate_arg(argc, argv);
	stacks = fill_array(argc, stacks, argv);
	checking(stacks);
	exit(0);
}
