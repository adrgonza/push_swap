#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"
# include <unistd.h>
# include <stdio.h>

typedef struct push{
    int *stack_a;
    int *stack_b;
	int nb_count;
    int min_number;
    int i;
    int j;
    char **splitted;
    char *string;
}				t_push;

int main(int argc, char **argv);
void sx(int *stack);
void px(int *stack);
void rx(int *stack);
void rrx(int *stack);

#endif