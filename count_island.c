#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>

int ft_strlen(char *str)
{
        int i;

        i = 0;
        while (str[i] != '\0')
                i++;
        return (i);
}

char	**ft_split(char *str)
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
		while (str[i] == '\n')
			i++;
		if (str[i])
		{
			tab[j] = malloc(sizeof(char) * 10000);
			if (!tab[j])
				return (NULL);
			k = 0;
			while (str[i] && !(str[i] == '\n'))
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

void ft_print(char **s)
{
	int i;
	int j;

	i = 0;
	while (s[i] != 0)
	{
		j = 0;
		while (s[i][j] != '\0')
		{
			write(1, &s[i][j], 1);
			j++;
		}
		write (1, "\n", 1);
		i++;
	}
}

void    dfs(char **s, int i, int j,int col, int row, int count)
{
        if (i<0 || i>=row || j<0 || j>=col || s[i][j] == '.' || (s[i][j] >= '0' && s[i][j] <= '9'))
                return;
        s[i][j] = count + '0';
        dfs(s, i+1, j, col, row, count);
        dfs(s, i-1, j, col, row, count);
        dfs(s, i, j+1, col, row, count);
        dfs(s, i, j-1, col, row, count);
}

int	 ft_countisland(char **s, int col, int row)
{
        int i;
        int j;
        int count;

        count = 0;
        i = 0;
        while (i < row)
        {
                j = 0;
                while (j < col)
                {
                        if (s[i][j] == 'X')
                        {
                                if (count < 10)
					 dfs (s, i, j, col, row, count);
                                else
					return (1);	
				count++;
                        }
                        j++;
                }
                i++;
        }
	return (0);
}

int main(int argc, char **argv)
{
	char	**s;
	char	buf[9000];	
	int	fd;
	int	nbread;
	int	row;
	int	col;	
	int	i;
	int	check;

	if (argc != 2)
	{
		write (1, "\n", 1);
		return (0); 
	}
	fd = open (argv[1], O_RDONLY);
	if (fd == -1)
	{
                write (1, "\n", 1);
                return (0);
       	}
	nbread = read (fd, buf, 9000);
	if (nbread == 0 || nbread == -1)
	{
                write (1, "\n", 1);
                return (0);
       	}
	buf[nbread] = '\0';

	i = 0;
	while (buf[i] != '\0')
	{	
		if (!(buf[i] == '.' || buf[i] == 'X' || buf[i] == '\n'))
		{
                	write (1, "\n", 1);
                	return (0);
		}
		i++;
        }
	
	s = ft_split(buf);
	close(fd);

	col = 0;
	while (s[0][col] != '\0')
		col++;

	row =0;
	while (s[row] != 0)
		row++;

	check = 1;
	i = 0;
	while (s[i] != 0)
	{
		if (ft_strlen(s[i]) > 1024)
			check = 0;
		if (ft_strlen(s[i]) != col)
			check = 0;
		i++;
	}
	if (check == 0)
	{
                write (1, "\n", 1);
                return (0);
	}

	if (ft_countisland(s, col, row) == 1)
	{
                write (1, "\n", 1);
                return (0);
 	}

	ft_print(s);
	i = 0;
	while (s[i] != 0)
	{	
		free(s[i]);
		i++;
	}
	free(s);
	
	return (0);
}

