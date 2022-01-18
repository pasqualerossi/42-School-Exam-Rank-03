#include <unistd.h>

int	main(int argc, char *argv[])
{
	int	i;
	int	j;

	i = -1; 
	j = -1;
	if (argc == 3)
	{
		while (argv[1][++i]) 
		{
			while (argv[2][++j])
			{
				if (argv[1][i] != 1 && (argv[1][i] == argv[2][j]))
				{
					write(1, &argv[1][i], 1);
					argv[1][i] = 1;
				}
			}
		}
	}
	write(1, "\n", 1);
}
