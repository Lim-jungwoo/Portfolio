# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jlim <jlim@student.42seoul.kr>             +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/08 11:34:19 by jlim              #+#    #+#              #
#    Updated: 2022/03/08 11:34:19 by jlim             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3d
NAME_LIB = cub3d.a

LIBFT = libft
LIBFT_LIB = libft.a

MLX = minilibx_opengl_20191021
MLX_LIB = libmlx.a

SRCS = ./cub3d.c ./parse.c ./clear.c ./print.c ./map_check.c\
		./map_check_wall.c ./map_check_character.c ./map_check_nsew.c\
		./init_mlx.c ./map.c\

OBJS = $(SRCS:.c=.o)

LIBC = ar rc

CC = gcc
CFLAGS = -Wall -Wextra -Werror
MLX_CFLAGS = -framework OpenGL -framework AppKit

RM = rm -f

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT)/$(LIBFT_LIB) $(MLX)/$(MLX_LIB)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT)/$(LIBFT_LIB) $(MLX)/$(MLX_LIB) $(MLX_CFLAGS) -o $(NAME)

$(LIBFT)/$(LIBFT_LIB):
	make -C $(LIBFT) all

$(MLX)/$(MLX_LIB):
	make -C $(MLX) all

clean:
	$(RM) $(OBJS)
	make -C $(LIBFT) clean
	make -C $(MLX) clean

fclean: clean
	$(RM) $(NAME) $(NAME_LIB)
	make -C $(LIBFT) fclean

re: fclean all

.PHONY: all clean fclean re