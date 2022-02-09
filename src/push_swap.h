/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jharras <jharras@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 13:37:04 by jharras           #+#    #+#             */
/*   Updated: 2022/02/09 15:39:24 by jharras          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <limits.h>

typedef struct s_array {
	int	*a;
	int	*b;
	int	size_a;
	int	size_b;
}		t_array;

void	error_msg_and_exit(void);
void	validate_arg(int count, char **argv);
int		ft_atoi(char *str);
void	sorting(t_array *stack);
int		check_sort(t_array *stack);
void	sa(t_array *stack, int flag_write);
void	sb(t_array *stack, int flag_write);
void	ss(t_array *stack);
void	ra(t_array *stack, int flag_write);
void	rb(t_array *stack, int flag_write);
void	rr(t_array *stack);
void	rra(t_array *stack, int flag_write);
void	rrb(t_array *stack, int flag_write);
void	rrr(t_array *stack);
#endif