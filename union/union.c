#include <unistd.h>

int main(int ac, char **av)
{
	if (ac == 3)
	{
		int i, j, tab[255];
		i = 0;
		while (i < 255)
			tab[i++] = 0;
		i = 1;
		while (i < 3)
		{
			j = 0;
			while (av[i][j])
			{
				if (tab[(unsigned char)av[i][j]] == 0)
				{
					tab[(unsigned char)av[i][j]] = 1;
					write(1, &av[i][j], 1);
				}
				j++;
			}
			i++;
		}
	}
	write(1, "\n", 1);
	return 0;
}
