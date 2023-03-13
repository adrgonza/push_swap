/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adrgonza <adrgonza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/11 15:06:40 by adrgonza          #+#    #+#             */
/*   Updated: 2023/03/13 16:34:46 by adrgonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <stdint.h>
# include <unistd.h>
# include <stdio.h>
# include <limits.h>

typedef struct push{
	int		*stack_a;
	int		*stack_b;
	int		nb_count;
	int		min_number;
	int		aux;
	int		i;
	int		j;
	char	**splitted;
	char	*string;
}				t_push;

int		main(int argc, char **argv);
int		operation(t_push *push, int n);
int		ft_atoi(const char *str, t_push *push);
size_t	ft_strlen(const char *s);
char	*ft_strjoin_s(char *s1, char const *s2);
char	**ft_split(char const *s, char c);
void	ft_sort_nb(t_push *push);
void	*ft_calloc(size_t count, size_t size);
void	ft_exit(t_push *push, int ko);

#endif
