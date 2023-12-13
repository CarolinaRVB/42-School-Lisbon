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

INCLUDE = minitalk.h

SERVER = server.c

SERVER_BONUS = server_bonus.c

SOBJS = $(SERVER:.c=.o)

SBOBJS = $(SERVER_BONUS:.c=.o)

CLIENT = client.c

COBJS = $(CLIENT:.c=.o)

CLIENT_BONUS = client_bonus.c

CBOBJS = $(CLIENT_BONUS:.c=.o)

CFLAGS = -Wall -Werror -Wextra #-g -fsanitize=address

LIBFT_DIR = libft

LIBFT_A = $(LIBFT_DIR)/libft.a

MINITALK_LIB = minitalk.a

%.o: %.c
	$(CC) $(CFLAGS) -o $@ -c $<

all: $(NAME) bonus

$(NAME): server client

server: $(SOBJS) 
	@make -C $(LIBFT_DIR) > /dev/null
	@$(CC) $(CFLAGS) $(INCLUDE) $(SOBJS) $(LIBFT_A) -o server >/dev/null

client: $(COBJS)
	@make -C $(LIBFT_DIR) > /dev/null
	@$(CC) $(CFLAGS) $(INCLUDE) $(COBJS) $(LIBFT_A) -o client >/dev/null

bonus: server_bonus client_bonus

server_bonus: $(SBOBJS)
	@make -C $(LIBFT_DIR) > /dev/null
	@$(CC) $(CFLAGS) $(INCLUDE) $(SBOBJS) $(LIBFT_A) -o server_bonus >/dev/null

client_bonus: $(CBOBJS)
	@make -C $(LIBFT_DIR) > /dev/null
	@$(CC) $(CFLAGS) $(INCLUDE) $(CBOBJS) $(LIBFT_A) -o client_bonus >/dev/null

clean:
	$(MAKE) clean -C $(LIBFT_DIR)
	$(RM) $(SOBJS) $(COBJS) $(SBOBJS) $(CBOBJS)

fclean: clean
	$(MAKE) fclean -C $(LIBFT_DIR)
	$(RM) server client server_bonus client_bonus

re: fclean all
