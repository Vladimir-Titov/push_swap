# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jharras <jharras@student.21-school.ru>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/09 13:36:08 by jharras           #+#    #+#              #
#    Updated: 2022/02/11 21:21:04 by jharras          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= push_swap

SRC		= 	push_swap.c	error.c	validate.c \
			utils.c	sorting.c	sort_utils.c \
			swap.c	rotate.c	reverse_rotate.c \
			push.c

SRCS	= $(addprefix src/, $(SRC))

OBJ			= $(SRCS:.c=.o)

CFLAGS		= -Wall -Werror -Wextra

.PHONY		: all clean fclean re

all			: $(NAME)

$(NAME)		: $(OBJ)
			gcc -o $(NAME) $(CFLAGS) $(OBJ)

%.o : %.c
		gcc -c $(CFLAGS) $< -o $@
		
clean:
		rm -f $(OBJ)
		
fclean: clean
		rm -f $(NAME)

re: fclean all