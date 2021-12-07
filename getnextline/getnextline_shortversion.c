#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

int	get_next_line(char **line)
{
	int	ret;
	int	i;

	ret = 0;
	i = 0;
	if (!(*line = malloc(1000000)))
		return (-1);
	while ((ret = read(0, &((*line)[i]), 1)) == 1)
	{
		if ((*line)[i] != '\n')
			i++;
		else
		{
			(*line)[i] = '\0';
			return (1);
		}
	}
	(*line)[i] = '\0';
	return (ret);
}
