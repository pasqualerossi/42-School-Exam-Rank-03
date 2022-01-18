#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
# endif

#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>

char	*get_next_line(int fd);

#endif
