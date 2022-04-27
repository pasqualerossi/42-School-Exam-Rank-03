#include <stdarg.h>
#include <unistd.h>

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

size_t character(char *str, int len)
{
    while (str && str[len] && ++len);
    return (str ? write(1, str, len) : write(1, "(null)", 6));
}

int ft_printf(const char *fmt, ...)
{
    int     g_var = 0;
    va_list ap;
    va_start(ap, fmt);
    
	while (*fmt)
    {
        if (*fmt == '%' && *(fmt + 1) == 's' && (fmt += 2))
            g_var += (int)character(va_arg(ap, char *), 0);
        else if (*fmt == '%' && *(fmt + 1) == 'x' && (fmt += 2))
            decimal(va_arg(ap, int), 16, "0123456789abcdef", &g_var);
        else if (*fmt == '%' && *(fmt + 1) == 'd' && (fmt += 2))
            hexadecimal(va_arg(ap, int), 10, "0123456789", &g_var);
        else
            g_var += (int)write(1, fmt++, 1);
    }
    return (va_end(ap), g_var);
}
