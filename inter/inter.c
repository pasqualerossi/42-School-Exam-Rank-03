#include <unistd.h>

int	main(int argc, char *argv[])
{
	int i = -1;
	int j = -1;

	if (argc == 3)
	{
		while (argv[1][++i] && (argv[2][++j])) 
		{
			if (argv[1][i] != 1 && (argv[1][i] == argv[2][j]))
			{
					write(1, &argv[1][i], 1);
					argv[1][i] = 1;
			}
		}
	}
	write(1, "\n", 1);
}
