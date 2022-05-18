#include <stdarg.h>
#include <unistd.h>

int  g_var = 0;

void	write_number(unsigned long length, unsigned long base, char *string)
{
	if (length < base)
	{
		write(1, &string[length], 1);
		g_var += 1;
	}
	else
	{
		write_number(length / base, base, string);
		write_number(length % base, base, string);
	}
}

void	write_number_x(unsigned int length, unsigned int base, char *string)
{
	if (length < base)
	{
		write(1, &string[length], 1);
		g_var += 1;
	}
	else
	{
		write_number(length / base, base, string);
		write_number(length % base, base, string);
	}
}

int ft_printf(const char *format, ...)
{
	va_list		ap;
	long long	d;
	char		*string;
	int			length;
	int			x;

	g_var = 0;
	va_start(ap, format);
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			if (*format == 's')
			{
				length = 0;
				string = va_arg(ap, char *);
				if (!string)
					string = "(null)";
				while (string[length])
					length++;
				g_var += length;
				write(1, string, length);
			}
			else if (*format == 'd')
			{
				d = va_arg(ap, int);
				if (d < 0)
				{
					write(1, "-", 1);
					g_var++;
					d = -d;
				}
				write_number(d, 10, "0123456789");
			}
			else if (*format == 'x')
			{
				x = va_arg(ap, int);
				write_number_x(x, 16, "0123456789abcdef");
			}
			format++;
		}
		else
			g_var += write(1, format++, 1);
	}
	va_end(ap);
	return(g_var);
}

//less readable code

/*size_t string(char *str, int len)
{
    while (str && str[len] && ++len);
    return (str ? write(1, str, len) : write(1, "(null)", 6));
}

void    decimal(unsigned dig, unsigned len, char *sign, int *g_var)
{
    if (dig >= len)
        decimal(dig / len, len, sign, g_var);
    *g_var += (int)write (1, &sign[dig % len], 1);
}

void    hexadecimal(long dig, int len, char *sign, int *g_var)
{
    (dig < 0) ? (*g_var += (int)write(1, "-", 1), \
    decimal(-dig, len, sign,g_var)) : decimal(dig, len, sign, g_var);
}

int ft_printf(const char *fmt, ...)
{
    int     g_var = 0;
    va_list ap;
    va_start(ap, fmt);
    
	while (*fmt)
    {
        if (*fmt == '%' && *(fmt + 1) == 's' && (fmt += 2))
            g_var += (int)string(va_arg(ap, char *), 0);
        else if (*fmt == '%' && *(fmt + 1) == 'x' && (fmt += 2))
            decimal(va_arg(ap, int), 16, "0123456789abcdef", &g_var);
        else if (*fmt == '%' && *(fmt + 1) == 'd' && (fmt += 2))
            hexadecimal(va_arg(ap, int), 10, "0123456789", &g_var);
        else
            g_var += (int)write(1, fmt++, 1);
    }
    return (va_end(ap), g_var);
}
*/
