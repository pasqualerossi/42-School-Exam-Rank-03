#include "get_next_line.h"

char	*ft_strdup(char *src)
{
	char	*dest;
	int		i = 0;

	if (!src)
		return (NULL);

	while (src[i])
		i++;

	dest = malloc(sizeof(char) * (i + 1));
	if (!dest)
		return (NULL);

	i = 0;
	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}

	dest[i] = '\0';
	return (dest);
}

char	*get_next_line(int fd)
{
	static char	buffer[BUFFER_SIZE];
	char		line[999999];
	static int	bytes_read = 0;
	static int	buffer_pos = 0;
	int			i = 0;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);

	while (1)
	{
		if (buffer_pos >= bytes_read)
		{
			bytes_read = read(fd, buffer, BUFFER_SIZE);
			buffer_pos = 0;
			if (bytes_read <= 0)
				break ;
		}
		line[i++] = buffer[buffer_pos++];
		if (line[i - 1] == '\n')
			break ;
	}

	line[i] = '\0';
	if (i == 0)
		return (NULL);

	return (ft_strdup(line));
}

// TEST --> comment out before submitting

#include <stdio.h> // printf()
#include <fcntl.h> // open()

int	main(void)
{
	int fd = open("test.txt", O_RDONLY | O_CREAT, 0666); // add lines to text.txt after creation
	char *line = get_next_line(fd);
	int i = 1;

	while (line)
	{
		printf("line %d: %s", i, line);
		free(line);
		line = get_next_line(fd);
		i++;
	}
	get_next_line(fd);
	printf("\nline %d: %s", i, line);
}
