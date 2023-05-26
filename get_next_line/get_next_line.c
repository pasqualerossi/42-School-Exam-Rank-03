#include "get_next_line.h"

char *get_next_line(int fd)
{
    int     i = 0;
    int     rd = 0;
    char    character;
    char    *buffer = malloc(100000);
    
    if (BUFFER_SIZE <= 0)
        return (NULL);
    while ((rd = read(fd, &character, BUFFER_SIZE - BUFFER_SIZE + 1)) > 0)
    {
        buffer[i++] = character;
        if (character == '\n')
            break ;
    }
    buffer[i] =  '\0';
    if (rd == -1 || i == 0 || (!buffer[i - 1] && !rd))
        return (free(buffer), NULL);
    return(buffer);
}
