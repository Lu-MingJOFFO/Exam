#include <unistd.h>

int	find(char c, char *str)
{
	int	i;
	i = 0;
	while (str[i])
	{
		if (c == str[i])
			return (1);
		i++;
	}
	return (0);
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
			if ((find(s1[i], s2) == 1) && (doubles(s1[i], i, s1) == 1))
				write(1, &s1[i], 1);
			i++;
		}
	}
	write(1, "\n", 1);
	return(0);
}

