#include "push_swap.h"

void sx(t_push *push, int s) // saber si cuando s = 3 pero no hay stack_x y si no mover write
{
    int aux;

    if ((s == 1 || s == 3) && push->stack_a[1])
    {
        aux = push->stack_a[0];
        push->stack_a[0] = push->stack_a[1];
        push->stack_a[1] = aux;
        if (s == 1)
            write(1, "sa\n", 4);
    }
    if ((s == 2 || s == 3) && push->stack_a[1])
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

void px(t_push *push, int p)
{
    int i;
    int aux;
    int xua;

    i = -1;
    if (p == 1 && push->stack_b[0])
    {
        aux = push->stack_a[0];
        push->stack_a[0] = push->stack_b[0];
        while(push->stack_a[++i])
        {
            xua = push->stack_a[i + 1];
            push->stack_a[i + 1] = aux;
            aux = xua;
        }
        write(1, "pa\n", 4);
    }
    if (p == 2 && push->stack_a[0])
    {
        aux = push->stack_b[0];
        push->stack_b[0] = push->stack_a[0];
        while(push->stack_b[++i])
        {
            xua = push->stack_b[i + 1];
            push->stack_b[i + 1] = aux;
            aux = xua;
        }
        write(1, "pb\n", 4);
    }
}

void rx(t_push *push, int r) //check de cuando r == 3
{
    int aux;
    int xua;
    int i;
    
    i = 0;
    if (r == 1 || r == 3)
    {
        while (push->stack_a[i])
            i++;
        aux = push->stack_a[--i];
        push->stack_a[i] = push->stack_a[0];
        while(push->stack_a[--i])
        {
            xua = push->stack_a[i];
            push->stack_a[i] = aux;
            aux = xua;
        }
    }
    i = 0;
    if (r == 2 || r == 3)
    {
        while (push->stack_b[i])
            i++;
        aux = push->stack_b[--i];
        push->stack_b[i] = push->stack_b[0];
        while(push->stack_b[--i])
        {
            xua = push->stack_b[i];
            push->stack_b[i] = aux;
            aux = xua;
        }
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