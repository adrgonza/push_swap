#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"
# include <stdarg.h>
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include <string.h>
# include <mlx.h>

typedef struct push{
    int *stack_a;
    int *stack_b;
	int nb_count;
}				t_push;

int main(int argc, char **argv);
void px(t_push *push, int p);

#endif