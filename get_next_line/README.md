## 2 Files Required

:one: get_next_line.c 

:two: get_next_line.h

## Allowed Functions

```
read, free and malloc
```

## Prototype
```
char	  *get_next_line(int fd);
```

## The Program

> LINE

- Your function must return a line that has been read from the file descriptor passed as parameter. 

- What we call a "line that has been read" is a succesion of 0 to n characters that end with '\n' (ascii code 0x0a) or with End Of File (EOF).

- The line should be returned including the '\n' in case there is one at the end of the line that has been read. 

<br>

> BUFFER

- When you've reached the EOF, you must store the current buffer in a char * and return it. 

<br>

> NULL

- If the buffer is empty you must return NULL.

- In case of error return NULL. 

- In case of not returning NULL, the pointer should be free-able.

<br>

> MEMORY

- Your program will be compiled with the flag -D BUFFER_SIZE=xx, which has to be used as the buffer size for the read calls in your functions.

- Your function must be memory leak free.

- When you've reached the EOF, your function should keep 0 memory allocated with malloc, except the line that has been returned.

<br>

> FUNCTION

- Calling your function get_next_line in a loop will therefore allow you to read the text avaiable on a file descriptor one line at a time until the end of the text, no matter the size or either the text or one of its lines.

- Make sure that your function behaves well when it reads from a file, from the standard output, from a redirection, etc... 

- No call to another function will be done on the file descriptor between 2 calls of get_next_line.

<br>

> FILE

- Finally we consider that get_next_line has an undefined behaviour when reading from a binary file.
