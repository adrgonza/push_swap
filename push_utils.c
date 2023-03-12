#include "push_swap.h"

void	*ft_calloc(size_t count, size_t size)
{
	size_t	i;
	char	*p;
	void	*s;

	s = malloc(count * size);
	if (!s)
		return (NULL);
	p = s;
	i = 0;
	while (i < (size * count))
		p[i++] = 0;
	return (s);
}


size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

int	ft_atoi(const char *str)
{
	int	i;
	int	nb;
	int	sign;

	i = 0;
	nb = 0;
	sign = 1;
	while ((str[i] == ' ') || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-')
		sign = -1;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
		nb = (str[i++] - '0') + nb * 10;
	return (sign * nb);
}

char	*ft_strjoin_s(char *s1, char const *s2)
{
	int		i;
	int		j;
	char	*str;

	if (!s1)
		return (0);
	str = (char *)malloc(sizeof(*s1) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!str)
		return (NULL);
	i = -1;
	j = 0;
	while (s1[++i])
		str[i] = s1[i];
	while (s2[j])
		str[i++] = s2[j++];
	str[i] = '\0';
	free(s1);
	return (str);
}
