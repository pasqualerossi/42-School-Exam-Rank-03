#include <unistd.h>

int	main(int argc, char *argv[])
{
	int i = -1;

	if (argc == 3)
	{
		while (argv[1][++i] && (argv[2][i]))
		{
			if (argv[1][i] && (argv[2][i] != 1))
			{
				write(1, &argv[1][i], 1);
				write(1, &argv[2][i], 1);
				argv[1][i] = 1;
				argv[2][i] = 1;
			}
		}
	}
	write(1, "\n", 1);
}
