/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_split.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adrgonza <adrgonza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 10:41:18 by adrgonza          #+#    #+#             */
/*   Updated: 2023/03/12 19:06:39 by adrgonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_countwords(const char *s, char c)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (s[i] == c && s[i])
		i++;
	while (s[i])
	{
		while (s[i] != c && s[i])
			i++;
		while (s[i] == c && s[i])
			i++;
		j++;
	}
	return (j);
}

int	ft_count_letters(const char *s, char c)
{
	int	i;

	i = 0;
	while (s[i] != c && s[i])
		i++;
	return (i);
}

char	*ft_freeg(char **words)
{
	int	i;

	i = -1;
	while (words[++i])
		free(words[i]);
	free(words);
	return (NULL);
}

char	**ft_split(char const *s, char c)
{
	char	**words;
	int		count;
	int		a;
	int		b;

	if (!s)
		return (NULL);
	count = ft_countwords(s, c);
	words = ft_calloc(sizeof(char *), (count + 1));
	if (!words)
		return (NULL);
	b = 0;
	while (count--)
	{
		while (*s == c && *s)
			s++;
		a = 0;
		words[b] = malloc((sizeof(char)) * (ft_count_letters(s, c) + 1));
		if (!words[b])
			return ((char **)ft_freeg(words));
		while (*s != c && *s)
			words[b][a++] = *s++;
		words[b++][a] = 0;
	}
	return (words);
}
