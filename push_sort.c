/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adrgonza <adrgonza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/11 15:06:47 by adrgonza          #+#    #+#             */
/*   Updated: 2023/03/13 15:05:50 by adrgonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_sort(t_push *push)
{
	int	i;

	i = -1;
	while (++i < push->nb_count - 1)
		if ((push->stack_a[i] > push->stack_a[i + 1]) && push->stack_a[i + 1])
			return (1);
	return (0);
}

void	ft_sort_radix(t_push *push)
{
	int	i;
	int	j;

	i = 0;
	while (1)
	{
		j = -1;
		while (++j < push->nb_count)
		{
			if (push->stack_a[0] >> i & 1)
				operation(push, 6);
			else
				operation(push, 5);
		}
		while (push->stack_b[0])
			operation (push, 4);
		if (check_sort(push) == 0)
			return (ft_exit(push, 6));
		i++;
	}
}

void	ft_sort_three(t_push *p)
{
	int	i;

	i = 0;
	if (p->stack_a[0] == 2 && p->stack_a[1] == 1)
		operation(p, 1);
	if (p->stack_a[0] == 3 && p->stack_a[1] == 2)
	{
		operation(p, 1);
		operation(p, 9);
	}
	if (p->stack_a[0] == 3 && p->stack_a[1] == 1)
		operation(p, 6);
	if (p->stack_a[0] == 1 && p->stack_a[1] == 3)
	{
		operation(p, 1);
		operation(p, 6);
	}
	if (p->stack_a[0] == 2 && p->stack_a[1] == 3)
		operation(p, 9);
}

void	ft_sort_five(t_push *push)
{
	while (push->stack_a[0] < 4)
		operation (push, 6);
	operation(push, 5);
	if (push->nb_count == 5)
	{
		while (push->stack_a[0] < 4)
			operation (push, 6);
		operation(push, 5);
		if (push->stack_b[0] == 4)
			operation (push, 2);
	}
	ft_sort_three(push);
	while (push->stack_b[0])
		operation (push, 4);
	operation (push, 6);
	if (push->nb_count == 5)
		operation (push, 6);
}

void	ft_sort_nb(t_push *push)
{
	int	i;

	push->j = -1;
	while (++push->j < push->nb_count)
	{
		push->i = -1;
		while (++push->i < push->nb_count)
		{
			if (push->stack_a[push->j] == push->stack_b[push->i])
			{
				push->stack_a[push->j] = push->i + 1;
				break ;
			}
		}
	}
	i = -1;
	while (++i < push->nb_count)
		push->stack_b[i] = 0;
	if (push->nb_count < 4)
		ft_sort_three(push);
	if (push->nb_count == 4 || push->nb_count == 5)
		ft_sort_five(push);
	if (push->nb_count > 5)
		ft_sort_radix(push);
}
