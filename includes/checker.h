/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jharras <jharras@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 17:51:55 by jharras           #+#    #+#             */
/*   Updated: 2022/02/17 15:47:45 by jharras          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <limits.h>

typedef struct s_stacks {
	struct s_array	*a;
	struct s_array	*b;
}		t_stacks;

typedef struct s_array {
	int	*arr;
	int	size;
	int	min;
}		t_array;

t_stacks	*fill_array(int count, t_stacks *stacks, char **data);
t_stacks	*init_array(t_stacks *stacks, int count);
void		ft_memset(char *str);
int			ft_strcmp(char *str1, char *str2);
void		error_msg_and_exit(void);
void		validate_arg(int count, char **argv);
int			ft_atoi(char *str);
void		sorting(t_stacks *stacks);
int			check_sort(t_array *stack);
void		sa(t_array *stack, int flag_write);
void		sb(t_array *stack, int flag_write);
void		ss(t_stacks *stacks, int flag_write);
void		ra(t_array *stack, int flag_write);
void		rb(t_array *stack, int flag_write);
void		rr(t_stacks *stacks, int flag_write);
void		rra(t_array *stack, int flag_write);
void		rrb(t_array *stack, int flag_write);
void		rrr(t_stacks *stacks, int flag_write);
void		pa(t_stacks *stack, int flag_write);
void		pb(t_stacks *stack, int flag_write);
int			get_index(t_array *stack, int digit);
void		find_min(t_array *stack);
void		quick_sort(int *array, int low, int high);
void		middle_sort(t_stacks *stacks);
int			find_less(t_array *stack, int less);
int			get_digit_less(t_array *stack, int less);
int			find_max(t_array *stack);
int			val_aprox(float m);
int			get_key(t_array *tmp);
void		free_stack(t_array *stack);
#endif