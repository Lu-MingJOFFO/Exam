#include <stdlib.h>
#include <stdio.h>

char *ft_itoa(int n)
{

	unsigned int	nb;
	int	i;
	char	*str;

	nb = n;
	if (n < 0)
		nb = -n;

	i = 1;
	while (nb > 9)
	{
		nb = nb / 10;
		i++;
	}
	if (n < 0)
		i++;

	str = malloc(sizeof(char)*(i + 1));
	if (!str)
		return (NULL);
	nb = n;
	if (n < 0)
                nb = -n;
	str[i] = '\0';
	i--;
	while (nb > 9)
	{
		str[i] = nb % 10 + 48;
		nb = nb /10;
		i--;
	}
	str[i] = nb + 48;
	if (n < 0)
		str[0] = '-';
	return (str);
}

int	main(void)
{
	char *str;
	str = ft_itoa(-1234);
	printf("%s\n", str);
}
