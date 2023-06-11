# Norminette

There's no norminette in this exam 💻

# 1 Exam Question

Either Get_Next_Line or Ft_Printf:

- [Get_Next_Line](https://github.com/pasqualerossi/42-School-Exam-Rank-03/tree/main/get_next_line)

- [Ft_Printf](https://github.com/pasqualerossi/42-School-Exam-Rank-03/tree/main/ft_printf) 

if you can make the code shorter, but readable, let me know!

# Exam Practice Tool

Practice the exam just like you would in the real exam with this tool - https://github.com/JCluzet/42_EXAM

# Code Commented

### get_next_line
```c
char *get_next_line(int fd)
{
    int i = 0;                      // Initialise a variable to keep track of the current position in the buffer
    int rd = 0;                     // Initialise a variable to store the result of the read operation
    char character;                 // Declare a variable to store each character read from the file
    char *buffer = malloc(100000);  // Allocate memory for the buffer with a size of 100000 characters

    if (BUFFER_SIZE <= 0)           // Check if the buffer size is less than or equal to 0
        return (NULL);              // If so, return NULL indicating an error

    while ((rd = read(fd, &character, BUFFER_SIZE - BUFFER_SIZE + 1)) > 0)
    {
        buffer[i++] = character;    // Store the current character in the buffer and increment the buffer index
        if (character == '\n')      // Check if the current character is a newline character
            break;                  // If so, exit the loop
    }

    buffer[i] = '\0';               // Add a null-terminating character at the end of the buffer to indicate the end of the string

    if (rd == -1 || i == 0 || (!buffer[i - 1] && !rd))
        return (free(buffer), NULL);  // Check for error conditions: read failure, empty buffer, or last character not present and no more characters to read. Free the buffer memory and return NULL.

    return (buffer);                // Return the buffer containing the read line
}
```
### ft_printf
```c
#include <unistd.h>
#include <stdarg.h>

void put_string(char *string, int *length)
{
    if (!string)
        string = "(null)"; // If the string is NULL, assign the value "(null)" to it
    while (*string)
        *length += write(1, string++, 1); // Write each character of the string to the standard output (file descriptor 1) and increment the length
}

void put_digit(long long int number, int base, int *length)
{
    char *hexadecimal = "0123456789abcdef"; // Define a string representing hexadecimal digits

    if (number < 0)
    {
        number *= -1; // If the number is negative, make it positive and print a '-' sign
        *length += write(1, "-", 1);
    }
    if (number >= base)
        put_digit((number / base), base, length); // Recursively divide the number by the base until it becomes less than the base
    *length += write(1, &hexadecimal[number % base], 1); // Write the remainder (digit) to the standard output and increment the length
}

int ft_printf(const char *format, ...)
{
    int length = 0; // Initialise the length counter

    va_list pointer; // Declare a variable of type va_list for handling variadic arguments
    va_start(pointer, format); // Initialise the va_list using the format parameter

    while (*format)
    {
        if ((*format == '%') && ((*(format + 1) == 's') || (*(format + 1) == 'd') || (*(format + 1) == 'x')))
        {
            format++; // Move to the next character after '%'
            if (*format == 's')
                put_string(va_arg(pointer, char *), &length); // Retrieve a string argument using va_arg and call put_string
            else if (*format == 'd')
                put_digit((long long int)va_arg(pointer, int), 10, &length); // Retrieve an integer argument using va_arg and call put_digit with base 10
            else if (*format == 'x')
                put_digit((long long int)va_arg(pointer, unsigned int), 16, &length); // Retrieve an unsigned integer argument using va_arg and call put_digit with base 16
        }
        else
            length += write(1, format, 1); // Write a single character from the format string to the standard output and increment the length
        format++; // Move to the next character in the format string
    }
    return (va_end(pointer), length); // Clean up the va_list and return the final length
}

```
