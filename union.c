#include <unistd.h>

int	find(char c, char *str)
{
	int	i;
	i = 0;
	while (str[i])
	{
		if (c == str[i])
			return (0);
		i++;
	}
	return (1);
}

int	doubles(char c, int i, char *str)
{
	int	j;
	j = 0;
	while (j < i)
	{
		if (c == str[j])
			return (0);
		j++;
	}
	return (1);
}

int	main(int ac, char **av)
{
	int	i;
	char	*s1;
	char	*s2;
	i = 0;
	s1 = av[1];
	s2 = av[2];

	if (ac == 3)
	{
		while (s1[i])
		{
			if (doubles(s1[i], i, s1) == 1)
				write(1, &s1[i], 1);
			i++;
		}
		i = 0;
		while (s2[i])
		{
			if (doubles(s2[i], i, s2) == 1 && find(s2[i], s1) == 1)
				write(1, &s2[i], 1);
			i++;
		}
	}
	write(1, "\n", 1);
	return(0);
}

