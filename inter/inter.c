#include <unistd.h>

int iter(char *str, char c, int len)
{
    int i;
    
    i = 0;
    while (str[i] && (i < len || len == -1))
        if (str[i++] == c) 
            return (1);
    return (0); 
}
