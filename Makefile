NAME = push_swap
CC = gcc
RM = rm -f
SRC = push_swap.c push_utils.c push_operations.c libft.a\

OBJ = $(SRC:.c=.o)

$(NAME): $(OBJ)
		$(CC) $(OBJ) -o $(NAME)

all : $(NAME)

clean:
		$(RM) $(OBJ)

fclean: clean
		@$(RM) $(NAME)

re: fclean all

.PHONY: all bonus fclean clean re