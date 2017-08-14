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

Here is a quick program to test static library created before :

Compile included tests files like this: ⇣
```
gcc -I include -o test printftest.c -L. -lftprintf
./test
```
## Code Overview
First, I define a struct to hold all the information for printf:

<img width="624" alt="screen shot 2017-08-13 at 7 25 39 pm" src="https://user-images.githubusercontent.com/14208431/29256185-3a73b7ce-805d-11e7-9bfb-1b2eb5a2b804.png">

Secondly, I define the sturcture of a dynamic string array:

<img width="498" alt="screen shot 2017-08-13 at 7 19 47 pm" src="https://user-images.githubusercontent.com/14208431/29256216-70a227a4-805d-11e7-9f4a-21b417feaa20.png">

All the different printf pass information to `vasprintf` which calls `dispatch`:

<img width="495" alt="screen shot 2017-08-13 at 7 32 11 pm" src="https://user-images.githubusercontent.com/14208431/29256290-2609499c-805e-11e7-93fe-264f4b89c4f8.png">

I use a jump table to handle different flags and length modifiers etc:

<img width="609" alt="screen shot 2017-08-13 at 7 30 06 pm" src="https://user-images.githubusercontent.com/14208431/29256265-e0dbaf5e-805d-11e7-95d8-1501058fe7f8.png">

The following function handles `%d`. Each field has a separate function: 

<img width="567" alt="screen shot 2017-08-13 at 7 36 06 pm" src="https://user-images.githubusercontent.com/14208431/29256369-c5c80928-805e-11e7-9e08-4b061a43b679.png">

All the functions above use the helper array append or insert functions:

<img width="495" alt="screen shot 2017-08-13 at 7 38 07 pm" src="https://user-images.githubusercontent.com/14208431/29256409-0c6c675c-805f-11e7-8bce-807b5f5ba68b.png">

Finally, when everything is done. I return a string which is properly null-teminanted:

<img width="365" alt="screen shot 2017-08-13 at 7 44 53 pm" src="https://user-images.githubusercontent.com/14208431/29256531-f5350408-805f-11e7-8668-92c69c0b19a7.png">

Run `make test && ./test` to make sure everything works correctly: 

<img width="548" alt="screen shot 2017-08-13 at 7 47 25 pm" src="https://user-images.githubusercontent.com/14208431/29256583-4e5f2d10-8060-11e7-8394-d8a1bb8daffe.png">

## Credits

This README was inpspired by [Antonin Gavrel](https://github.com/agavrel)

## Contact or contribute

If you want to contact me, or fix / improve this project, just send me a mail at **jibran.kalia@gmail.com**
