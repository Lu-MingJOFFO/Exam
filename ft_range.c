#include <stdlib.h>
#include <stdio.h>


int     *ft_range(int start, int end)
{
	int	*tab;
	int	size;
	int	sign;
	int	i;

	i = 0;
	if (end > start)
	{
		size = end - start + 1;
		sign = 1;
	}
	else
	{
		size = start - end + 1;
		sign = -1;
	}
	tab = malloc(sizeof(int) * size);
	if (!tab)
		return (NULL);
	while (i < size)
	{
	 	tab[i] = start;
		start = start + sign;
		i++;
	}
	return (tab);
}

int	main(void)
{

	int	*tab;
	int	max;
	int	min;
	min = 4;
	max = 8;

	tab = ft_range(min, max);
	int	i;
	i = 0;
	while (i <= max - min)
	{
		printf("%d , ", tab[i]);
		i++;
	}
	printf("\n");
}
