#include "push_swap.h"

void ft_exit(t_push *push, int ko)
{
    if (ko == 1)
        printf("\033[31mError:\nRepeated numbers...\n");
    exit(0);
}

void ft_convert_nb(t_push *push)
{
    int i;
    int j;
    int aux;

    i = -1;
    while (++i < push->nb_count) //bubble sort
    {
        j = -1;
        while (++j < push->nb_count - 1)
        {
            if (push->stack_b[j] > push->stack_b[j + 1])
            {
                aux = push->stack_b[j];
                push->stack_b[j] = push->stack_b[j + 1];
                push->stack_b[j + 1] = aux;
            }
        }
    }
    j = -1;
    while (++j < push->nb_count)//convert nb to positions
    {
        i = -1;
        while (++i < push->nb_count)
            if (push->stack_a[j] == push->stack_b[i])
                push->stack_a[j] = i + 1;
    }
}

int ft_check_nb(t_push *push) 
{
    int i;
    int j;

    i = -1;
    while (++i < push->nb_count)//check repeated numbers
    {
        j = i;
        while (++j < push->nb_count)
            if (push->stack_a[j] == push->stack_a[i])
                ft_exit(push, 1);
    }
    push->stack_b = malloc(push->nb_count * sizeof(int));
    if (!push->stack_b)
        ft_exit(push, 2);
    i = -1;
    while (++i < push->nb_count) // get copy
        push->stack_b[i] = push->stack_a[i];
    i = -1;
    while (++i < push->nb_count) //cheeck if is ordenated
        if (push->stack_a[i] > push->stack_a[i + 1] && push->stack_a[i + 1])
            return (ft_convert_nb(push), 1);
    return(ft_exit(push, 2), 0);
}

void ft_get_number(int argc, char **argv, t_push *push)
{
    int i;
    
    i = 0;
    push->string = malloc(1 * sizeof(char));
    if (!push->string)
        ft_exit(push, 2);
    while(++i < argc) //put all arguments in a hole string
    {
        push->string = ft_strjoin(push->string, argv[i]);
        push->string = ft_strjoin(push->string, " ");
    }
    push->splitted = ft_split(push->string, ' '); //split string
    i = 0;
    while (push->splitted[i]) //get size of *int
        i++;
    push->nb_count = i;
    push->stack_a = malloc(i * sizeof(int)); //allocate memory for it
    if (!push->stack_a)
        ft_exit(push, 2);
    i = -1;
    while(push->splitted[++i]) //put every number in a int *
        push->stack_a[i] = ft_atoi(push->splitted[i]);
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
    ft_get_number(argc, argv, &push); //put argument in a int *
    ft_check_nb(&push);
    if (!ft_sort_nb(&push))
        ft_exit(&push, 2);
}