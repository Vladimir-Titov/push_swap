/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jharras <jharras@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 13:37:04 by jharras           #+#    #+#             */
/*   Updated: 2022/02/11 18:36:21 by jharras          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <limits.h>

typedef struct s_stacks {
	struct s_array *a;
	struct s_array *b;
}		t_stacks;

typedef struct	s_array {
	int	*arr;
	int	size;
	int	min;
}		t_array;

void	error_msg_and_exit(void);
void	validate_arg(int count, char **argv);
int		ft_atoi(char *str);
void	sorting(t_stacks *stacks);
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
void	pa(t_stacks *stack);
void	pb(t_stacks *stack);
int		get_index(t_array *stack, int digit);
void	find_min(t_array *stack);
#endif