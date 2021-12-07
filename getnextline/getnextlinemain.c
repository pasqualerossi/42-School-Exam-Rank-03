int	main(int argc, char **argv)
{
	char	*line;

	while (get_next_line(&line))
		printf("%s", line);
	return (0);
}
