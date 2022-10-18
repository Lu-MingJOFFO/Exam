#include <unistd.h>

int	main(int ac, char **av)
{
	int	i;
	i = 0;
	char	*s;
	s = av[1];

	if (ac == 2)
	{
		while (s[i])
			i++;
		i--;
		while (s[i] == 32 || s[i] == 9)
			i--;
		while (s[i] && s[i] != 32 && s[i] != 9)
			i--;
		i++;
		while (s[i] && s[i] != 32 && s[i] != 9)
		{
			write(1, &s[i], 1);
			i++;
		}
	}
	write(1, "\n", 1);
	return(0);
}
