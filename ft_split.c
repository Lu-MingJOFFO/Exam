#include <stdlib.h>

char    **ft_split(char *str)
{
	char	**tab;
	int	i;
	int	j;
	int	k;

	tab = malloc(sizeof(char *) * 10000);
	if (!tab)
		return (NULL);
	i = 0;
	j = 0;
	while (str[i])
	{
		while (str[i] == 32 || str[i] == '\t' || str[i] == '\n')
			i++;
		if (str[i])
		{
			tab[j] = malloc(sizeof(char) * 10000);
			if (!tab[j])
				return (NULL);
			k = 0;
			while (str[i] && !(str[i] == 32 || str[i] == '\t' || str[i] == '\n'))
			{
				tab[j][k] = str[i];
				k++;
				i++;
			}
			tab[j][k] = '\0';
			j++;
		}
	}
	tab[j] = NULL;
	return (tab);
}

#include <stdio.h>

int	main(void)
{
	char	**table;
	int	i;

	table = ft_split(" hello   Worl ! ");
	i = 0;
	while (table[i])
	{
		printf("%s\n", table[i]);
		i++;
	}
}
