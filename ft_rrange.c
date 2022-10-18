#include <stdlib.h>
#include <stdio.h>


int     *ft_rrange(int start, int end)
{
	int	*tab;
	int	size;
	int	sign;
	int	i;

	i = 0;
	if (end > start)
	{
		size = end - start + 1;
		sign = -1;
	}
	else
	{
		size = start - end + 1;
		sign = 1;
	}
	tab = malloc(sizeof(int) * size);
	if (!tab)
		return (NULL);
	while (i < size)
	{
	 	tab[i] = end;
		end = end + sign;
		i++;
	}
	return (tab);
}

int	main(void)
{

	int	*tab;
	int	max;
	int	min;
	min = 0;
	max = -3;

	tab = ft_rrange(min, max);
	int	i;
	i = 0;
	while (i <= min - max)
	{
		printf("%d , ", tab[i]);
		i++;
	}
	printf("\n");
}
