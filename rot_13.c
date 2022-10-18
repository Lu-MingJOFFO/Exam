#include <unistd.h>

int	main(int argc, char **argv)
{
	int     i;
        char    *str;
        i = 0;
        str = argv[1];

	if (argc == 2)
	{
		while (str[i])
		{
			if (('A' <= str[i] && str[i] <= 'M') || ('a' <= str[i] && str[i] <= 'm'))
				str[i] = str[i] + 13;
			else if (('N' <= str[i] && str[i] <= 'Z') || ('n' <= str[i] && str[i] <= 'z'))
                        	str[i] = str[i] - 13;
			write(1, &str[i], 1);
			i++;
		}
	}
	write(1, "\n", 1);
	return (0);
}
