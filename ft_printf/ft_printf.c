#include <unistd.h>
#include <stdarg.h>

int	ft_putchar(char c)
{
	return (write(1, &c, 1));
}

int     ft_putnbr(unsigned int i, int base)
{
        char    *base_set = "0123456789abcdef";
        int     count = 0;
        int     n = i % base;

        if (i / base > 0)
                count += ft_putnbr(i / base, base);
        count += ft_putchar(base_set[n]);
        return (count);
}

int	ft_putstr(char *str)
{
	int	i = 0;

	if (!str)
		str = "(null)";
	while (str[i])
	{
		ft_putchar(str[i]);
		i++;
	}
	return (i);
}

int	ft_putint(int i)
{
	int	count = 0;

	if (i < 0)
	{
		count += ft_putchar('-');
		i *= -1;
	}
	count += ft_putnbr(i, 10);
	return (count);
}

int	ft_printf(char *string, ...)
{
	int		count = 0;
	va_list		args;
	int		i = 0;

	va_start(args, string);
	while (string[i])
	{
		if (string[i] == '%')
		{
			i++;
			if (string[i] == 's')
				count += ft_putstr(va_arg(args, char *));
			if (string[i] == 'd')
				count += ft_putint(va_arg(args, int));
			if (string[i] == 'x')
				count += ft_putnbr(va_arg(args, unsigned int), 16);
		}
		else
			count += ft_putchar(string[i]);
		i++;
	}
	va_end(args);
	return (count);
}
