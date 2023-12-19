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

CC = cc

CFLAGS = -Wall -Werror -Wextra #-g -fsanitize=address

RM = rm -f

INCLUDE = minitalk.h

LIBFT_DIR = libft

LIBFT_A = $(LIBFT_DIR)/libft.a

MINITALK_LIB = minitalk.a

SERVER = server.c

SERVER_BONUS = server_bonus.c

CLIENT = client.c

CLIENT_BONUS = client_bonus.c

SOBJS = $(SERVER:.c=.o)

SBOBJS = $(SERVER_BONUS:.c=.o)

COBJS = $(CLIENT:.c=.o)

CBOBJS = $(CLIENT_BONUS:.c=.o)


.PHONY: all clean fclean re bonus

all: $(NAME)

$(NAME): server client

server: $(SOBJS)
	@make -C $(LIBFT_DIR) > /dev/null
	@$(CC) $(CFLAGS) -o server $(SOBJS) $(LIBFT_A)

client: $(COBJS)
	@make -C $(LIBFT_DIR) > /dev/null
	@$(CC) $(CFLAGS) -o client $(COBJS) $(LIBFT_A)

bonus: server_bonus client_bonus

server_bonus: $(SBOBJS)
	@make -C $(LIBFT_DIR) > /dev/null
	@$(CC) $(CFLAGS) -o server_bonus $(SBOBJS) $(LIBFT_A)

client_bonus: $(CBOBJS)
	@make -C $(LIBFT_DIR) > /dev/null
	@$(CC) $(CFLAGS) -o client_bonus $(CBOBJS) $(LIBFT_A)

$(SOBJS): $(SERVER) $(INCLUDE)
	$(CC) $(CFLAGS) -c $(SERVER) -o $@

$(COBJS): $(CLIENT) $(INCLUDE)
	$(CC) $(CFLAGS) -c $(CLIENT) -o $@

$(SBOBJS): $(SERVER_BONUS) $(INCLUDE)
	$(CC) $(CFLAGS) -c $(SERVER_BONUS) -o $@

$(CBOBJS): $(CLIENT_BONUS) $(INCLUDE)
	$(CC) $(CFLAGS) -c $(CLIENT_BONUS) -o $@

clean:
	@make clean -C $(LIBFT_DIR)
	$(RM) $(SOBJS) $(COBJS) $(SBOBJS) $(CBOBJS)

fclean: clean
	@make fclean -C $(LIBFT_DIR)
	$(RM) server client server_bonus client_bonus $(MINITALK_LIB)

re: fclean all
