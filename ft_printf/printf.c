#include <unistd.h>
#include <stdarg.h>
#include <stdio.h>

int    write_string(char *str)
{
    int i = 0;
    if (!str)
        str = "(null)";
    while (str[i])
    {
        write(1, &str[i], 1);
        i++;
    }
    return (i);
}

int    write_hexadecimal(unsigned int i, int base)
{
    char *arr = "0123456789abcdef";
    int count = 0;
    int n = i % base;

    if (i/base != 0)
        count += write_hexadecimal(i/base, base);
    write(1, &arr[n], 1);
    count++;
    return (count);
}

int    write_decimal(int i)
{
    int count = 0; 
    
    if (i == -2147483648)
    {
        write(1, "-2147483648", 11);
        return (11);
    }
    if (i < 0)
    {
        write(1, "-", 1);
        i *= -1;
        count++;
    }
    count += write_hexadecimal(i, 10);
    return (count);
}

int	ft_printf(char *string, ...)
{
	int		count = 0;
	va_list	args;
	int		i = 0;

	va_start(args, string);
	while (string[i])
	{
		if (string[i] == '%')
		{
			i++;
			if (string[i] == 's')
				count += write_string(va_arg(args, char *));
			if (string[i] == 'd')
				count += write_decimal(va_arg(args, int));
			if (string[i] == 'x')
				count += write_hexadecimal(va_arg(args, unsigned int), 16);
		}
		else
        {
            write(1, &string[i], 1);
            count++;
        }
		i++;
	}
	va_end(args);
	return (count);
}