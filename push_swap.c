/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adrgonza <adrgonza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/11 15:06:27 by adrgonza          #+#    #+#             */
/*   Updated: 2023/03/17 17:32:37 by adrgonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_exit(t_push *push, int ko)
{
	int	i;

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
		write(1, "Error\n", 7);
	if (ko > 5)
		free(push->stack_b);
	exit(0);
}

void	ft_convert_nb(t_push *push)
{
	while (++push->i < push->nb_count)
	{
		push->j = -1;
		while (++push->j < push->nb_count - 1)
		{
			if (push->stack_b[push->j] > push->stack_b[push->j + 1])
			{
				push->aux = push->stack_b[push->j];
				push->stack_b[push->j] = push->stack_b[push->j + 1];
				push->stack_b[push->j + 1] = push->aux;
			}
		}
	}
}

int	ft_check_nb(t_push *push)
{
	int	i;
	int	j;

	i = -1;
	while (++i < push->nb_count)
	{
		j = i;
		while (++j < push->nb_count)
			if (push->stack_a[j] == push->stack_a[i])
				ft_exit(push, 4);
	}
	push->stack_b = ft_calloc(sizeof(int), (push->nb_count + 1));
	if (!push->stack_b)
		ft_exit(push, 5);
	i = -1;
	while (++i < push->nb_count)
		push->stack_b[i] = push->stack_a[i];
	i = -1;
	push->i = -1;
	while (++i < push->nb_count - 1)
		if ((push->stack_a[i] > push->stack_a[i + 1]))
			return (ft_convert_nb(push), 1);
	return (ft_exit(push, 6), 0);
}

void	ft_get_nb(int argc, char **argv, t_push *push)
{
	int	i;

	i = 0;
	push->string = ft_calloc(sizeof(char), 1);
	if (!push->string)
		ft_exit(push, 2);
	while (++i < argc)
	{
		push->string = ft_strjoin_s(push->string, argv[i]);
		push->string = ft_strjoin_s(push->string, " ");
	}
	push->splitted = ft_split(push->string, ' ');
	i = 0;
	while (push->splitted[i])
		i++;
	push->nb_count = i;
	push->stack_a = ft_calloc(sizeof(int), (push->nb_count + 1));
	if (!push->stack_a)
		ft_exit(push, 3);
	i = -1;
	while (push->splitted[++i])
		push->stack_a[i] = ft_atoi(push->splitted[i], push);
}

int	main(int argc, char **argv)
{
	t_push	push;
	int		i;
	int		j;

	if (argc < 2)
		return (0);
	j = 0;
	while (++j < argc)
	{
		i = -1;
		while (argv[j][++i])
			if ((argv[j][i] != ' ' && (argv[j][i] < '0' || argv[j][i] > '9'))
					&& ((argv[j][i] != '-' && argv[j][i] != '+')
						|| (argv[j][i + 1] < '0' || argv[j][i + 1] > '9')))
				return (write(1, "Error\n", 7));
	}
	ft_get_nb(argc, argv, &push);
	ft_check_nb(&push);
	ft_sort_nb(&push);
	ft_exit(&push, 6);
}
