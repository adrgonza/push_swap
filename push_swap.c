#include "push_swap.h"

void ft_exit(t_push *push, int ko)
{
    if (ko == 1)
        printf("\033[31mError:\nRepeated numbers...\n");
    exit(0);
}

void ft_sort_numbers(t_push *push)
{

}

int ft_convert_nb(t_push *push) //look for de lowest number and change all of them (1 to n)
{
    int i;

    i = 0;
    push->min_number = push->stack_a[0];
    while (++i <push->nb_count)
        if (push->stack_a[i] < push->min_number)
            push->min_number = push->stack_a[i];
    i = -1;
    while (++i <push->nb_count)
        push->stack_a[i] -= push->min_number - 1;
    return (-2);
}

void ft_get_number(int argc, char **argv, t_push *push)
{
    push->string = malloc(1);
    push->i = 0;
    while(++push->i < argc) //put all arguments in a hole string
    {
        push->string = ft_strjoin(push->string, argv[push->i]);
        push->string = ft_strjoin(push->string, " ");
    }
    push->splitted = ft_split(push->string, ' '); //split string
    push->i = 0;
    while (push->splitted[push->i]) //get size of *int
        push->i++;
    push->nb_count = push->i;
    push->stack_a = malloc(push->i); //allocate memory for it
    push->i = -1;
    while(push->splitted[++push->i]) //put every number in a int *
        push->stack_a[push->i] = ft_atoi(push->splitted[push->i]);
    push->i = -1;
    while (++push->i < push->nb_count)//check repeated numbers
    {
        push->j = push->i;
        while (++push->j < push->nb_count)
            if (push->stack_a[push->j] == push->stack_a[push->i])
                ft_exit(push, 1);
    }
}

int main(int argc, char **argv)
{
    t_push push;
    int i;
    int j;

    if (argc < 2) //check there is more than 1 argument
        return (printf("\033[31mError:\nInsert Numbers...\n"));
    j = 0;
    while (++j < argc) //check there is only numbers and spaces
    {
        i = -1;
        while (argv[j][++i])
            if ((argv[j][i] != ' '  && (argv[j][i] < '0' || argv[j][i] > '9'))
            && ((argv[j][i] != '-' && argv[j][i] != '+')
            || (argv[j][i + 1] < '0' || argv[j][i + 1] > '9')))
                return (printf("\033[31mError:\nOnly numbers allow...\n"));
    }
    ft_get_number(argc, argv, &push);
    i = -1;
    while (++i < push.nb_count && i != -1)
        if (push.stack_a[i] < 1)
            i = ft_convert_nb(&push);
    rrx(&push, 1);
    ft_sort_numbers(&push);
}