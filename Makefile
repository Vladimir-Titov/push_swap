# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jharras <jharras@student.21-school.ru>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/09 13:36:08 by jharras           #+#    #+#              #
#    Updated: 2022/02/17 18:51:43 by jharras          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= push_swap
NAME_BONUS	= checker

SRC			=	push_swap.c	error.c	validate.c \
				utils.c	sorting.c	sort_utils.c \
				swap.c	rotate.c	reverse_rotate.c \
				push.c	quick_sort.c	middle_sort.c \
				utils_middle_sort.c utils2.c\

SRC_BONUS 	=	checker.c	error.c	validate.c \
				utils.c	swap.c	rotate.c \
				reverse_rotate.c \
				push.c	\
				utils_2.c	\

SRCS		= $(addprefix src/, $(SRC))
SRCS_BONUS	= $(addprefix checker_src/, $(SRC_BONUS))
SRC_HEADER	= includes/push_swap.h

OBJ			= $(SRCS:.c=.o)
OBJ_BONUS	= $(SRCS_BONUS:.c=.o)
BONUS_HEADER	= includes/checker.h

INCLUDES	= includes/

CFLAGS		= -Wall -Werror -Wextra

.PHONY		: all bonus clean fclean re

all			: $(NAME) $(NAME_BONUS)

bonus		: $(NAME_BONUS)

$(NAME)		: $(OBJ)
			cc -o $(NAME) $(CFLAGS) -I $(INCLUDES) $(OBJ)

$(NAME_BONUS)	: $(OBJ_BONUS)
			cc -o $(NAME_BONUS) $(CFLAGS) -I $(INCLUDES) $(OBJ_BONUS)

%.o : %.c $(SRC_HEADER) $(BONUS_HEADER)
		cc -c $(CFLAGS) -I $(INCLUDES) $< -o $@
		
clean:
		rm -f $(OBJ) $(OBJ_BONUS)
		
fclean: clean
		rm -f $(NAME) $(NAME_BONUS)

re: fclean all