# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ayguilla <ayguilla@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/06/12 11:16:40 by mric              #+#    #+#              #
#    Updated: 2023/06/13 14:28:09 by ayguilla         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	minitalk

CC		=	cc
CFLAGS	=	-Wall -Werror -Wextra
RM		=	rm -f

CLIENT	=	client
SERVER 	=	server

all:		$(NAME)

$(SERVER): 	$(SERVER).c
				@$(CC)	$(CFLAGS)	-o	$(SERVER)	$(SERVER).c
				@echo "The server is ready!"
				
$(CLIENT): 	$(CLIENT).c
				@$(CC)	$(CFLAGS)	-o	$(CLIENT)	$(CLIENT).c
				@echo "The client is ready too!"

$(NAME): 	$(SERVER)	$(CLIENT)

clean:
				@$(RM)	$(SERVER)	$(CLIENT)

fclean: 	clean

re: 		fclean all

.PHONY: 	all clean fclean re