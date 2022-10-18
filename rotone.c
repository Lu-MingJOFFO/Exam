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
			if (str[i] == 'Z' || str[i] == 'z')
				str[i] = str[i] - 25;
			else if (('A' <= str[i] && str[i] <= 'Y') || ('a' <= str[i] && str[i] <= 'y'))
                        	str[i] = str[i] + 1;
			write(1, &str[i], 1);
			i++;
		}
	}
	write(1, "\n", 1);
	return (0);
}
