# Get_Next_Line Tester Results

![Screen Shot 2022-02-04 at 2 44 07 pm](https://user-images.githubusercontent.com/58959408/152471030-9daceb00-6637-4946-b53d-7df1374f5f84.png)

# Link To Tester

https://github.com/Abaker-Hype/42-Cursus-Tester

# Get_Next_Line Exam Rank 02

Assignment name  : get_next_line <br />
Expected files   : get_next_line.c get_next_line.h <br />
Allowed functions: read, free, malloc

<br />
Write a function named get_next_line which prototype should be:

char	  *get_next_line(int fd);

<br />
Your function must return a line that has been read from the file descriptor
passed as parameter. What we call a "line that has been read" is a succesion of 0 to n characters
that end with '\n' (ascii code 0x0a) or with End Of File (EOF).
<br />
<br />
The line should be returned including the '\n' in case there is one at the end
of the line that has been read. When you've reached the EOF, you must store the current buffer in a char * and
return it. If the buffer is empty you must return NULL.
<br />
<br />
In case of error return NULL. In case of not returning NULL, the pointer should 
be free-able. Your program will be compiled with the flag -D BUFFER_SIZE=xx, which has to be
used as the buffer size for the read calls in your functions.
<br />
<br />
Your function must be memory leak free. When you've reached the EOF, your function should keep 0 memory allocated with
malloc, except the line that has been returned.
<br />
<br />
Caling your function get_next_line in a lop will therefore allow you to read
the text avaiable on a file descriptor one line at a time until the end of the 
text, no matter the size od either the text or one of its lines.
<br />
<br />
Make sure that your function behaves wel when it reads from a file, from the
standard output, from a redirection, etc... 
<br />
<br />
No call to another function will be done on the file descriptor between 2 calls
of get_next_line. Finally we consider that get_next_line has an undefined behaviour when reading
from a binary file.
