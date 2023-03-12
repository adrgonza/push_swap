/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adrgonza <adrgonza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/11 15:06:27 by adrgonza          #+#    #+#             */
/*   Updated: 2023/03/12 21:01:56 by adrgonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void ft_exit(t_push *push, int ko)
{
    int i;

    if (ko > 2)
        {
            free(push->string);
            i = -1;
            while (push->splitted[++i])
                free(push->splitted[i]);
            free(push->splitted);
        }
    if (ko > 3)
        free(push->stack_a);
    if (ko == 4)
        write(1, "\033[31mError:\nRepeated numbers...\n", 33);
    if (ko > 5)
        free(push->stack_b);
    exit(0);
}

void ft_convert_nb(t_push *push) // remove negatives and 0
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

int ft_check_nb(t_push *push) //check repepeated and ordenated
{
    int i;
    int j;

    i = -1;
    while (++i < push->nb_count)//check repeated numbers
    {
        j = i;
        while (++j < push->nb_count)
            if (push->stack_a[j] == push->stack_a[i])
                ft_exit(push, 4);
    }
    push->stack_b = malloc(push->nb_count * sizeof(int) + 1);
    if (!push->stack_b)
        ft_exit(push, 5);
    i = -1;
    while (++i < push->nb_count) // get copy
        push->stack_b[i] = push->stack_a[i];
    i = -1;
    while (++i < push->nb_count - 1) //cheeck if is ordenated
        if ((push->stack_a[i] > push->stack_a[i + 1]) && push->stack_a[i + 1])
           return (ft_convert_nb(push), 1);
    return (ft_exit(push, 6), 0);
}

void ft_get_nb(int argc, char **argv, t_push *push)
{
    int i;

    i = 0;
    push->string = malloc(1 * sizeof(char));
    if (!push->string)
        ft_exit(push, 2);
    while(++i < argc) //put all arguments in a hole string
    {
        push->string = ft_strjoin_s(push->string, argv[i]);
        push->string = ft_strjoin_s(push->string, " ");
    }
    push->splitted = ft_split(push->string, ' '); //split string
    i = 0;
    while (push->splitted[i]) //get size of *int
        i++;
    push->nb_count = i;
    push->stack_a = malloc(i * sizeof(int) + 1); //allocate memory for it
    if (!push->stack_a)
        ft_exit(push, 3);
    push->stack_a[i] = 0;
    i = -1;
    while(push->splitted[++i]) //put every number in a int *
        push->stack_a[i] = ft_atoi(push->splitted[i]);
}
void leaks()
{
    system("leaks -q push_swap");
}

int main(int argc, char **argv)
{
    t_push  push;
    int i;
    int j;

    atexit(leaks);
    if (argc < 2) //check there is more than 1 argument
       return (write(1, "\033[31mError:\nInsert Numbers...\n", 31));
    j = 0;
    while (++j < argc) //check there is only numbers and spaces
    {
        i = -1;
        while (argv[j][++i])
            if ((argv[j][i] != ' '  && (argv[j][i] < '0' || argv[j][i] > '9'))
            && ((argv[j][i] != '-' && argv[j][i] != '+')
            || (argv[j][i + 1] < '0' || argv[j][i + 1] > '9')))
                return (write(1, "\033[31mError:\nOnly numbers allow...\n", 35));
    }
    ft_get_nb(argc, argv, &push); //put argument in a int *
    ft_check_nb(&push);  //check repeated and  ordenated
    ft_sort_nb(&push); //sort numbers
    ft_exit(&push, 6);  // exit program
}
