#include <unistd.h>

void	putnbr(int i)
{
	char c;
	if (i > 9)
		putnbr(i/10);
	c = i % 10 + 48;
	write(1, &c,1);
} 

int	main(void)
{
	int	i;
	i = 1;
	while (i <= 100)
	{
		if (i % 3 == 0)
			write(1, "fizz", 4);
		if (i % 5 == 0)
			write(1, "buzz", 4);
		if (i % 3 != 0 && i % 5 != 0)
			putnbr(i); 
		write(1, "\n", 1);
		i++;
	}
}
