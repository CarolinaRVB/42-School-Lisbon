# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: crebelo- <crebelo-@student.42lisboa.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/02 08:54:59 by crebelo-          #+#    #+#              #
#    Updated: 2023/10/02 08:54:59 by crebelo-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = pushswap.a
CFLAGS = -Wall -Wextra -Werror
SRC = check_validations.c \
	  init_args.c \
	  moves_list.c \
	  push_swap.c \
	  sort_list.c \
	  utils_args.c \
	  utils_list.c \
	  big_sort.c
OBJ = $(SRC:.c=.o)

#program's source file
PROGRAM_SRC = push_swap.c

#name of the executable
PROGRAM_NAME = push_swap

$(NAME): $(OBJ)
	ar -rc $(NAME) $(OBJ)

all: $(NAME) $(PROGRAM_NAME)

$(PROGRAM_NAME): $(PROGRAM_SRC)
	gcc $(CFLAGS) -o $(PROGRAM_NAME) $(PROGRAM_SRC) $(NAME)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME) $(PROGRAM_NAME)

re: fclean all

.PHONY: all clean fclean re
