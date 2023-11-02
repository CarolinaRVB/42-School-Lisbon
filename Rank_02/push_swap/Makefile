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
CFLAGS = -Wall -Wextra -Werror -g
SRC = check_validations.c \
	  init_args.c \
	  moves_list_a.c \
	  moves_list_b.c \
	  moves_list_both.c \
	  main.c \
	  sort_list.c \
	  small_sort.c \
	  big_sort.c \
	  utils_main_1.c \
	  utils_main_2.c \
	  utils_args_1.c \
	  utils_args_2.c \
	  utils_list.c \
	  utils_big_1.c \
	  utils_big_2.c \
	  utils_big_3.c

OBJ = $(SRC:.c=.o)

PROGRAM_SRC = main.c

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
