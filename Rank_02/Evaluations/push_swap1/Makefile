SourceFiles = aux_funcs.c best_friend_calcs.c big_sort.c list_utils.c \
move_funcs.c node_utils.c push_actions.c push_swap.c reverse_rotation_actions.c \
rotate_actions.c sorting.c swap_actions.c utils.c check_args_utils.c Libft/ft_split.c

Objects = $(SourceFiles:.c=.o)

EXEC_NAME = push_swap
CC = cc
CFLAGS = -Wall -Wextra -Werror
RM = rm -f

all: $(EXEC_NAME)

$(EXEC_NAME): $(Objects)
	$(CC) $(CFLAG) $(Objects) -o $(EXEC_NAME)

clean :
	$(RM) $(Objects)

fclean : clean
	$(RM) $(NAME)

re : fclean all

.PHONY: all clean fclean re
