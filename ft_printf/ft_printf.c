#include <unistd.h>
#include <stdarg.h>
#include <stdio.h>

int	putcharacter(char c)
{
	write(1, &c, 1);
	return (1);
}

int	putstring(char *str)
{
	int	i = 0;

	if (!str)
		str = "(null)";
	while (str[i])
	{
		putcharacter(str[i]);
		i++;
	}
	return (i);
}

int	putnumber(unsigned int i, int base)
{
	char	*arr = "0123456789abcdef";
	int	count = 0;
	int	n = i % base;

	if (i / base != 0)
		count += putnumber(i / base, base);
	count += write(1, &arr[n], 1);
	return (count);
}

int	putint(int i)
{
	int	count = 0;

	if (i < 0)
	{
		i *= -1;
		count += putcharacter('-');
	}
	count += putnumber(i, 10);
	return (count);
}

int	ft_printf(char *string, ...)
{
	int	counter = 0;
	int	i = 0;

	va_list	args;
	va_start(args, string);
	while (string[i])
	{
		if (string[i] == '%')
		{
			i++;
			if (string[i] == 's')
				counter += putstring(va_arg(args, char *));
			if (string[i] == 'd')
				counter += putint(va_arg(args, int));
			if (string[i] == 'x')
				counter += putnumber(va_arg(args, unsigned int), 16);
		}
		else
			counter += putcharacter(string[i]);
		i++;
	}
	va_end(args);
	return (counter);
}
