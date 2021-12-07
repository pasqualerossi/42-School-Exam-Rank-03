int	main(void)
{
	int data = 1293;
	int min_int = -2147483648;
	printf("bytes printed %d\n", (ft_printf("%s\n", "Pasquale Rossi")));
	ft_printf("Bytes printed %d\n", (ft_printf("%s\n", "Pasquale Rossi")));
	ft_printf("here is a hex number %x\n", data);
	printf("bytes printed %d\n", (ft_printf("lowest int is %d\n", min_int)));				
}
