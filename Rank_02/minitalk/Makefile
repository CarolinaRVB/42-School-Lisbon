# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: crebelo- <crebelo-@student.42lisboa.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/03 09:27:31 by crebelo-          #+#    #+#              #
#    Updated: 2023/12/03 09:27:31 by crebelo-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minitalk

SRCS = 

OBJS = $(SRCS:.c=.o)

CC = cc

CFLAGS = -Wall -Werror -Wextra -g #-fsanitize=address

LIBFT_DIR = libft

LIBFT_A = $(LIBFT_DIR)/libft.a

MINITALK_LIB = minitalk.a

%.o: %.c
	$(CC) $(CFLAGS) -o $@ -c $<

all: $(NAME)

$(NAME): $(SO_LONG_LIB) $(OBJS)
	$(CC) $(CFLAGS) -I/usr/include main.c $(OBJS) $(LIBFT_A) $(MINITALK_LIB) -o $(NAME) > /dev/null

$(MINITALK_LIB): $(OBJS)
	@make -C $(LIBFT_DIR) > /dev/null
	@ar rcs $(MINITALK_LIB) $(OBJS) $(LIBFT_A) > /dev/null
	
clean:
	@rm -f $(OBJS)
	@make -C $(LIBFT_DIR) clean > /dev/null

fclean:	clean
	@rm -f $(MINITALK_LIB)
	@rm -f $(NAME)
	@make -C $(LIBFT_DIR) fclean > /dev/null

re:	fclean all

.PHONY: all clean fclean re
