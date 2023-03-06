#include "push_swap.h"

void sx(t_push *push, int s) // swap los 2 primeros elementos, falta check si hay uno menos elementos
{
    int aux;

    if (s == 1 || s == 3)
    {
        aux = push->stack_a[0];
        push->stack_a[0] = push->stack_a[1];
        push->stack_a[1] = aux;
        if (s == 1)
            write(1, "sa\n", 4);
    }
    if (s == 2 || s == 3)
    {
        aux = push->stack_b[0];
        push->stack_b[0] = push->stack_b[1];
        push->stack_b[1] = aux;
        if (s == 2)
            write(1, "sb\n", 4);
    }
    if(s == 3)
        write(1, "ss\n", 4);
}

void px(t_push *push, int p) // falta check si stack a o b existen
{
    int i;
    int aux;
    int xua;

    i = -1;
    if (p == 1)
    {
        aux = push->stack_a[0];
        //push->stack_a[0] = push->stack_b[0];
        while(++i < push->nb_count)
        {
            xua = push->stack_a[i + 1];
            push->stack_a[i + 1] = aux;
            aux = xua;
        }
        write(1, "pa\n", 4);
    }
    if (p == 2)
    {
        aux = push->stack_b[0];
        //push->stack_b[0] = push->stack_a[0];
        while(++i < push->nb_count)
        {
            xua = push->stack_b[i + 1];
            push->stack_b[i + 1] = aux;
            aux = xua;
        }
        write(1, "pb\n", 4);
    }
}

void rx(t_push *push, int r)
{
    int aux;
    
    if (r == 1 || r == 3)
    {

    }
    if (r == 2 || r == 3)
    {
        
    }
}

void rrx(t_push *push, int rr)
{
    if (rr == 1 || rr == 3)
    {

    }
    if (rr == 2 || rr == 3)
    {
        
    }
}