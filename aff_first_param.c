#include <unistd.h>

int	main(int ac, char **av)
{
	int	i;
	char	*s;

	i = 0;
	s = av[1];

	if (ac >= 2)
	{
		while (s[i])
		{
			write(1, &s[i], 1);
			i++;
		}
	}
	write(1, "\n", 1);
	return (0);
}
