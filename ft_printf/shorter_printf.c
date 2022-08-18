#include <stdarg.h>
#include <unistd.h>

void    ft_putnbr(unsigned digits, unsigned length, char *sign, int *g_var)
{
    if (digits >= length)
    {
		  ft_putnbr(digits / length, length, sign, g_var);
	  }
	  *g_var += (int)write (1, &sign[digits % length], 1);
}

void    ft_dig(long digits, int length, char *sign, int *g_var)
{
    (digits < 0) ? (*g_var += (int)write(1, "-", 1), \
	  ft_putnbr(-digits, length, sign,g_var)) : ft_putnbr(digits, length, sign, g_var);
}

size_t ft_putstr(char *string, int length)
{
    while (string && string[length] && ++length);
    return (string ? write(1, string, length) : write(1, "(null)", 6));
}

int ft_printf(const char *format, ...)
{
    int     g_var = 0;
    va_list ap;
    va_start(ap, format);

    while (*format)
    {
        if (*format == '%' && *(format + 1) == 's' && (format += 2))
		    {
            g_var += (int)ft_putstr(va_arg(ap, char *), 0);
		    }
		    else if (*format == '%' && *(format + 1) == 'x' && (format += 2))
        {
			    ft_putnbr(va_arg(ap, int), 16, "0123456789abcdef", &g_var);
		    }
		    else if (*format == '%' && *(format + 1) == 'd' && (format += 2))
        {    
			    ft_dig(va_arg(ap, int), 10, "0123456789", &g_var);
		    }
		    else
            g_var += (int)write(1, format++, 1);
    }
    return (va_end(ap), g_var);
}
