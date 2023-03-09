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
int ft_sort_nb(t_push *push);
int operation(t_push *push, int n);

#endif