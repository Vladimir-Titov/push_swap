/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jharras <jharras@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 13:38:16 by jharras           #+#    #+#             */
/*   Updated: 2022/02/17 18:48:20 by jharras          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	check_words(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			error_msg_and_exit();
		i++;
	}
}

static void	check_overflow(int a, int b, int sign)
{
	int	overflow;

	overflow = 0;
	if (sign == -1)
	{
		a = -a;
		b = -b;
	}
	if (a > 0 && b > INT_MAX - a)
	{
		overflow = 1;
	}
	else if (a < 0 && b < INT_MIN - a)
	{
		overflow = 1;
	}
	if (overflow == 1)
		error_msg_and_exit();
}

int	ft_atoi(char *str)
{
	int	res;
	int	negative;

	negative = 1;
	res = 0;
	while (*str && (*str == ' ' || *str == '\n' || *str == '\t'
			|| *str == '\v' || *str == '\f' || *str == '\r'))
		++str;
	if (*str == '-')
		negative = -1;
	if (*str == '-' || *str == '+')
		++str;
	check_words(str);
	while (*str && *str >= '0' && *str <= '9')
	{
		check_overflow(res * 10, *str - 48, negative);
		res = res * 10 + (*str - 48);
		++str;
	}
	return (res * negative);
}

void	free_stack(t_array *stack)
{
	free(stack->arr);
	free(stack);
}
