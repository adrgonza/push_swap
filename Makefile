NAME = push_swap
CC = gcc -Wall -Wextra -Werror
RM = rm -f
SRC = push_swap.c push_sort.c push_operations.c push_utils.c push_split.c\

OBJ = $(SRC:.c=.o)

$(NAME): $(OBJ)
		$(CC) $(OBJ) -o $(NAME)

all : $(NAME)

clean:
		$(RM) $(OBJ)

fclean: clean
		@$(RM) $(NAME)

re: clean all

.PHONY: all bonus fclean clean re
