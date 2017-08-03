# Ft_printf (Printf's refactoring)

## Project Overview
Ft_printf is a 42 Project that aims to mimic the printf function.

A) parsing for flags, field_width, precision, length_modifier.
B) parsing for conversion specifier.
C) displaying UTF-8 characters. (%C and %S).
D) computing unsigned numbers in base 2 (%b), 8 (%o), 10 (%u) and 16 (%x).
E) displaying signed numbers (%d %D %i).
F) displaying pointer address (%p).

Bonus :
1) Handles multiple file descriptor (use ft_dprintf(int fd, char const format, ...) instead of ft_printf).
2) sprintf, snprintf, asprintf, vprintf, vsprintf, vdprintf, vasprintf implemented.
3) Wildcard Length_modifier (%*) : replaces precision and field_width with parameter in va_list ap.
5) print_len with %n.
7) colors with '%{' (%{red}).
8) %f and %F to handle double and float numbers.

## Sources
* https://linux.die.net/man/3/printf

## How to use it

### Download and compile the library

```
https://github.com/JibranKalia/printf.git
cd ~/printf
make
```

### Compile with your files

Here is a quick prog to test static library created before :

Compile included tests files like this: ⇣
```
gcc -I include -o test printftest.c -L. -lftprintf
./test
```

## Credits

This README was inpspired by [Antonin Gavrel](https://github.com/agavrel)

## Contact or contribute

If you want to contact me, or fix / improve this project, just send me a mail at **jibran.kalia@gmail.com**
