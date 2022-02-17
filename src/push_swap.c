/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jharras <jharras@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 13:37:29 by jharras           #+#    #+#             */
/*   Updated: 2022/02/17 15:33:04 by jharras          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_stacks	*stacks;

	stacks = NULL;
	validate_arg(argc, argv);
	stacks = fill_array(argc, stacks, argv);
	sorting(stacks);
	exit(0);
}
