/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_operations.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adrgonza <adrgonza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/11 15:06:19 by adrgonza          #+#    #+#             */
/*   Updated: 2023/03/15 00:50:42 by adrgonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sx(int *stack)
{
	int	aux;

	if (stack[1])
	{
		aux = stack[0];
		stack[0] = stack[1];
		stack[1] = aux;
	}
}

void	rx(int *stack)
{
	int	aux;
	int	xua;
	int	i;

	i = 0;
	while (stack[i])
		i++;
	if (i > 1)
	{
		i--;
		aux = stack[i];
		stack[i] = stack[0];
		while (i > 0)
		{
			i--;
			xua = stack[i];
			stack[i] = aux;
			aux = xua;
		}
	}
}

void	px(int *stack1, int *stack2)
{
	int	i;
	int	aux;
	int	xua;

	i = -1;
	if (stack2[0])
	{
		aux = stack1[0];
		stack1[0] = stack2[0];
		rx(stack2);
		i = 0;
		while (stack2[i])
			i++;
		stack2[i - 1] = 0;
		i = 0;
		while (stack1[i])
		{
			xua = stack1[i + 1];
			stack1[i + 1] = aux;
			aux = xua;
			i++;
		}
	}
}

void	rrx(int *stack)
{
	int	aux;
	int	xua;
	int	i;

	i = 0;
	while (stack[i])
		i++;
	aux = stack[0];
	stack[0] = stack[--i];
	stack[i] = 0;
	i = -1;
	while (stack[++i])
	{
		xua = stack[i + 1];
		stack[i + 1] = aux;
		aux = xua;
	}
}

int	operation(t_push *push, int n)
{
	if (n == 1)
		return (sx(push->stack_a), write(1, "sa\n", 3));
	if (n == 2)
		return (sx(push->stack_b), write(1, "sb\n", 3));
	if (n == 3)
		return (sx(push->stack_a), sx(push->stack_b), write(1, "ss\n", 3));
	if (n == 4)
		return (px(push->stack_a, push->stack_b), write(1, "pa\n", 3));
	if (n == 5)
		return (px(push->stack_b, push->stack_a), write(1, "pb\n", 3));
	if (n == 6)
		return (rx(push->stack_a), write(1, "ra\n", 3));
	if (n == 7)
		return (rx(push->stack_b), write(1, "rb\n", 3));
	if (n == 8)
		return (rx(push->stack_a), rx(push->stack_b), write(1, "rr\n", 3));
	if (n == 9)
		return (rrx(push->stack_a), write(1, "rra\n", 4));
	if (n == 10)
		return (rrx(push->stack_b), write(1, "rrb\n", 4));
	if (n == 11)
		return (rrx(push->stack_a), rrx(push->stack_b), write(1, "rrr\n", 4));
	return (0);
}
