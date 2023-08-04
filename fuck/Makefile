# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jlim <jlim@student.42seoul.kr>             +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/09/29 13:29:45 by jlim              #+#    #+#              #
#    Updated: 2021/09/29 14:11:21 by jlim             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = checker

NAME2 = push_swap

CC = gcc

CFLAGS = -Wall -Wextra -Werror

RM = rm -f

LIB = ./libft/libft.a

LIB_PATH = ./libft

SRCS1 = checker.c\
		list.c\
		create_list.c\
		push.c\
		re_rotate.c\
		rotate.c\
		swap.c\
		utils.c

SRCS2 = push_swap.c\
		sorting.c\
		eight_sorting.c\
		list.c\
		create_list.c\
		push.c\
		get_median.c\
		re_rotate.c\
		rotate.c\
		swap.c\
		utils.c

OBJS1 = $(SRCS1:.c=.o)

OBJS2 = $(SRCS2:.c=.o)

INCS = -I $(LIB_PATH)

all : $(NAME) $(NAME2)

.c.o :
	$(CC) $(CFLAGS) -c $< -o $(<:.c=.o) $(INCS)

$(NAME) : $(OBJS1)
	make -C $(LIB_PATH)
	$(CC) $(CFLAGS) $(OBJS1) $(INCS) $(LIB) -o $(NAME)

$(NAME2) : $(OBJS2)
	make -C $(LIB_PATH)
	$(CC) $(CFLAGS) $(OBJS2) $(INCS) $(LIB) -o $(NAME2)

clean :
	make clean -C $(LIB_PATH)
	$(RM) $(OBJS1)
	$(RM) $(OBJS2)

fclean : clean
	make fclean -C $(LIB_PATH)
	$(RM) $(NAME) $(NAME2)

re : fclean all

.PHONY : all, clean, fclean, re
