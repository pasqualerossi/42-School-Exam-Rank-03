#include "get_next_line.h"

char	*get_next_line(int fd)
{
	char	*string = malloc(10000), *buffer = string;
	while (read(fd, buffer, 1) > 0 && *buffer++ != '\n');
	return (buffer > string) ? (*buffer = 0, string) : (free(string), NULL);
}
