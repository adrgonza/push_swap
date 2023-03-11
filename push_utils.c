#include "push_swap.h"

int check_sort(t_push *push)
{
	int i;
	i = -1;
	while (++i < push->nb_count - 1) //cheeck if is ordenated
        if ((push->stack_a[i] > push->stack_a[i + 1]) && push->stack_a[i + 1])
            return (1);
	return 0;
}

void ft_radix(t_push *push)
{
	int i;
	int j;

	i = 0;
	while (1)
	{
		j = -1;
		while(++j < push->nb_count)
		{
			if (((push->stack_a[0] >> i) & 1) == 1)
				operation(push, 6);
			else
				operation(push, 5);
		}
		while (push->stack_b[0])
			operation (push, 4);
		if (check_sort(push) == 0)
			return (ft_exit(push, 2));
		i++;
	}
}

int ft_sort_three(t_push *p)
{
	if (p->stack_a[0] == 2 && p->stack_a[1] == 1)
		operation(p, 1);
	if (p->stack_a[0] == 3 && p->stack_a[1] == 2 && p->stack_a[2] == 1)
	{
		operation(p, 1);
		operation(p, 9);
	}
	if (p->stack_a[0] == 3 && p->stack_a[1] == 1 && p->stack_a[2] == 2)
		operation(p, 6);
	if (p->stack_a[0] == 1 && p->stack_a[1] == 3 && p->stack_a[2] == 2)
	{
		operation(p, 1);
		operation(p, 6);
	}
	if (p->stack_a[0] == 2 && p->stack_a[1] == 3 && p->stack_a[2] == 1)
		operation(p, 9);
	return (1);
}

int ft_sort_nb(t_push *push)
{
	int i;
	i = -1;
	while (++i < push->nb_count)
		push->stack_b[i] = 0;
	if (push->nb_count < 4)
		ft_sort_three(push);
	else
		ft_radix(push);
	return 0;
}
