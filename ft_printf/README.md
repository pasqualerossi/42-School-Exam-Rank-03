## 1 Excepted File

:one: ft_printf.c

## Allowed Functions
```
malloc, free, write, va_start, va_arg, va_copy and va_end
```

## Prototype
```
int ft_printf(const char *, ... )
```

## The Program

Write a function named `ft_printf` that will mimic the real printf but it will manage only the following conversions:
```
s (string)
d (decimal) 
x (lowercase hexademical)
```

## Output Examples
```
call: ft_printf("%s\n", "toto")

out: toto$
```

```
call: ft_printf("Magic %s is %d", "number", 42)

out: Magic number is 42%
```

```
call: ft_printf("Hexadecimal for %d is %x\n", 42, 42)

out: Hexadecimal for 42 is 2a$
```
