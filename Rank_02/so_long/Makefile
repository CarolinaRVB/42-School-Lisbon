# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: crebelo- <crebelo-@student.42lisboa.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/07 15:38:32 by crebelo-          #+#    #+#              #
#    Updated: 2023/11/20 13:28:41 by crebelo-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

SRCS = so_long_utils_1.c \
	   so_long_utils_2.c \
	   main.c \
	   so_long_build.c \
	   so_long_check.c \
	   so_long_init.c

OBJS = $(SRCS:.c=.o)

CC = gcc

CFLAGS = -Wall -Werror -Wextra -g -fsanitize=address

MLXFLAGS = -Lminilibx_linux -lmlx -L/usr/lib -Iminilibx_linux -lXext -lX11 -lm -lz

LIBFT_DIR = libft

LIBFT_A = $(LIBFT_DIR)/libft.a

%.o: %.c
	$(CC) -Wall -Wextra -Werror -I/usr/include -Iminilibx_linux -O3 -c $< -o $@

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(OBJS) $(LIBFT_A) $(MLXFLAGS) -o $(NAME)

clean:
	@rm -f $(OBJS)

fclean:	clean 
	@rm -f $(NAME)

re:	fclean

.PHONY: all clean fclean re