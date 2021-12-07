#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>

char	*ft_aux(char *s, int c)
{
	char	*str;
	int		i;

	i = 0;
	while (s[i])
		i++;
	if (!(str = (char *)malloc(1 + i)))
		return (0);
	i = 0;
	while (s[i])
	{
		str[i] = s[i];
		i++;
	}
	str[i] = c;
	str[i + 1] = '\0';
	free(s);
	return (str);
}

int	get_next_line(char **line)
{
	char	buffer;
	int		flag;

	if (!line || !(*line = malloc(1)))
		return (-1);
	*line [0] = '\0';
	while ((flag = read(0, &buffer, 1) > 0))
	{
		if (buffer == '\n')
			break ;
		*line = ft_aux (*line, buffer);
	}
	return (flag);
}
