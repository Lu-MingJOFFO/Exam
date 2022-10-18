#include <unistd.h>

int     main(int ac, char **av)
{
        int     i;
        char    *s;

	i = 0;
        s = av[1];

        if (ac == 2)
        {
                while (s[i])
                {
                        while (s[i] == 32 || s[i] == 9)
				i++;
			while (s[i] && s[i] != 32 && s[i] != 9)
			{
				write(1, &s[i], 1);
				i++;
			}
			while (s[i] == 32 || s[i] == 9)
                                i++;
			if (s[i])
				write(1, "   ", 3);
                }
        }
        write(1, "\n", 1);
        return(0);
}
