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

SERVER_SRC = server.c

<<<<<<< HEAD
CLIENT_SRC = client.c

SERVER_BONUS_SRC = server_bonus.c

CLIENT_BONUS_SRC = client_bonus.c
=======
SERVER = server.c

SERVER_BONUS = server_bonus.c

CLIENT = client.c

CLIENT_BONUS = client_bonus.c

SOBJS = $(SERVER:.c=.o)

SBOBJS = $(SERVER_BONUS:.c=.o)

COBJS = $(CLIENT:.c=.o)

CBOBJS = $(CLIENT_BONUS:.c=.o)


.PHONY: all clean fclean re bonus
>>>>>>> cad68f986b0f0c5be2ac9b973ae59376445406af

all: $(NAME)

$(NAME): server client

<<<<<<< HEAD
server: $(SERVER_SRC)
	@make -C $(LIBFT_DIR) > /dev/null
	@$(CC) $(CFLAGS) $(SERVER_SRC) $(LIBFT_A) -o $@
=======
server: $(SOBJS)
	@make -C $(LIBFT_DIR) > /dev/null
	@$(CC) $(CFLAGS) -o server $(SOBJS) $(LIBFT_A)
>>>>>>> cad68f986b0f0c5be2ac9b973ae59376445406af

client: $(CLIENT_SRC)
	@make -C $(LIBFT_DIR) > /dev/null
<<<<<<< HEAD
	@$(CC) $(CFLAGS) $(CLIENT_SRC) $(LIBFT_A) -o $@
=======
	@$(CC) $(CFLAGS) -o client $(COBJS) $(LIBFT_A)
>>>>>>> cad68f986b0f0c5be2ac9b973ae59376445406af

bonus: server_bonus client_bonus

server_bonus: $(SERVER_BONUS_SRC)
	@make -C $(LIBFT_DIR) > /dev/null
<<<<<<< HEAD
	@$(CC) $(CFLAGS) $(SERVER_BONUS_SRC) $(LIBFT_A) -o $@
=======
	@$(CC) $(CFLAGS) -o server_bonus $(SBOBJS) $(LIBFT_A)
>>>>>>> cad68f986b0f0c5be2ac9b973ae59376445406af

client_bonus: $(CLIENT_BONUS_SRC)
	@make -C $(LIBFT_DIR) > /dev/null
<<<<<<< HEAD
	@$(CC) $(CFLAGS) $(CLIENT_BONUS_SRC) $(LIBFT_A) -o $@

clean:
	$(MAKE) clean -C $(LIBFT_DIR)
	$(RM) $(NAME) server client server_bonus client_bonus

fclean: clean
	$(MAKE) fclean -C $(LIBFT_DIR)
=======
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
>>>>>>> cad68f986b0f0c5be2ac9b973ae59376445406af

re: fclean all
