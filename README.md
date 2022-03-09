# ft_printf (July 2021 112/100)
This is my solution of ft_printf of 42 school.
<img src="readme_additions/result.png">

## Note
This was my second ever project of 42 school.<br>
The quality of the code may look very bad, but it was the best i was able to do back then.<br>
By now (6 months later) i would like to believe that the way i code has changed a bit.<br>
But i will still leave this project in its original state, since this is how i solved the project.<br>
Today i would definitley solve it differently.<br>

## Usage
This is not a complete programm, but rather a library, which when compiled can be used just as any other library.

1. run `make` or `make all` in the root of this directory
2. inlcude `libftprintf.h` into your file that you want to use `ft_printf` in
3. when compiling, include `libftprintf.a` into it like `gcc main.c libftprintf.a`
4. enjoy some of the behaviour of printf with only using the external functions stated in the subject.pdf
<img src="readme_additions/functions.png" width="400"/>


### Limits
This ft_printf does not copy the whole printf function, but only limited parts of it.<br>
This includes the following format specifiers:

- %c
- %s
- %p
- %d
- %i
- %u
- %x
- %X
- %%

And any combination of the following flags:

- `-`
- `0`
- `.`
- minimum field width
