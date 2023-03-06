#include "push_swap.h"

void ft_exit(t_push *push)
{
    exit(0);
}

void ft_sort_numbers(t_push *push)
{

}

int ft_get_number(int argc, char **argv, t_push *push) // there are leaks int this function
{
    char **splitted;
    char *string;
    int i;

    string = malloc(1);
    i = 0;
    while(++i < argc) //put all arguments in a hole string
    {
        string = ft_strjoin(string, argv[i]);
        string = ft_strjoin(string, " ");
    }
    splitted = ft_split(string, ' '); //split string
    free(string);
    i = 0;
    while (splitted[i]) //get size of *int
        i++;
    push->nb_count = i;
    push->stack_a = malloc(i); //allocate memory for it
    i = -1;
    while(splitted[++i]) //put every number in a int *
    {
        push->stack_a[i] = atoi(splitted[i]);
        free(splitted[i]);
    }
    free(splitted);
    return (1);
}

int main(int argc, char **argv)
{
    t_push push;
    int i;
    int j;

    if (argc <= 1) //check there is more than 1 argument
        return (printf("\033[31mError:\nInsert Numbers...\n"));
    j = 0;
    while (++j < argc) //check there is only numbers and spaces
    {
        i = -1;
        while (argv[j][++i])
            if (argv[j][i] != ' '  && (argv[j][i] < '0' || argv[j][i] > '9'))
                if((argv[j][i] != '-' || (argv[j][i + 1] < '0' || argv[j][i + 1] > '9')))
                    return (printf("\033[31mError:\nOnly numbers allow...\n"));
    }
    ft_get_number(argc, argv, &push);
    i = -1;
    while (++i < push.nb_count)//check repeated numbers
    {
        j = i;
        while (++j < push.nb_count)
            if (push.stack_a[j] == push.stack_a[i])
                return (printf("\033[31mError:\nRepeated numbers...\n"));
    }
    px(&push, 1);
    //ft_sort_numbers(&push);
}