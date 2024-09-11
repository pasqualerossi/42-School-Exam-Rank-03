#include "get_next_line.h"

char	*get_next_line(int fd)
{
	int 	i = 0;
	int	byte;
	char	*str_buf;
	char	c;

	if (fd < 0 || BUFFER_SIZE < 1)
		return (NULL);

	str_buf = (char*)malloc(42000000);
	byte = read(fd, &c, 1);

	while (byte > 0)
	{
		str_buf[i] = c;
		i++;
		if (c == EOF || c == '\n')
			break ;
		byte = read(fd, &c, 1);
	}

	if (i == 0 || byte < 0)
	{
		free(str_buf);
		return (NULL);
	}
	str_buf[i] = '\0';
	return (str_buf);
}	

// TESTs [Remove or comment out this part when you're ready to submit]
/*
int	main(void)
{
	int	fd;
	char	*str;
	char	*path;
	int	i = -1;

	path = "subject.en.txt";
	fd = open(path, O_RDONLY);
	
	while (++i < 10)
	{
		str = get_next_line(fd);
		printf("%s\n", str);
	}
	return (0);
}
*/
