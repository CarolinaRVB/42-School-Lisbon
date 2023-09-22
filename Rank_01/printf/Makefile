# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: crebelo- <crebelo-@student.42lisboa.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/04 13:58:05 by crebelo-          #+#    #+#              #
#    Updated: 2023/05/04 13:58:05 by crebelo-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

CFLAGS = -Wall -Wextra -Werror

SRC = 	ft_printf.c \
		ft_putchar_fd.c \
		ft_putnbr_fd.c \
		ft_putptr_hex.c \
		ft_putnbr_hex.c \
		ft_putstr_fd.c \
		ft_putunbr.c \
		ft_strlen.c

OBJ = $(SRC:.c=.o)

$(NAME): $(OBJ)
		ar -rc $(NAME) $(OBJ)

all: $(NAME)

clean: 
		rm -f $(OBJ)

fclean: clean 
		rm -f $(NAME)

re: clean all