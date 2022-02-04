
   
#include <unistd.h>

int main(int argc, char *argv[])
{
	int used[255] = {0};
	int i = 1, j = 0;
	if (argc == 3)
	{
		while (i < 3)
		{
			while (argv[i][j])
			{
				if(!used[(unsigned char)argv[i][j]])
				{
					used[(unsigned char)argv[i][j]] = 1;
					write(1, &argv[i][j], 1);
				}
				j++;
			}
			i++;
		}
	}
	write(1, "\n", 1);
}
