/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jharras <jharras@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 13:38:39 by jharras           #+#    #+#             */
/*   Updated: 2022/02/17 13:42:20 by jharras          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	a_is_sorted(int count, char **argv)
{
	int	i;

	i = 1;
	while (i + 1 < count)
	{
		if (ft_atoi(argv[i]) > ft_atoi(argv[i + 1]))
			return ;
		i++;
	}
	exit(0);
}

static void	have_duplicate(int count, char **argv)
{
	int	i;
	int	j;

	i = 1;
	j = 1;
	while (i + 1 <= count)
	{
		while (j + 1 <= count)
		{	
			if (ft_atoi(argv[i]) == ft_atoi(argv[j]) && i != j)
				error_msg_and_exit();
			j++;
		}
		i++;
		j = 1;
	}
}

void	validate_arg(int count, char **argv)
{
	if (count == 1)
		return ;
	have_duplicate(count, argv);
	a_is_sorted(count, argv);
}
